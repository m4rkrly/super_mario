#include "game_window.hpp"

#include <QCloseEvent>
#include <QKeyEvent>
#include <Qt>

using biv::GameWindow;

GameWindow::GameWindow(QWidget* parent) : QMainWindow(parent) {
	setWindowTitle("Super Mario");
	setFocusPolicy(Qt::StrongFocus);
}

void GameWindow::keyPressEvent(QKeyEvent* event) {
	if (!event->isAutoRepeat()) {
		emit key_pressed(event->key());
	}

	QMainWindow::keyPressEvent(event);
}

void GameWindow::keyReleaseEvent(QKeyEvent* event) {
	if (!event->isAutoRepeat()) {
		emit key_released(event->key());
	}

	QMainWindow::keyReleaseEvent(event);
}

void GameWindow::closeEvent(QCloseEvent* event) {
	emit key_pressed(Qt::Key_Q);
	QMainWindow::closeEvent(event);
}
