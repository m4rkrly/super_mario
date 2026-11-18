#pragma once

#include <QGraphicsItem>
#include <QPixmap>

namespace biv {
	class QtUIObj : public QGraphicsItem {
		public:
			virtual ~QtUIObj() override = default;

			virtual void sync_position() noexcept = 0;
			virtual const QPixmap& get_texture() const noexcept = 0;
	};
}
