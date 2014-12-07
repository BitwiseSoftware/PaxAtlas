#pragma once

#include <SFML\Graphics.hpp>
#include <unordered_map>
#include <vector>

// Allow sf::Color unordered keys
namespace std {
	template <>
	struct hash<sf::Color>
	{
		std::size_t operator()(const sf::Color& key) const
		{
			using std::size_t;
			using std::hash;

			return (hash<int>()(key.r) + (hash<int>()(key.b)) + hash<int>()(key.b));
		}
	};
}

// Converts provinces map image to actual actual province location data
namespace PA {
	namespace Province {
		class MapConverter {
		public:
			MapConverter();

			std::unordered_map < sf::Color, std::vector<sf::Vector2f> > tiles;

		private:
			sf::Image provinces_image;

			void init_tiles();
			void convert_to_convex();
		};
	}
}
