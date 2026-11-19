#include "qt_enemy.hpp"

using biv::QtEnemy;

QtEnemy::QtEnemy(
	const Coord& top_left,
	const int width,
	const int height,
	const QPixmap& texture
) : Enemy(top_left, width, height),
	QtUIObjRectAdapter(top_left, width, height, texture) {}
