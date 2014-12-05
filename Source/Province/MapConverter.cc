#include "MapConverter.hh"

#include "Province.hh"
#include <iostream>

PA::Province::MapConverter::MapConverter()
{
	init_tiles();
	create_shape();
}

void PA::Province::MapConverter::init_tiles()
{
	provinces_image.loadFromFile("Resources/Map/Provinces.bmp");

	for (unsigned int x = 0; x < provinces_image.getSize().x; x++)
	{
		for (unsigned int y = 0; y < provinces_image.getSize().y; y++)
		{
			auto pixel_colour = provinces_image.getPixel(x, y);
			tiles[pixel_colour].push_back(sf::Vector2f(x, y));
		}
	}
}

void PA::Province::MapConverter::create_shape()
{
	for (const auto& pair : tiles)
	{
		const auto color = pair.first;
		const auto pixels = pair.second;

		sf::ConvexShape shape;
		shape.setPointCount(pixels.size());
		shape.setFillColor(color);

		for (unsigned int i = 0; i < pixels.size(); i++)
		{
			shape.setPoint(i, pixels[i]);
		}

		auto province = new PA::Province::Province;
		province->set_shape(shape);
	}
}
