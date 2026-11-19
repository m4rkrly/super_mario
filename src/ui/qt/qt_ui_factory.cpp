#include "qt_ui_factory.hpp"

#include <Qt>

#include "qt_ui_obj_rect_adapter.hpp"

using biv::QtUIFactory;

QtUIFactory::QtUIFactory(Game* game) : UIFactory(game) {
	load_textures();
}

QtUIFactory::~QtUIFactory() {
	clear_data();
	delete game_map;
	game_map = nullptr;
}

void QtUIFactory::clear_data() {
	game->remove_objs();
	if (game_map != nullptr) {
		game_map->remove_objs();
	}

	delete mario;
	mario = nullptr;

	for (QtBox* box : boxes) {
		delete box;
	}
	boxes.clear();

	for (QtFullBox* full_box : full_boxes) {
		delete full_box;
	}
	full_boxes.clear();

	for (QtShip* ship : ships) {
		delete ship;
	}
	ships.clear();

	for (QtEnemy* enemy : enemies) {
		delete enemy;
	}
	enemies.clear();

	for (QtMoney* money : moneys) {
		delete money;
	}
	moneys.clear();

	for (QtFlyingEnemy* flying_enemy : flying_enemies) {
		delete flying_enemy;
	}
	flying_enemies.clear();

	for (QtJumpingEnemy* jumping_enemy : jumping_enemies) {
		delete jumping_enemy;
	}
	jumping_enemies.clear();

	for (QtHorizontalPlatform* platform : horizontal_platforms) {
		delete platform;
	}
	horizontal_platforms.clear();
}

void QtUIFactory::create_box(
	const Coord& top_left,
	const int width,
	const int height
) {
	QtBox* box = new QtBox(
		top_left, width, height, get_texture(TextureId::BOX)
	);
	boxes.push_back(box);
	game->add_map_movable(box);
	game->add_static_obj(box);
	game_map->add_obj(box);
}

void QtUIFactory::create_enemy(
	const Coord& top_left,
	const int width,
	const int height
) {
	QtEnemy* enemy = new QtEnemy(
		top_left, width, height, get_texture(TextureId::ENEMY)
	);
	enemies.push_back(enemy);
	game->add_map_movable(enemy);
	game->add_movable(enemy);
	game->add_collisionable(enemy);
	game->add_move_collisionable(enemy);
	game_map->add_obj(enemy);
}

void QtUIFactory::create_flying_enemy(
	const Coord& top_left,
	const int width,
	const int height,
	const unsigned int offset
) {
	QtFlyingEnemy* flying_enemy = new QtFlyingEnemy(
		top_left, width, height, offset,
		get_texture(TextureId::FLYING_ENEMY)
	);
	flying_enemies.push_back(flying_enemy);
	game->add_map_movable(flying_enemy);
	game->add_movable(flying_enemy);
	game->add_collisionable(flying_enemy);
	game_map->add_obj(flying_enemy);
}

void QtUIFactory::create_jumping_enemy(
	const Coord& top_left,
	const int width,
	const int height
) {
	QtJumpingEnemy* jumping_enemy = new QtJumpingEnemy(
		top_left, width, height, get_texture(TextureId::JUMPING_ENEMY)
	);
	jumping_enemies.push_back(jumping_enemy);
	game->add_map_movable(jumping_enemy);
	game->add_movable(jumping_enemy);
	game->add_collisionable(jumping_enemy);
	game_map->add_obj(jumping_enemy);
}

void QtUIFactory::create_full_box(
	const Coord& top_left,
	const int width,
	const int height
) {
	QtFullBox* full_box = new QtFullBox(
		top_left, width, height, this,
		get_texture(TextureId::FULL_BOX),
		get_texture(TextureId::FULL_BOX_USED)
	);
	full_boxes.push_back(full_box);
	game->add_collisionable(full_box);
	game->add_map_movable(full_box);
	game->add_static_obj(full_box);
	game_map->add_obj(full_box);
}

