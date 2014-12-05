#include "MapConverter.hh"

#include "Province.hh"

PA::Province::MapConverter::MapConverter()
{
	init_tiles();

	for (auto pair : tiles)
	{
		const auto color = pair.first;
		const auto pixels = pair.second;

		new PA::Province::Province;
	}
}

void PA::Province::MapConverter::init_tiles()
{
	provinces_image.loadFromFile("Resources/Map/Provinces.bmp");

	for (unsigned int x = 0; x < provinces_image.getSize().x; x++)
	{
		for (unsigned int y = 0; y < provinces_image.getSize().y; y++)
		{
			auto pixel_colour = provinces_image.getPixel(x, y);
			tiles[pixel_colour].push_back(sf::Vector2i(x, y));
		}
	}
}
