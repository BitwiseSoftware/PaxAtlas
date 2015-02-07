#include "ProvinceLoader.hh"

#include "Province.hh"
#include "MapConverter.hh"

PA::Province::ProvinceLoader::ProvinceLoader()
{
	PA::Province::MapConverter map_converter;
	load_json(Mikan::Engine::ROOT_DIR + "Information/provinces.json");

	for (auto province : root["provinces"])
	{
		const int red = province["colour"]["r"].asInt();
		const int green = province["colour"]["g"].asInt();
		const int blue = province["colour"]["b"].asInt();

		const sf::Color colour(red, green, blue);
		auto& pixels = map_converter.tiles[colour];

		sf::ConvexShape shape;
		shape.setPointCount(pixels.size());
		shape.setOutlineColor(sf::Color::Blue);
		shape.setOutlineThickness(1);

		for (unsigned int i = 0; i < pixels.size(); i++)
		{
			shape.setPoint(i, pixels[i]);
		}

		auto province_entity = new PA::Province::Province(province["id"].asInt());
		province_entity->set_shape(shape);
	}
}
