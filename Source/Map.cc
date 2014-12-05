#include "Map.hh"

#include "Mikan\Engine.hh"

PA::Map::Map()
{
	sprite.scale(10, 10);
}

void PA::Map::tick(const float delta_seconds)
{
	Mikan::Engine::terrain_layer.draw(sprite);
}
