#pragma once

#include <vector>

#include "collisionable.hpp"
#include "movable.hpp"
#include "rect.hpp"
#include "rect_map_movable_adapter.hpp"

namespace biv {
  class Platform : public RectMapMovableAdapter, protected Movable, protected Collisionable {
    protected:
      Coord start;
      Coord end;
      
      std::vector<Movable*> passangers;

      void move_map_left() noexcept override;
      void move_map_right() noexcept override;

      virtual void move_horizontally() noexcept override;
      virtual void move_vertically() noexcept override;

      virtual void process_horizontal_static_collision(Rect*) noexcept override;
      virtual void process_mario_collision(Collisionable*) noexcept;
      virtual void process_vertical_static_collision(Rect*) noexcept;

    public:
      Platform(
        const Coord& top_left, const int width, const int height,
        const unsigned int offset
      );

      virtual bool is_on_platform(Movable*) const noexcept;
      virtual bool is_in_platform_way(Movable*) const noexcept;
      
      virtual Coord move_platform() noexcept;
      virtual void process_static_collision(Rect*) noexcept;

      void update_passangers(const std::vector<Movable*> passangers) noexcept;
  };
}
