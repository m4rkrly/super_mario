#pragma once

#include <QPixmap>

#include "full_box.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace biv {
	class QtFullBox : public FullBox, public QtUIObjRectAdapter {
		private:
			QPixmap used_texture;

		public:
			QtFullBox(
				const Coord& top_left,
				const int width,
				const int height,
				UIFactory* ui_factory,
				const QPixmap& active_texture,
				const QPixmap& used_texture
			);

			const QPixmap& get_texture() const noexcept override;
	};
}
