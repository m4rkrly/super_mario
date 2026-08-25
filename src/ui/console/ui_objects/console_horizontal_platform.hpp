#pragma once

#include "console_ui_obj_rect_adapter.hpp"
#include "horizontal_platform.hpp"

namespace biv {
  class ConsoleHorizontalPlatform : public HorizontalPlatform, public ConsoleUIObjectRectAdapter {
    public:
      ConsoleHorizontalPlatform(
        const Coord& top_left, const int width, const int height,
        const unsigned int offset
      );

      char get_brush() const noexcept override;
  };
}
