#pragma once

#include <SFML\Graphics.hpp>

#include "..\Mikan\Entity.hh"
#include <vector>

namespace PA {
	namespace Province {
		class Province : Mikan::Entity
		{
		public:
			Province(std::vector<sf::Vector2f> points, sf::Vector2f position);

			void tick(float delta_seconds) override;

			std::string name;

			sf::ConvexShape convex;

		private:
			sf::Font font;
			sf::Text name_text;

			void configure_display_name();
		};
	}
}
