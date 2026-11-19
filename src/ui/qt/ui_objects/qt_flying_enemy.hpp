#pragma once

#include <QPixmap>

#include "flying_enemy.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace biv {
	class QtFlyingEnemy : public FlyingEnemy, public QtUIObjRectAdapter {
		public:
			QtFlyingEnemy(
				const Coord& top_left,
				const int width,
				const int height,
				const unsigned int offset,
				const QPixmap& texture
			);
	};
}
