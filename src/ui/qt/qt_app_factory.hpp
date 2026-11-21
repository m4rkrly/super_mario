#pragma once

#include "app_factory.hpp"

class QApplication;

namespace biv {
	class GameWindow;
	class QtControlSettings;
	class QtKeyBoard;
	class QtUIFactory;

	class QtAppFactory : public AppFactory {
		private:
			QApplication* app = nullptr;
			GameWindow* window = nullptr;
			QtKeyBoard* keyboard = nullptr;
			QtControlSettings* control_settings = nullptr;
			QtUIFactory* ui_factory = nullptr;

		public:
			QtAppFactory(const int map_height, const int map_width);
			~QtAppFactory() override;

			void create_app(int& argc, char** argv) override;
			OSControlSettings* create_os_control_settings() override;
			KeyBoard* create_keyboard() override;
			UIFactory* create_ui_factory(Game* game) override;
			GameMap* create_game_map() override;

			std::chrono::milliseconds get_frame_delay() const noexcept override;
			void process_events() override;
	};
}
