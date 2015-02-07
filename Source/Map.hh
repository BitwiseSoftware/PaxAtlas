#pragma once

#include "Mikan/Entity.hh"
#include <SFML/Graphics.hpp>

namespace PA
{
	class Map : Mikan::Entity
	{
	public:
		Map();

		void tick(float delta_seconds) override;

	private:
		sf::Texture texture;
		sf::Sprite sprite;
	};
}
