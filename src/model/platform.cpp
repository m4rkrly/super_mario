#include "platform.hpp"

using biv::Platform;

Platform::Platform(
  const Coord& top_left, const int width, const int height,
  const unsigned int offset 
) : RectMapMovableAdapter(top_left, width, height) {
  this->start = top_left;
  this->end = top_left;
  this->end.x += offset;
}


void Platform::move_map_left() noexcept {

}


void Platform::move_map_right() noexcept {

}


void Platform::move_horizontally() noexcept {}



void Platform::move_vertically() noexcept {}


void Platform::process_horizontal_static_collision(Rect* obj) noexcept {
  
}


void Platform::process_mario_collision(Collisionable*) noexcept {

}


void Platform::process_vertical_static_collision(Rect* obj) noexcept {
  
}


bool Platform::is_on_platform() const noexcept { return false; }


bool Platform::is_in_platform_way() const noexcept { return false; }


biv::Coord Platform::move_platform() noexcept {
  return {0, 0};
}


void Platform::process_static_collision() noexcept {

}



void Platform::update_passangers(
  const std::vector<Movable*> passangers
) noexcept {

}
