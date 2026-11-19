#pragma once

#include <QObject>

#include <vector>

#include "game_map.hpp"

class QGraphicsScene;
class QGraphicsView;
class QPixmap;

namespace biv {
	class QtUIObj;

	class QtGameMap : public QObject, public GameMap {
		public:
			static constexpr int VIEW_WIDTH_CELLS = 80;

			QtGameMap(
				const int height,
				const int width,
				const QPixmap& sky_texture,
				const QPixmap& water_texture
			);
			~QtGameMap() override;

			void add_obj(QtUIObj* obj);
			void clear() noexcept override;
			QGraphicsView* get_viewer() const noexcept;
			void refresh() noexcept override;
			void remove_obj(QtUIObj* obj);
			void remove_objs() override;
			void show() const noexcept override;

		private:
			QGraphicsScene* scene = nullptr;
			QGraphicsView* view = nullptr;
			std::vector<QtUIObj*> objs;
	};
}
