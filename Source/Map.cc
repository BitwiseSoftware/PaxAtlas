#include "Map.hh"

#include "Mikan\Engine.hh"

PA::Map::Map()
{
	texture.loadFromFile("Resources/Map/Provinces.bmp");
	sprite.setTexture(texture);
	sprite.scale(10, 10);
}

void PA::Map::tick(const float delta_seconds)
{
	Mikan::Engine::terrain_layer.draw(sprite);
}
