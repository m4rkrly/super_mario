#include "qt_full_box.hpp"

using biv::QtFullBox;

QtFullBox::QtFullBox(
	const Coord& top_left,
	const int width,
	const int height,
	UIFactory* ui_factory,
	const QPixmap& active_texture,
	const QPixmap& used_texture
) : FullBox(top_left, width, height, ui_factory),
	QtUIObjRectAdapter(top_left, width, height, active_texture),
	used_texture(used_texture) {}

const QPixmap& QtFullBox::get_texture() const noexcept {
	if (is_active_) {
		return QtUIObjRectAdapter::get_texture();
	}
	return used_texture;
}
