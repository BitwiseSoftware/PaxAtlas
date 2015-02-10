#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

namespace Mikan {
	class Entity
	{
	public:
		Entity();

		virtual void tick(float delta_seconds) = 0;
		void render();

		static std::vector<Entity*> entities;

	protected:
		~Entity();
		sf::ConvexShape shape;
		sf::RenderTexture& get_layer();
	};
}
