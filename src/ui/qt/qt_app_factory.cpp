#include "qt_app_factory.hpp"

#include <QApplication>
#include <QGraphicsView>
#include <QObject>

#include "game_window.hpp"
#include "qt_control_settings.hpp"
#include "qt_keyboard.hpp"
#include "qt_ui_factory.hpp"

using biv::QtAppFactory;

QtAppFactory::QtAppFactory(
	const int map_height,
	const int map_width
) : AppFactory(map_height, map_width) {}

QtAppFactory::~QtAppFactory() {
	delete keyboard;
	keyboard = nullptr;

	delete window;
	window = nullptr;

	delete ui_factory;
	ui_factory = nullptr;

	delete control_settings;
	control_settings = nullptr;

	delete app;
	app = nullptr;
}

void QtAppFactory::create_app(int& argc, char** argv) {
	if (app == nullptr) {
		app = new QApplication(argc, argv);
	}

	if (window == nullptr) {
		window = new GameWindow();
	}
}

biv::OSControlSettings* QtAppFactory::create_os_control_settings() {
	if (control_settings == nullptr) {
		control_settings = new QtControlSettings();
	}
	return control_settings;
}

biv::KeyBoard* QtAppFactory::create_keyboard() {
	if (keyboard == nullptr) {
		keyboard = new QtKeyBoard();

		if (window != nullptr) {
			QObject::connect(
				window, &GameWindow::key_pressed,
				keyboard, &QtKeyBoard::process_key_press
			);
			QObject::connect(
				window, &GameWindow::key_released,
				keyboard, &QtKeyBoard::process_key_release
			);
		}
	}
	return keyboard;
}

biv::UIFactory* QtAppFactory::create_ui_factory(Game* game) {
	if (ui_factory == nullptr) {
		ui_factory = new QtUIFactory(game);
	}
	return ui_factory;
}

biv::GameMap* QtAppFactory::create_game_map() {
	if (ui_factory == nullptr) {
		return nullptr;
	}

	GameMap* map = ui_factory->get_game_map(map_height, map_width);
	QGraphicsView* view = ui_factory->get_game_map_widget();

	if (window != nullptr && view != nullptr) {
		window->setCentralWidget(view);
		window->setFixedSize(view->size());
		window->show();
		window->activateWindow();
		window->setFocus();
	}

	return map;
}

std::chrono::milliseconds QtAppFactory::get_frame_delay() const noexcept {
	return std::chrono::milliseconds(16);
}

void QtAppFactory::process_events() {
	if (app != nullptr) {
		QApplication::processEvents();
	}
}