void QtUIFactory::create_mario(
	const Coord& top_left,
	const int width,
	const int height
) {
	game->remove_collisionable(mario);
	game->remove_movable(mario);
	game->remove_move_collisionable(mario);
	game->remove_mario();
	game_map->remove_obj(mario);
	delete mario;
	mario = nullptr;

	mario = new QtMario(
		top_left, width, height, get_texture(TextureId::MARIO)
	);
	game->add_collisionable(mario);
	game->add_movable(mario);
	game->add_mario(mario);
	game->add_move_collisionable(mario);
	game_map->add_obj(mario);
}

void QtUIFactory::create_money(
	const Coord& top_left,
	const int width,
	const int height
) {
	QtMoney* money = new QtMoney(
		top_left, width, height, get_texture(TextureId::MONEY)
	);
	moneys.push_back(money);
	game->add_map_movable(money);
	game->add_movable(money);
	game->add_collisionable(money);
	game_map->add_obj(money);
}

void QtUIFactory::create_ship(
	const Coord& top_left,
	const int width,
	const int height
) {
	QtShip* ship = new QtShip(
		top_left, width, height, get_texture(TextureId::SHIP)
	);
	ships.push_back(ship);
	game->add_map_movable(ship);
	game->add_static_obj(ship);
	game_map->add_obj(ship);
}

void QtUIFactory::create_horizontal_platform(
	const Coord& top_left,
	const int width,
	const int height,
	const unsigned int offset
) {
	QtHorizontalPlatform* platform = new QtHorizontalPlatform(
		top_left, width, height, offset,
		get_texture(TextureId::HORIZONTAL_PLATFORM)
	);
	horizontal_platforms.push_back(platform);
	game->add_map_movable(platform);
	game->add_static_obj(platform);
	game->add_platform(platform);
	game_map->add_obj(platform);
}

biv::GameMap* QtUIFactory::get_game_map(const int height, const int width) {
	if (game_map == nullptr) {
		game_map = new QtGameMap(
			height, width,
			get_texture(TextureId::SKY),
			get_texture(TextureId::WATER)
		);
	}
	return game_map;
}

QGraphicsView* QtUIFactory::get_game_map_widget() {
	if (game_map == nullptr) {
		return nullptr;
	}
	return game_map->get_viewer();
}

biv::Mario* QtUIFactory::get_mario() {
	return mario;
}

void QtUIFactory::load_textures() {
	textures[TextureId::BOX] =
		load_texture(":/textures/box.png");
	textures[TextureId::ENEMY] =
		load_texture(":/textures/enemy.png");
	textures[TextureId::FLYING_ENEMY] =
		load_texture(":/textures/flying_enemy.png");
	textures[TextureId::JUMPING_ENEMY] =
		load_texture(":/textures/jumping_enemy.png");
	textures[TextureId::FULL_BOX] =
		load_texture(":/textures/full_box.png");
	textures[TextureId::FULL_BOX_USED] =
		load_texture(":/textures/full_box_used.png");
	textures[TextureId::MARIO] =
		load_texture(":/textures/mario.png");
	textures[TextureId::MONEY] =
		load_texture(":/textures/money.png");
	textures[TextureId::SHIP] =
		load_texture(":/textures/ship.png");
	textures[TextureId::HORIZONTAL_PLATFORM] =
		load_texture(":/textures/horizontal_platform.png");
	textures[TextureId::SKY] =
		load_texture(":/textures/sky.png");
	textures[TextureId::WATER] =
		load_texture(":/textures/water.png");
}

QPixmap QtUIFactory::load_texture(const char* path) const {
	QPixmap pixmap(path);

	if (pixmap.isNull()) {
		pixmap = QPixmap(
			QtUIObjRectAdapter::TILE_SIZE,
			QtUIObjRectAdapter::TILE_SIZE
		);
		pixmap.fill(Qt::magenta);
		return pixmap;
	}

	if (
		pixmap.width() != QtUIObjRectAdapter::TILE_SIZE
		|| pixmap.height() != QtUIObjRectAdapter::TILE_SIZE
	) {
		pixmap = pixmap.scaled(
			QtUIObjRectAdapter::TILE_SIZE,
			QtUIObjRectAdapter::TILE_SIZE,
			Qt::IgnoreAspectRatio,
			Qt::FastTransformation
		);
	}

	return pixmap;
}

const QPixmap& QtUIFactory::get_texture(TextureId id) const {
	return textures.at(id);
}
