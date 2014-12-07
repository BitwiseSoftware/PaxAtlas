#include "Country.hh"

PA::Country::Country::Country(const sf::Color& color)
{
	this->color = color;
}

void PA::Country::Country::add_province(PA::Province::Province* province)
{
	province->shape.setFillColor(color);
	provinces.push_back(province);
}
