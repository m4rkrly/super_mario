#pragma once

#include <QPixmap>
#include <QRectF>

#include "qt_ui_obj.hpp"
#include "rect.hpp"

class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;

namespace biv {
	class QtUIObjRectAdapter : virtual public Rect, public QtUIObj {
		public:
			static constexpr int TILE_SIZE = 16;

			QtUIObjRectAdapter(
				const Coord& top_left,
				const int width,
				const int height,
				const QPixmap& texture
			);

			QRectF boundingRect() const override;
			void paint(
				QPainter* painter,
				const QStyleOptionGraphicsItem* option,
				QWidget* widget
			) override;
			void sync_position() noexcept override;
			const QPixmap& get_texture() const noexcept override;

		protected:
			QPixmap texture;
	};
}
