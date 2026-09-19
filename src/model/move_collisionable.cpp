#include "move_collisionable.hpp"

using biv::MoveCollisionable;

MoveCollisionable::MoveCollisionable() : Movable() {
  this->is_mario = false;
}

MoveCollisionable::MoveCollisionable(
  const Coord& top_left,
  const int width, const int height,
  const float vspeed, const float hspeed,
  const bool is_mario
) : Movable(top_left, width, height, vspeed, hspeed) {
  this->is_mario = is_mario;
}

bool MoveCollisionable::get_is_mario() const noexcept {
  return this->is_mario;
}
