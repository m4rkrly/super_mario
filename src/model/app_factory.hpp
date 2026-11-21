#pragma once

#include <chrono>

#include "keyboard.hpp"
#include "os_control_settings.hpp"
#include "ui_factory.hpp"

namespace biv {
class AppFactory {
public:
  virtual ~AppFactory() = default;

  virtual void create_app(int &argc, char **argv) = 0;
  virtual OSControlSettings *create_os_control_settings() = 0;
  virtual KeyBoard *create_keyboard() = 0;
  virtual UIFactory *create_ui_factory(Game *game) = 0;
  virtual GameMap *create_game_map() = 0;

  virtual std::chrono::milliseconds get_frame_delay() const noexcept = 0;
  virtual void process_events() = 0;

protected:
  AppFactory(const int map_height, const int map_width)
      : map_height(map_height), map_width(map_width) {}

  const int map_height;
  const int map_width;
};
} // namespace biv
