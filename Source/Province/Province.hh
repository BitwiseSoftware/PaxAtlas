#pragma once

#include <SFML\Graphics.hpp>

#include "..\Mikan\Entity.hh"
#include <vector>

namespace PA {
	namespace Province {
		class Province : Mikan::Entity
		{
		public:
			Province();

			void tick(float delta_seconds) override;

			void set_shape(const sf::ConvexShape& value);

		private:
			sf::Font font;
			sf::Text name_text;
			std::string name;

			sf::ConvexShape shape;

			void configure_display_name();
		};
	}
}
