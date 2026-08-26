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
  top_left.x -= MapMovable::MAP_STEP;
  start.x -= MapMovable::MAP_STEP;
  end.x -= MapMovable::MAP_STEP;
}


void Platform::move_map_right() noexcept {
  top_left.x += MapMovable::MAP_STEP;
  start.x += MapMovable::MAP_STEP;
  end.x += MapMovable::MAP_STEP;
}


void Platform::move_horizontally() noexcept {
  int cur_x = static_cast<int>(top_left.x);
  int start_x = static_cast<int>(start.x);
  int end_x = static_cast<int>(end.x);

  if ((cur_x - start_x < 0) || (end_x - cur_x < 0)) 
    hspeed = -hspeed;
  move_horizontal_offset(hspeed);
}


void Platform::move_vertically() noexcept {
  int cur_y = static_cast<int>(top_left.y);
  int start_y = static_cast<int>(start.y);
  int end_y = static_cast<int>(end.y);

  if ((cur_y - start_y < 0) || (end_y - cur_y < 0)) 
    vspeed = -vspeed;
  move_vertical_offset(vspeed);
}


void Platform::force_passsangers_direction_recheck() noexcept {
  for (Movable* mv : this->passangers) {
    Collisionable* cl = dynamic_cast<Collisionable*>(mv);
    cl->decide_to_move(this);
  }
}


bool Platform::is_on_platform(Movable* obj) const noexcept { return false; }


bool Platform::is_in_platform_way(Movable* obj) const noexcept { return false; }


biv::Coord Platform::move_platform() noexcept {
  return {0, 0};
}


void Platform::process_static_collision() noexcept {}



void Platform::update_passangers(
  const std::vector<Movable*> passangers
) noexcept {
  this->passangers = passangers;
}

std::vector<biv::Movable*> Platform::get_passangers() const noexcept {
  return this->passangers;
}
