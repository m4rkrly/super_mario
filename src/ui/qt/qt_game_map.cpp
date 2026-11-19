#include "qt_game_map.hpp"

#include <QFrame>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QPixmap>

#include <algorithm>

#include "qt_ui_obj.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

using biv::QtGameMap;

namespace {
class QtGraphicsScene : public QGraphicsScene {
public:
  QtGraphicsScene(const int height, const int width, const QPixmap &sky_texture,
                  const QPixmap &water_texture)
      : height(height), width(width), sky_texture(sky_texture),
        water_texture(water_texture) {}

protected:
  void drawBackground(QPainter *painter, const QRectF &rect) override {
    painter->drawTiledPixmap(rect, sky_texture);

    const qreal water_top = (height - 3) * biv::QtUIObjRectAdapter::TILE_SIZE;
    const qreal water_bottom = height * biv::QtUIObjRectAdapter::TILE_SIZE;
    const QRectF water_area(0, water_top,
                            width * biv::QtUIObjRectAdapter::TILE_SIZE,
                            water_bottom - water_top);
    const QRectF visible_water = water_area.intersected(rect);

    if (!visible_water.isEmpty()) {
      painter->drawTiledPixmap(visible_water, water_texture);
    }
  }

private:
  int height;
  int width;
  QPixmap sky_texture;
  QPixmap water_texture;
};
} // namespace

QtGameMap::QtGameMap(const int height, const int width,
                     const QPixmap &sky_texture, const QPixmap &water_texture)
    : QObject(nullptr), GameMap(height, width) {
  scene = new QtGraphicsScene(height, width, sky_texture, water_texture);
  view = new QGraphicsView(scene);

  const int view_width = VIEW_WIDTH_CELLS * QtUIObjRectAdapter::TILE_SIZE;
  const int view_height = height * QtUIObjRectAdapter::TILE_SIZE;

  view->setSceneRect(0, 0, view_width, view_height);
  view->setFixedSize(view_width, view_height);
  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
  view->setFrameShape(QFrame::NoFrame);
  view->setFocusPolicy(Qt::NoFocus);
  view->setInteractive(false);
  view->setRenderHint(QPainter::Antialiasing, false);
  view->setRenderHint(QPainter::SmoothPixmapTransform, false);
}

QtGameMap::~QtGameMap() {
  remove_objs();
  delete scene;
  scene = nullptr;
}

void QtGameMap::add_obj(QtUIObj *obj) {
  objs.push_back(obj);
  scene->addItem(obj);
  obj->sync_position();
}

void QtGameMap::clear() noexcept {
  for (QtUIObj *obj : objs) {
    scene->removeItem(obj);
  }
  objs.clear();
}

QGraphicsView *QtGameMap::get_viewer() const noexcept { return view; }

void QtGameMap::refresh() noexcept {
  for (QtUIObj *obj : objs) {
    obj->sync_position();
  }
  scene->update();
}

void QtGameMap::remove_obj(QtUIObj *obj) {
  auto it = std::find(objs.begin(), objs.end(), obj);
  if (it == objs.end()) {
    return;
  }

  scene->removeItem(obj);
  objs.erase(it);
}

void QtGameMap::remove_objs() { clear(); }

void QtGameMap::show() const noexcept {}
