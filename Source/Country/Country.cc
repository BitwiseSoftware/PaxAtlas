#include "Country.hh"

#include <algorithm>

PA::Country::Country::Country(const sf::Color& color)
{
	this->color = color;
}

void PA::Country::Country::add_province(PA::Province::Province* province)
{
	provinces.push_back(province);
}

void PA::Country::Country::remove_province(PA::Province::Province* province)
{
	const auto position = std::find(provinces.begin(), provinces.end(), province);
	provinces.erase(position);
}

sf::Color PA::Country::Country::get_color()
{
	return color;
}
