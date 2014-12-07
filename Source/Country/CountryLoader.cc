#include "CountryLoader.hh"

#include "Country.hh"
#include "../Province/Province.hh"

PA::Country::CountryLoader::CountryLoader()
{
	load_json("Information/countries.json");

	for (const auto& country_json : root["countries"])
	{
		auto country = new PA::Country::Country;
		for (const auto& province_json : country_json["provinces"])
		{
			int province_id = province_json.asInt();
			auto& found = std::find_if(Mikan::Entity::entities.begin(), Mikan::Entity::entities.end(), [province_id](Mikan::Entity* entity)
			{
				auto province = (PA::Province::Province*)entity;
				if (province->id == province_id)
				{
					return true;
				}
				else
				{
					return false;
				}
			});
			auto province = (PA::Province::Province*)*found;
			country->add_province(province);
		}
	}
}
