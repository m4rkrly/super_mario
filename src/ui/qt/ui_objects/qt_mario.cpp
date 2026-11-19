#include "qt_mario.hpp"

using biv::QtMario;

QtMario::QtMario(
	const Coord& top_left,
	const int width,
	const int height,
	const QPixmap& texture
) : Mario(top_left, width, height),
	QtUIObjRectAdapter(top_left, width, height, texture) {}
