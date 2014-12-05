#include "MapConverter.hh"

#include "Province.hh"

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
			if (pixel_colour != sf::Color(255, 255, 255)) {
				tiles[pixel_colour].push_back(sf::Vector2f(x, y));
			}
		}
	}

	for (auto& pair : tiles)
	{
		auto& pixels = pair.second;
		pixels = convex_hull(pixels);
	}
}

void PA::Province::MapConverter::create_shape()
{
	for (const auto& pair : tiles)
	{
		const auto& color = pair.first;
		const auto& pixels = pair.second;

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

// http://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain#C.2B.2B
int PA::Province::MapConverter::cross(const sf::Vector2f &O, const sf::Vector2f &A, const sf::Vector2f &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

//http://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain#C.2B.2B
std::vector<sf::Vector2f> PA::Province::MapConverter::convex_hull(std::vector<sf::Vector2f> pixels)
{
	int n = pixels.size(), k = 0;
	std::vector<sf::Vector2f> h(2 * n);

	// Build lower hull
	for (int i = 0; i < n; ++i)
	{
		while (k >= 2 && cross(h[k - 2], h[k - 1], pixels[i]) <= 0) k--;
		h[k++] = pixels[i];
	}

	// Build upper hull
	for (int i = n - 2, t = k + 1; i >= 0; i--)
	{
		while (k >= t && cross(h[k - 2], h[k - 1], pixels[i]) <= 0) k--;
		h[k++] = pixels[i];
	}

	h.resize(k);
	return h;
}
