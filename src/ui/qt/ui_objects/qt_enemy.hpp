#pragma once

#include <QPixmap>

#include "enemy.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace biv {
	class QtEnemy : public Enemy, public QtUIObjRectAdapter {
		public:
			QtEnemy(
				const Coord& top_left,
				const int width,
				const int height,
				const QPixmap& texture
			);
	};
}
