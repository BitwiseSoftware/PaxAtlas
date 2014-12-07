#include "Country.hh"

PA::Country::Country::Country()
{

}

void PA::Country::Country::add_province(PA::Province::Province* province)
{
	// Temperary global province colour
	province->shape.setFillColor(sf::Color::Green);
	provinces.push_back(province);
}
