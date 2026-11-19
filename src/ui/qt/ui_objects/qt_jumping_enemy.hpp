#pragma once

#include <QPixmap>

#include "jumping_enemy.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace biv {
	class QtJumpingEnemy : public JumpingEnemy, public QtUIObjRectAdapter {
		public:
			QtJumpingEnemy(
				const Coord& top_left,
				const int width,
				const int height,
				const QPixmap& texture
			);
	};
}
