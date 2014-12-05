#include "Entity.hh"

#include <algorithm>

// Initialize static variables
std::vector<Mikan::Entity*> Mikan::Entity::entities;

Mikan::Entity::Entity()
{
	entities.push_back(this);
}

Mikan::Entity::~Entity()
{
	const auto position = std::find(entities.begin(), entities.end(), this);
	entities.erase(position);
}
