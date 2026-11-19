#include "qt_ship.hpp"

using biv::QtShip;

QtShip::QtShip(
	const Coord& top_left,
	const int width,
	const int height,
	const QPixmap& texture
) : Ship(top_left, width, height),
	QtUIObjRectAdapter(top_left, width, height, texture) {}
