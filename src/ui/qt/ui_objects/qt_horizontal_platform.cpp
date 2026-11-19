#include "qt_horizontal_platform.hpp"

using biv::QtHorizontalPlatform;

QtHorizontalPlatform::QtHorizontalPlatform(
	const Coord& top_left,
	const int width,
	const int height,
	const unsigned int offset,
	const QPixmap& texture
) : HorizontalPlatform(top_left, width, height, offset),
	QtUIObjRectAdapter(top_left, width, height, texture) {}
