#pragma once

#include "movable.hpp"
#include "collisionable.hpp"

namespace biv {
  class MoveCollisionable : public Movable, public Collisionable {
    public:
      MoveCollisionable();
      MoveCollisionable(
        const Coord& top_left,
        const int width, const int height,
        const float vspeed, const float hspeed
      );

      virtual void process_movable_collision(Movable* pf) noexcept = 0;
  };
}
