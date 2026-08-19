#include "linux_control_settings.hpp"

#include <ncurses.h>

using biv::LinuxControlSettings;

LinuxControlSettings::LinuxControlSettings(const int height, const int width)
: height(height), width(width) {}

void LinuxControlSettings::init() {
	/*initscr();
	curs_set(0);
	noecho();
	nodelay(stdscr, TRUE);

	getmaxyx(stdscr, height, width);*/
	
    initscr();
    // (DEV) отключает необходимость нажимать enter для отправки ввода
    cbreak();
    // (DEV) скрывает ввод символов на экране
    noecho();
    // (DEV) stdscr - "our present window". создаётся initscr
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);	

    // (DEV) задаёт видимость курсора. 0 - невидимый
	curs_set(0);
	getmaxyx(stdscr, height, width);
}

void LinuxControlSettings::set_cursor_start_position() {
	move(0, 0);
}
