#include "flying_enemy.hpp"


using biv::FlyingEnemy;

FlyingEnemy::FlyingEnemy(
  const Coord& top_left, const int width, const int height,
  const Coord& start, const int offset
) : RectMapMovableAdapter(top_left, width, height) {
  vspeed = 0;
  hspeed = 0.2;
  this->start = start;
  end = start;
  end.x += offset;
}


biv::Rect FlyingEnemy::get_rect() const noexcept {
	return {top_left, width, height};
}


biv::Speed FlyingEnemy::get_speed() const noexcept {
	return {vspeed, hspeed};
}


void FlyingEnemy::move_horizontally() noexcept {
  int cur_x = static_cast<int>(top_left.x);
  int start_x = static_cast<int>(start.x);
  int end_x = static_cast<int>(end.x);

  if ((cur_x - start_x == 0) || (end_x - cur_x == 0)) 
    hspeed = -hspeed;
  move_horizontal_offset(hspeed);
}

void FlyingEnemy::move_vertically() noexcept {}

void FlyingEnemy::process_horizontal_static_collision(Rect* obj) noexcept {
	hspeed = -hspeed;
	move_horizontally();
}


void FlyingEnemy::process_mario_collision(Collisionable* mario) noexcept {
	if (mario->get_speed().v > 0 && mario->get_speed().v != V_ACCELERATION) {
		kill();
	} else {
		mario->kill();
	}
}


void FlyingEnemy::process_vertical_static_collision(Rect* obj) noexcept {}
