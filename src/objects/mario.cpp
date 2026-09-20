#include "mario.hpp"

#include "map_movable.hpp"

using biv::Mario;

Mario::Mario(const Coord& top_left, const int width, const int height) 
	: MoveCollisionable(top_left, width, height, 0, 0, true) {}

biv::Rect Mario::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed Mario::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void Mario::move_map_left() noexcept {
	move_horizontal_offset(biv::MapMovable::MAP_STEP);
}

void Mario::move_map_right() noexcept {
	move_horizontal_offset(-biv::MapMovable::MAP_STEP);
}

void Mario::process_horizontal_static_collision(Rect* obj) noexcept {
	hspeed = -hspeed;
	move_horizontally();
}

void Mario::process_mario_collision(Collisionable* mario) noexcept {}

void Mario::process_vertical_static_collision(Rect* obj) noexcept {
	if (vspeed > 0) {
		// Марио упал на корабль.
		top_left.y -= vspeed;
	} else if (vspeed < 0) {
		// Марио ударился головой о полку и после этого должен падать вниз.
		top_left.y -= vspeed;
	}
	vspeed = 0;
}

void Mario::process_movable_collision(Movable* mv) noexcept {
	float pf_speed = mv->get_hspeed();
	this->hspeed += pf_speed;
	move_horizontally();
	this->hspeed -= pf_speed;
}
