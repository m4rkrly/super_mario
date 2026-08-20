#include "console_flying_enemy.hpp"

using biv::ConsoleFlyingEnemy;

ConsoleFlyingEnemy::ConsoleFlyingEnemy(
  const Coord& top_left, const int width, const int height,
  const Coord& start, const int offset
) : FlyingEnemy(top_left, width, height, start, offset) {}

char ConsoleFlyingEnemy::get_brush() const noexcept {
  return 'f';
} 
