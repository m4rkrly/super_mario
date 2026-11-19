#include "qt_flying_enemy.hpp"

using biv::QtFlyingEnemy;

QtFlyingEnemy::QtFlyingEnemy(
	const Coord& top_left,
	const int width,
	const int height,
	const unsigned int offset,
	const QPixmap& texture
) : FlyingEnemy(top_left, width, height, offset),
	QtUIObjRectAdapter(top_left, width, height, texture) {}
