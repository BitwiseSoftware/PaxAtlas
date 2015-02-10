#pragma once

#include <vector>
#include "../Province/Province.hh"

namespace PA
{
	namespace Country
	{
		class Country
		{
		public:
			Country(const sf::Color& color);

			void add_province(Province::Province* province);
			void remove_province(Province::Province* province);

			sf::Color get_color();

		private:
			std::vector<Province::Province*> provinces;

			sf::Color color;
		};
	}
}
