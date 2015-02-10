#include "Country.hh"

#include <algorithm>

namespace PA {
namespace Country {

Country::Country(const sf::Color& color)
{
	this->color = color;
}

void Country::add_province(PA::Province::Province* province)
{
	provinces.push_back(province);
}

void Country::remove_province(PA::Province::Province* province)
{
	const auto position = std::find(provinces.begin(), provinces.end(), province);
	provinces.erase(position);
}

sf::Color Country::get_color()
{
	return color;
}

} // Country
} // PA
