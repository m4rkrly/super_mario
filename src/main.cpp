/**
        Игровой цикл - это обощённое представление потока событий, происходящих
   в игре.

        Игровой цикл:
                1. Установка параметров игры
                2. Получение пользовательского ввода
                3. Обновление внутреннего состояния игры
                4. Обновление изображения на экране
                5. Проверка того, не окончена ли игра

                *** Если игра не окончена, то возвращаемся в пункт № 2.

                6. Завершение

        - Какие архитектурные принципы применены при реализации игры?

        - На основе какого приципа ООП построен алгоритм игры?
        - Какими элементами языка С++ реализуется этот принцип?
        - Приведите примеры кода, отображающие этот прицип.
*/
#include <chrono>
#include <thread>

#include "app_factory.hpp"
#include "first_level.hpp"
#include "game.hpp"
#include "game_level.hpp"
#include "game_map.hpp"
#include "keyboard.hpp"
#include "mario.hpp"
#include "os_control_settings.hpp"
#include "ui_factory.hpp"

#ifdef QT
#include "qt_app_factory.hpp"
#else
#include "console_app_factory.hpp"
#endif

int main(int argc, char **argv) {
  // 1. Установка параметров игры
  using namespace std::chrono_literals;

  const int map_height = 30;
  const int map_width = 200;

  biv::Game game;

  biv::AppFactory *app_factory = nullptr;
#ifdef QT
  app_factory = new biv::QtAppFactory(map_height, map_width);
#else
  app_factory = new biv::ConsoleAppFactory(map_height, map_width);
#endif

  app_factory->create_app(argc, argv);

  biv::OSControlSettings *control_settings =
      app_factory->create_os_control_settings();
  biv::KeyBoard *keyboard = app_factory->create_keyboard();

  control_settings->init();
  keyboard->on();

  biv::UIFactory *ui_factory = app_factory->create_ui_factory(&game);
  biv::GameMap *game_map = app_factory->create_game_map();

  biv::GameLevel *game_level = new biv::FirstLevel(ui_factory);
  biv::GameLevel *first_level = game_level;
  biv::Mario *mario = ui_factory->get_mario();

  biv::UserInput user_input;
  do {
    // 2. Получение пользовательского ввода
    user_input = keyboard->get_user_input();
    switch (user_input) {
    case biv::UserInput::MAP_LEFT:
      mario->move_map_left();
      if (!game.check_static_collisions(mario)) {
        game.move_map_left();
      }
      mario->move_map_right();
      break;
    case biv::UserInput::MAP_RIGHT:
      mario->move_map_right();
      if (!game.check_static_collisions(mario)) {
        game.move_map_right();
      }
      mario->move_map_left();
      break;
    case biv::UserInput::MARIO_JUMP:
      mario->jump();
      break;
    case biv::UserInput::EXIT:
      game.finish();
      break;
    }

    // 3. Обновление внутреннего состояния игры
    // game.gather_platforms_passangers();
    game.move_platforms();
    game.move_objs_horizontally();
    game.check_horizontally_static_collisions();

    game.move_objs_vertically();
    game.check_mario_collision();
    game.check_vertically_static_collisions();

    /* (DEV) is_active показывает будет ли персонаж рассматриваться
    при коллизиях или нет (мёртв или жив в текущей реализации) */
    if (game_map->is_below_map(mario->get_top()) || !mario->is_active()) {
      keyboard->off();
      keyboard->on();
      game_level->restart();
      mario = ui_factory->get_mario();
      std::this_thread::sleep_for(1000ms);
    }

    if (game.is_level_end()) {
      if (!game_level->is_final()) {
        game_level = game_level->get_next();
        mario = ui_factory->get_mario();
        std::this_thread::sleep_for(1000ms);
        keyboard->off();
        keyboard->on();
        game.start_level();
      } else {
        game.finish();
      }
    }

    // 4. Обновление изображения на экране
    game_map->refresh();
    control_settings->set_cursor_start_position();
    game_map->show();
    app_factory->process_events();
    std::this_thread::sleep_for(app_factory->get_frame_delay());
  } while (
      /* 5. Проверка того, не окончена ли игра */
      !game.is_finished());

  // 6. Завершение
  delete first_level;
  delete app_factory;
}
