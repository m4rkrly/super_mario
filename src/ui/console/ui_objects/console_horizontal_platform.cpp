#include "console_horizontal_platform.hpp"

using biv::ConsoleHorizontalPlatform;

ConsoleHorizontalPlatform::ConsoleHorizontalPlatform(
  const Coord& top_left, const int width, const int height,
  const unsigned int offset
) : HorizontalPlatform(top_left, width, height, offset) {}

char ConsoleHorizontalPlatform::get_brush() const noexcept {
  return 'p';
}
