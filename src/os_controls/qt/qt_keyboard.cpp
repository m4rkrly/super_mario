#include "qt_keyboard.hpp"

#include <Qt>

using biv::QtKeyBoard;

QtKeyBoard::QtKeyBoard(QObject* parent) : QObject(parent) {}

void QtKeyBoard::process_key_press(int key) {
	pressed_keys.insert(key);

	if (key == Qt::Key_A || key == Qt::Key_D) {
		last_direction_key = key;
	}
}

void QtKeyBoard::process_key_release(int key) {
	pressed_keys.remove(key);

	if (key != last_direction_key) {
		return;
	}

	if (pressed_keys.contains(Qt::Key_D)) {
		last_direction_key = Qt::Key_D;
	} else if (pressed_keys.contains(Qt::Key_A)) {
		last_direction_key = Qt::Key_A;
	} else {
		last_direction_key = 0;
	}
}

biv::UserInput QtKeyBoard::get_user_input() {
	if (
		pressed_keys.contains(Qt::Key_Q)
		|| pressed_keys.contains(Qt::Key_Escape)
	) {
		return UserInput::EXIT;
	}

	if (pressed_keys.contains(Qt::Key_Space)) {
		return UserInput::MARIO_JUMP;
	}

	if (last_direction_key == Qt::Key_A) {
		return UserInput::MAP_RIGHT;
	}

	if (last_direction_key == Qt::Key_D) {
		return UserInput::MAP_LEFT;
	}

	return UserInput::NO_INPUT;
}

void QtKeyBoard::on() {
	off();
}

void QtKeyBoard::off() {
	pressed_keys.clear();
	last_direction_key = 0;
}
