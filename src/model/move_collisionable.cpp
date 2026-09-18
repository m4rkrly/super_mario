#include "move_collisionable.hpp"

using biv::MoveCollsionable;

MoveCollsionable::MoveCollsionable(
  const Coord& top_left,
  const int width, const int height,
  const float vspeed, const float hspeed
) : Movable(top_left, width, height, vspeed, hspeed) {}

void MoveCollsionable::decide_to_move(Rect* obj) {}
