#pragma once

#include <QPixmap>

#include <map>
#include <vector>

#include "qt_box.hpp"
#include "qt_enemy.hpp"
#include "qt_flying_enemy.hpp"
#include "qt_full_box.hpp"
#include "qt_game_map.hpp"
#include "qt_horizontal_platform.hpp"
#include "qt_jumping_enemy.hpp"
#include "qt_mario.hpp"
#include "qt_money.hpp"
#include "qt_ship.hpp"
#include "ui_factory.hpp"

namespace biv {
	class QtUIFactory : public UIFactory {
		private:
			enum class TextureId {
				BOX,
				ENEMY,
				FLYING_ENEMY,
				JUMPING_ENEMY,
				FULL_BOX,
				FULL_BOX_USED,
				MARIO,
				MONEY,
				SHIP,
				HORIZONTAL_PLATFORM,
				SKY,
				WATER
			};

			QtGameMap* game_map = nullptr;
			std::map<TextureId, QPixmap> textures;

			std::vector<QtBox*> boxes;
			std::vector<QtFullBox*> full_boxes;
			std::vector<QtShip*> ships;
			QtMario* mario = nullptr;
			std::vector<QtEnemy*> enemies;
			std::vector<QtMoney*> moneys;
			std::vector<QtFlyingEnemy*> flying_enemies;
			std::vector<QtJumpingEnemy*> jumping_enemies;
			std::vector<QtHorizontalPlatform*> horizontal_platforms;

			void load_textures();
			QPixmap load_texture(const char* path) const;
			const QPixmap& get_texture(TextureId id) const;

		public:
			QtUIFactory(Game* game);
			~QtUIFactory() override;

			void clear_data() override;
			void create_box(
				const Coord& top_left,
				const int width,
				const int height
			) override;
			void create_enemy(
				const Coord& top_left,
				const int width,
				const int height
			) override;
			void create_flying_enemy(
				const Coord& top_left,
				const int width,
				const int height,
				const unsigned int offset
			) override;
			void create_jumping_enemy(
				const Coord& top_left,
				const int width,
				const int height
			) override;
			void create_full_box(
				const Coord& top_left,
				const int width,
				const int height
			) override;
			void create_mario(
				const Coord& top_left,
				const int width,
				const int height
			) override;
			void create_money(
				const Coord& top_left,
				const int width,
				const int height
			) override;
			void create_ship(
				const Coord& top_left,
				const int width,
				const int height
			) override;
			void create_horizontal_platform(
				const Coord& top_left,
				const int width,
				const int height,
				const unsigned int offset
			) override;

			GameMap* get_game_map(const int height, const int width) override;
			QGraphicsView* get_game_map_widget() override;
			Mario* get_mario() override;
	};
}
