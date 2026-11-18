#pragma once

#include <QObject>
#include <QSet>

#include "keyboard.hpp"

namespace biv {
	class QtKeyBoard : public QObject, public KeyBoard {
		Q_OBJECT

		private:
			QSet<int> pressed_keys;
			int last_direction_key = 0;

		public:
			explicit QtKeyBoard(QObject* parent = nullptr);

			UserInput get_user_input() override;
			void on() override;
			void off() override;

		public slots:
			void process_key_press(int key);
			void process_key_release(int key);
	};
}
