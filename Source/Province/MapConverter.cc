#include "MapConverter.hh"

#include "Province.hh"

PA::Province::MapConverter::MapConverter()
{
	init_tiles();
	convert_to_convex();
}

void PA::Province::MapConverter::init_tiles()
{
	provinces_image.loadFromFile(Mikan::Engine::ROOT_DIR + "Resources/Map/Provinces.bmp");

	for (unsigned int x = 0; x < provinces_image.getSize().x; x++)
	{
		for (unsigned int y = 0; y < provinces_image.getSize().y; y++)
		{
			auto pixel_colour = provinces_image.getPixel(x, y);
			if (pixel_colour != sf::Color(255, 255, 255)) {
				tiles[pixel_colour].push_back(sf::Vector2f(x, y));
			}
		}
	}
}

void PA::Province::MapConverter::convert_to_convex()
{
	for (auto& pair : tiles)
	{
		auto& pixels = pair.second;
		std::vector<sf::Vector2f> new_pixels;
		sf::Vector2f last_pixel(pixels[0]);
		while (true)
		{
			auto found = std::find_if(pixels.begin(), pixels.end(), [last_pixel](const sf::Vector2f& pixel)
			{
				bool same_row_ahead = pixel == last_pixel + sf::Vector2f(1, 0);
				bool same_column_ahead = pixel == last_pixel + sf::Vector2f(0, 1);
				bool same_row_behind = pixel == last_pixel - sf::Vector2f(1, 0);
				bool same_column_behind = pixel == last_pixel - sf::Vector2f(0, 1);
				if (same_row_ahead || same_column_ahead || same_row_behind || same_column_behind)
				{
					return true;
				}
				else
				{
					return false;
				}
			});
			if (found == pixels.end())
			{
				break;
			}

			new_pixels.push_back(*found);
			last_pixel = *found;
			pixels.erase(found);
		}
		pixels = new_pixels;
	}
}
