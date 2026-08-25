#pragma once

#include "collisionable.hpp"
#include "platform.hpp"

namespace biv {
  class HorizontalPlatform : public Platform {
    public:
      HorizontalPlatform(
        const Coord& top_left, const int width, const int height,
        const unsigned int offset
      );

      bool is_on_platform(Movable*) const noexcept override;
      bool is_in_platform_way(Movable*) const noexcept override;
      
      Coord move_platform() noexcept override;
      virtual void process_static_collision() noexcept override;
  };
}
