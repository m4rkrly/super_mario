#pragma once

#include "app_factory.hpp"

namespace biv {
	class ConsoleAppFactory : public AppFactory {
		private:
			OSControlSettings* control_settings = nullptr;
			KeyBoard* keyboard = nullptr;
			UIFactory* ui_factory = nullptr;

		public:
			ConsoleAppFactory(const int map_height, const int map_width);
			~ConsoleAppFactory() override;

			void create_app(int& argc, char** argv) override;
			OSControlSettings* create_os_control_settings() override;
			KeyBoard* create_keyboard() override;
			UIFactory* create_ui_factory(Game* game) override;
			GameMap* create_game_map() override;

			std::chrono::milliseconds get_frame_delay() const noexcept override;
			void process_events() override;
	};
}
