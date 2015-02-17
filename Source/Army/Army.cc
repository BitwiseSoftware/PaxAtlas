#include "Army.hh"

#include <iostream>

namespace PA {
namespace Army {

Army::Army(Province::Province& location, std::vector<Unit> units)
        : location(location), units(units) {
    shape.setPosition(static_cast<sf::Vector2f>(location.middle));
    shape.setPointCount(4);
    shape.setPoint(0, sf::Vector2f(0, 0));
    shape.setPoint(1, sf::Vector2f(0, 4));
    shape.setPoint(2, sf::Vector2f(4, 4));
    shape.setPoint(3, sf::Vector2f(4, 0));
}

void Army::tick(const float delta_seconds) {
}

} // namespace Army
} // namespace PA
