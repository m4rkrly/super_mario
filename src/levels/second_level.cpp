#include "second_level.hpp"

using biv::SecondLevel;

SecondLevel::SecondLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

bool SecondLevel::is_final() const noexcept {
	return true;
}

biv::GameLevel* SecondLevel::get_next() {
	return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void SecondLevel::init_data() {
	ui_factory->create_mario({39, 10}, 3, 3);
	
	ui_factory->create_ship({20, 25}, 40, 2);

	ui_factory->create_enemy({55, 23}, 3, 2);
	ui_factory->create_flying_enemy({25, 15}, 4, 2, 30);

	ui_factory->create_ship({75, 20}, 10, 7);

	ui_factory->create_jumping_enemy({80, 17}, 3, 2);

	ui_factory->create_ship({95, 24}, 30, 3);
	
	ui_factory->create_full_box({110, 17}, 5, 3);

	ui_factory->create_enemy({115, 20}, 3, 2);
	ui_factory->create_enemy({120, 20}, 3, 2);

	ui_factory->create_horizontal_platform({95, 12}, 7, 3, 30);
	ui_factory->create_enemy({98, 10}, 3, 2);


	ui_factory->create_ship({140, 25}, 10, 2);
}
