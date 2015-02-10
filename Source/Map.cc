#include "Map.hh"

#include "Mikan/Engine.hh"

namespace PA {

Map::Map()
{
	sprite.scale(10, 10);
}

void Map::tick(const float delta_seconds)
{
	Mikan::Engine::terrain_layer.draw(sprite);
}

} // namespace PA
