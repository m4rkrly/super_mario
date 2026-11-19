#pragma once

#include <QPixmap>

#include "money.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace biv {
	class QtMoney : public Money, public QtUIObjRectAdapter {
		public:
			QtMoney(
				const Coord& top_left,
				const int width,
				const int height,
				const QPixmap& texture
			);
	};
}
