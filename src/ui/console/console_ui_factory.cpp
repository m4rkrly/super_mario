#include "console_ui_factory.hpp"

using biv::ConsoleUIFactory;

ConsoleUIFactory::ConsoleUIFactory(Game* game) : UIFactory(game) {}

ConsoleUIFactory::~ConsoleUIFactory() {
	clear_data();
	delete game_map;
	game_map = nullptr;
}

void ConsoleUIFactory::clear_data() {
	game->remove_objs();
	if (game_map != nullptr) {
		game_map->remove_objs();
	}

	delete mario;
	mario = nullptr;

	for (ConsoleBox* box : boxes) {
		delete box;
	}
	boxes.clear();

	for (ConsoleFullBox* full_box : full_boxes) {
		delete full_box;
	}
	full_boxes.clear();

	for (ConsoleShip* ship : ships) {
		delete ship;
	}
	ships.clear();

	for (ConsoleEnemy* enemy : enemies) {
		delete enemy;
	}
	enemies.clear();

	for (ConsoleMoney* money : moneys) {
		delete money;
	}
	moneys.clear();

	for (ConsoleFlyingEnemy* flying_enemy : flying_enemies) {
		delete flying_enemy;
	}
	flying_enemies.clear();

	for (ConsoleJumpingEnemy* jumping_enemy : jumping_enemies) {
		delete jumping_enemy;
	}
	jumping_enemies.clear();

	for (ConsoleHorizontalPlatform* platform : horizontal_platforms) {
		delete platform;
	}
	horizontal_platforms.clear();
}

void ConsoleUIFactory::create_box(
	const Coord& top_left, const int width, const int height
) {
	ConsoleBox* box = new ConsoleBox(top_left, width, height);
	boxes.push_back(box);
	game->add_map_movable(box);
	game->add_static_obj(box);
	game_map->add_obj(box);
}

void ConsoleUIFactory::create_enemy(
	const Coord& top_left, const int width, const int height
) {
	ConsoleEnemy* enemy = new ConsoleEnemy(top_left, width, height);
	enemies.push_back(enemy);
	game->add_map_movable(enemy);
	game->add_movable(enemy);
	game->add_collisionable(enemy);
	game->add_move_collisionable(enemy);
	game_map->add_obj(enemy);
}

void ConsoleUIFactory::create_flying_enemy(
	const Coord& top_left, const int width, const int height,
	const unsigned int offset
) {
	ConsoleFlyingEnemy* flying_enemy = new ConsoleFlyingEnemy(
			top_left, width, height, offset
		);
	flying_enemies.push_back(flying_enemy);
	game->add_map_movable(flying_enemy);
	game->add_movable(flying_enemy);
	game->add_collisionable(flying_enemy);
	game_map->add_obj(flying_enemy);
} 

void ConsoleUIFactory::create_jumping_enemy(
	const Coord& top_left, const int width, const int height
) {
	ConsoleJumpingEnemy* jumping_enemy = new ConsoleJumpingEnemy(top_left, width, height);
	jumping_enemies.push_back(jumping_enemy);
	game->add_map_movable(jumping_enemy);
	game->add_movable(jumping_enemy);
	game->add_collisionable(jumping_enemy);
	game_map->add_obj(jumping_enemy);
}

void ConsoleUIFactory::create_full_box(
	const Coord& top_left, const int width, const int height
) {
	ConsoleFullBox* full_box = new ConsoleFullBox(top_left, width, height, this);
	full_boxes.push_back(full_box);
	game->add_collisionable(full_box);
	game->add_map_movable(full_box);
	game->add_static_obj(full_box);
	game_map->add_obj(full_box);
}

void ConsoleUIFactory::create_mario(
	const Coord& top_left, const int width, const int height
) {
	game->remove_collisionable(mario);
	game->remove_movable(mario);
	game->remove_move_collisionable(mario);
	game->remove_mario();
	game_map->remove_obj(mario);
	delete mario;
	mario = nullptr;
	
	mario = new ConsoleMario(top_left, width, height);
	game->add_collisionable(mario);
	game->add_movable(mario);
	game->add_mario(mario);
	game->add_move_collisionable(mario);
	game_map->add_obj(mario);
}

void ConsoleUIFactory::create_money(
	const Coord& top_left, const int width, const int height
) {
	ConsoleMoney* money = new ConsoleMoney(top_left, width, height);
	moneys.push_back(money);
	game->add_map_movable(money);
	game->add_movable(money);
	game->add_collisionable(money);
	game_map->add_obj(money);

	// (DEV) Добавить сюда move_collisionable тоже!
}

void ConsoleUIFactory::create_ship(
	const Coord& top_left, const int width, const int height
) {
	ConsoleShip* ship = new ConsoleShip(top_left, width, height);
	ships.push_back(ship);
	game->add_map_movable(ship);
	game->add_static_obj(ship);
	game_map->add_obj(ship);
}


void ConsoleUIFactory::create_horizontal_platform(
	const Coord& top_left, const int width, const int height,
	const unsigned int offset
) {
	ConsoleHorizontalPlatform* platform = new ConsoleHorizontalPlatform(
		top_left, width, height, offset
	);
	horizontal_platforms.push_back(platform);
	game->add_map_movable(platform);
	game->add_static_obj(platform);
	game->add_platform(platform);
	game_map->add_obj(platform);
}



biv::GameMap* ConsoleUIFactory::get_game_map(const int height, const int width) {
	if (game_map == nullptr) {
		game_map = new ConsoleGameMap(height, width);
	}
	return game_map;
}

QGraphicsView* ConsoleUIFactory::get_game_map_widget() {
	return nullptr;
}

biv::Mario* ConsoleUIFactory::get_mario() {
	return mario;
}
