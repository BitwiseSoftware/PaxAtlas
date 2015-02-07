#include "CountryLoader.hh"

#include "Country.hh"
#include "../Province/Province.hh"

PA::Country::CountryLoader::CountryLoader()
{
	load_json(Mikan::Engine::ROOT_DIR + "Information/countries.json");

	for (const auto& country_json : root["countries"])
	{
		const int red = country_json["colour"]["r"].asInt();
		const int green = country_json["colour"]["g"].asInt();
		const int blue = country_json["colour"]["b"].asInt();
		const sf::Color colour(red, green, blue);

		auto country = new PA::Country::Country(colour);
		for (const auto& province_json : country_json["provinces"])
		{
			int province_id = province_json.asInt();
			auto found = std::find_if(Mikan::Entity::entities.begin(), Mikan::Entity::entities.end(), [province_id](Mikan::Entity* entity)
			{
				auto province = (PA::Province::Province*)entity;
				return province->id == province_id;
			});
			auto province = (PA::Province::Province*)*found;
			country->add_province(province);
		}
	}
}
