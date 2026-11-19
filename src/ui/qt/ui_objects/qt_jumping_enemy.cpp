#include "qt_jumping_enemy.hpp"

using biv::QtJumpingEnemy;

QtJumpingEnemy::QtJumpingEnemy(
	const Coord& top_left,
	const int width,
	const int height,
	const QPixmap& texture
) : JumpingEnemy(top_left, width, height),
	QtUIObjRectAdapter(top_left, width, height, texture) {}
