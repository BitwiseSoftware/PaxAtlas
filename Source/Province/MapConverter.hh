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

		private:
			sf::Image provinces_image;
			std::unordered_map < sf::Color, std::vector<sf::Vector2f> > tiles;

			void init_tiles();
			void create_shape();

			// http://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain#C.2B.2B
			int cross(const sf::Vector2f &O, const sf::Vector2f &A, const sf::Vector2f &B);
			std::vector<sf::Vector2f> convex_hull(std::vector<sf::Vector2f> pixels);
		};
	}
}
