#pragma once

#include <QPixmap>

#include "horizontal_platform.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace biv {
	class QtHorizontalPlatform : public HorizontalPlatform, public QtUIObjRectAdapter {
		public:
			QtHorizontalPlatform(
				const Coord& top_left,
				const int width,
				const int height,
				const unsigned int offset,
				const QPixmap& texture
			);
	};
}
