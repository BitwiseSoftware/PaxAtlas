#pragma once

#include <SFML/Graphics.hpp>

#include "../Mikan/Entity.hh"
#include <vector>

namespace PA {

// Forward declaration
namespace Country {
  class Country;
}

namespace Province {

class Province : public Mikan::Entity {
public:
  Province(unsigned int id, sf::Vector2i middle);

  void tick(float delta_seconds) override;

  void set_shape(const sf::ConvexShape& value);
  void set_owner(Country::Country* owner);

  unsigned int id;
  const sf::Vector2i middle;

private:
  sf::Font font;
  sf::Text name_text;
  std::string name;
  Country::Country* owner;

  void configure_display_name();
};

} // namespace Province
} // namespace PA

