#include "Entity.hh"

#include <algorithm>

namespace Mikan {

// Initialize static variables
std::vector<Entity*> Entity::entities;

Entity::Entity()
{
	entities.push_back(this);
}

Entity::~Entity()
{
	const auto position = std::find(entities.begin(), entities.end(), this);
	entities.erase(position);
}

} // namespace Mikan
