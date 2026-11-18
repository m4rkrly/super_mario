#include "qt_ui_obj_rect_adapter.hpp"

#include <QPainter>
#include <QPointF>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

using biv::QtUIObjRectAdapter;

QtUIObjRectAdapter::QtUIObjRectAdapter(
	const Coord& top_left,
	const int width,
	const int height,
	const QPixmap& texture
) {
	this->top_left = top_left;
	this->width = width;
	this->height = height;
	this->texture = texture;
}

QRectF QtUIObjRectAdapter::boundingRect() const {
	return QRectF(0, 0, width * TILE_SIZE, height * TILE_SIZE);
}

void QtUIObjRectAdapter::paint(
	QPainter* painter,
	const QStyleOptionGraphicsItem*,
	QWidget*
) {
	if (texture.isNull()) {
		return;
	}

	const int object_width = width * TILE_SIZE;
	const int object_height = height * TILE_SIZE;

	painter->save();
	painter->setClipRect(QRectF(0, 0, object_width, object_height));

	for (int y = 0; y < object_height; y += TILE_SIZE) {
		for (int x = 0; x < object_width; x += TILE_SIZE) {
			painter->drawPixmap(QPoint(x, y), texture);
		}
	}

	painter->restore();
}

void QtUIObjRectAdapter::sync_position() noexcept {
	setPos(QPointF(
		get_x() * TILE_SIZE,
		get_y() * TILE_SIZE
	));
}

const QPixmap& QtUIObjRectAdapter::get_texture() const noexcept {
	return texture;
}
