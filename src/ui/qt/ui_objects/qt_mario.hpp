#pragma once

#include <QPixmap>

#include "mario.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace biv {
	class QtMario : public Mario, public QtUIObjRectAdapter {
		public:
			QtMario(
				const Coord& top_left,
				const int width,
				const int height,
				const QPixmap& texture
			);
	};
}
