#include "qt_box.hpp"

using biv::QtBox;

QtBox::QtBox(
	const Coord& top_left,
	const int width,
	const int height,
	const QPixmap& texture
) : Box(top_left, width, height),
	QtUIObjRectAdapter(top_left, width, height, texture) {}
