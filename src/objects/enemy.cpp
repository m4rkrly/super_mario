#include "enemy.hpp"

#include "map_movable.hpp"

using biv::Enemy;

Enemy::Enemy(const Coord& top_left, const int width, const int height) 
	: RectMapMovableAdapter(top_left, width, height) {
	vspeed = 0;
	hspeed = 0.2;
}

biv::Rect Enemy::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed Enemy::get_speed() const noexcept {
	return {vspeed, hspeed};
}

//void Enemy::decide_to_move(Rect* static_obj) noexcept {
  // float next_left = get_x() + hspeed;
  // float next_right = get_x() + width + hspeed; 
  //
  // if (next_left < static_obj->get_left() || next_right > static_obj->get_right()) {
  //   hspeed = -hspeed;
  // }
//}

void Enemy::process_horizontal_static_collision(Rect* obj) noexcept {
	hspeed = -hspeed;
	move_horizontally();
}

void Enemy::process_mario_collision(Collisionable* mario) noexcept {
	if (mario->get_speed().v > 0 && mario->get_speed().v != V_ACCELERATION) {
		kill();
	} else {
		mario->kill();
	}
}

void Enemy::process_vertical_static_collision(Rect* obj) noexcept {
	// Проверка: не свалился ли враг с корабля. 
	// Т.е., если он на краю, то он должен разверуться 
	// и побежать в обратную сторону.
  float next_left = get_x() + hspeed;
  float next_right = get_x() + width + hspeed; 

  if (next_left < obj->get_left() || next_right > obj->get_right()) {
    hspeed = -hspeed;
  }

	// Особенность модели вертикального передвижения в игре.
	if (vspeed > 0) {
		top_left.y -= vspeed;
		vspeed = 0;
	}
}


void Enemy::process_movable_collision(Movable* mv) noexcept {
	float pf_speed = mv->get_hspeed();
	this->hspeed += pf_speed;
	move_horizontally();
	this->hspeed -= pf_speed;

	float next_left = get_x() + hspeed;
  float next_right = get_x() + width + hspeed; 

  if (next_left < mv->get_left() || next_right > mv->get_right()) {
    hspeed = -hspeed;
  }

}
