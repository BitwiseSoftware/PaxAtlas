#pragma once

#include <vector>

namespace Mikan {
	class Entity
	{
	public:
		Entity();

		virtual void tick(float delta_seconds) = 0;

		static std::vector<Entity*> entities;

	protected:
		~Entity();
	};
}
