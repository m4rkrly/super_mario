#pragma once

#include "movable.hpp"
#include "collisionable.hpp"

namespace biv {
  class MoveCollsionable : public Movable, public Collisionable {
    public:
      MoveCollsionable(
        const Coord& top_left,
        const int width, const int height,
        const float vspeed, const float hspeed
      );

      virtual void process_movable_collision(Movable* pf) = 0;
      virtual void decide_to_move(Rect* obj);
  };
}
