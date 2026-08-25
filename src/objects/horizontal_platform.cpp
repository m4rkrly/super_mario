#include "horizontal_platform.hpp"

using biv::HorizontalPlatform;

HorizontalPlatform::HorizontalPlatform(
  const Coord& top_left, const int width, const int height,
  const unsigned int offset
) : Platform(top_left, width, height, offset) {
  this->vspeed = 0;
  this->hspeed = 0.2;
}


bool HorizontalPlatform::is_on_platform(
  Movable* obj
) const noexcept {
  if (
    (this->get_top() == obj->get_bottom())
    &&
    (this->get_left() <= obj->get_left())
    &&
    (this->get_right() >= obj->get_right())
  ) {
    return true;
  }
  return false;
}


bool HorizontalPlatform::is_in_platform_way(
  Movable* obj
) const noexcept {
  return false; 
}


biv::Coord HorizontalPlatform::move_platform() noexcept {
  move_horizontally();
}

void HorizontalPlatform::process_static_collision(
  Rect* obj
) noexcept {
  process_horizontal_static_collision(obj);
}
