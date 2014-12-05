#include "ProvinceLoader.hh"

#include "Province.hh"

PA::Province::ProvinceLoader::ProvinceLoader()
{
	load_json("Information/provinces.json");

	for (auto province : root["provinces"])
	{
		std::vector<sf::Vector2f> points;
		for (auto point : province["points"])
		{
			points.push_back(sf::Vector2f(point[0].asFloat(), point[1].asFloat()));
		}
		sf::Vector2f position;
		position.x = province["position"]["x"].asFloat();
		position.y = province["position"]["y"].asFloat();
		//new PA::Province::Province(points, position);
	}
}
