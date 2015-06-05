#pragma once

#include <SFML/Graphics.hpp>

#include "Mikan/Entity.hh"

namespace PA {
    
class FrameRate : Mikan::Entity {
public:
  FrameRate();

  void tick(float delta_seconds) override;

private:
  void display_fps();
  std::string configure_text();

  double current_fps;
  sf::Clock fps_clock;
  unsigned int fps_incrementor = 0;
};

} // namespace PA

