#pragma once

#include <QMainWindow>

class QCloseEvent;
class QKeyEvent;

namespace biv {
	class GameWindow : public QMainWindow {
		Q_OBJECT

		public:
			explicit GameWindow(QWidget* parent = nullptr);

		signals:
			void key_pressed(int key);
			void key_released(int key);

		protected:
			void keyPressEvent(QKeyEvent* event) override;
			void keyReleaseEvent(QKeyEvent* event) override;
			void closeEvent(QCloseEvent* event) override;
	};
}
