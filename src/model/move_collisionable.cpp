#include "move_collisionable.hpp"

using biv::MoveCollisionable;

MoveCollisionable::MoveCollisionable() : Movable() {}

MoveCollisionable::MoveCollisionable(
  const Coord& top_left,
  const int width, const int height,
  const float vspeed, const float hspeed
) : Movable(top_left, width, height, vspeed, hspeed) {}

