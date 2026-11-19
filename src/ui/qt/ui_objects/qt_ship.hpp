#pragma once

#include <QPixmap>

#include "qt_ui_obj_rect_adapter.hpp"
#include "ship.hpp"

namespace biv {
	class QtShip : public Ship, public QtUIObjRectAdapter {
		public:
			QtShip(
				const Coord& top_left,
				const int width,
				const int height,
				const QPixmap& texture
			);
	};
}
