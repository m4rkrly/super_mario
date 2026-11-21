#include "console_app_factory.hpp"

#include "console_ui_factory.hpp"

#ifdef WINDOWS_CONSOLE
#include "windows_control_settings.hpp"
#include "windows_keyboard.hpp"
#elif defined(LINUX_CONSOLE)
#include "linux_control_settings.hpp"
#include "linux_keyboard.hpp"
#endif

using biv::ConsoleAppFactory;

ConsoleAppFactory::ConsoleAppFactory(const int map_height, const int map_width)
    : AppFactory(map_height, map_width) {}

ConsoleAppFactory::~ConsoleAppFactory() {
  delete ui_factory;
  ui_factory = nullptr;

  delete keyboard;
  keyboard = nullptr;

  delete control_settings;
  control_settings = nullptr;
}

void ConsoleAppFactory::create_app(int &argc, char **argv) {
  (void)argc;
  (void)argv;
}

biv::OSControlSettings *ConsoleAppFactory::create_os_control_settings() {
  if (control_settings == nullptr) {
#ifdef WINDOWS_CONSOLE
    control_settings = new WindowsControlSettings();
#elif defined(LINUX_CONSOLE)
    control_settings = new LinuxControlSettings(map_height, map_width);
#endif
  }
  return control_settings;
}

biv::KeyBoard *ConsoleAppFactory::create_keyboard() {
  if (keyboard == nullptr) {
#ifdef WINDOWS_CONSOLE
    keyboard = new WindowsKeyBoard();
#elif defined(LINUX_CONSOLE)
    keyboard = new LinuxKeyboard();
#endif
  }
  return keyboard;
}

biv::UIFactory *ConsoleAppFactory::create_ui_factory(Game *game) {
  if (ui_factory == nullptr) {
    ui_factory = new ConsoleUIFactory(game);
  }
  return ui_factory;
}

biv::GameMap *ConsoleAppFactory::create_game_map() {
  if (ui_factory == nullptr) {
    return nullptr;
  }
  return ui_factory->get_game_map(map_height, map_width);
}

std::chrono::milliseconds ConsoleAppFactory::get_frame_delay() const noexcept {
#ifdef WINDOWS_CONSOLE
  return std::chrono::milliseconds(10);
#elif defined(LINUX_CONSOLE)
  return std::chrono::milliseconds(50);
#endif
}

void ConsoleAppFactory::process_events() {}
