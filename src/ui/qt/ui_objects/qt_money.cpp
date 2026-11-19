#include "qt_money.hpp"

using biv::QtMoney;

QtMoney::QtMoney(
	const Coord& top_left,
	const int width,
	const int height,
	const QPixmap& texture
) : Money(top_left, width, height),
	QtUIObjRectAdapter(top_left, width, height, texture) {}
