#include "Mikan\Engine.hh"

#include "Province\ProvinceLoader.hh"
#include "Country\CountryLoader.hh"
#include "Map.hh"
#include "FrameRate.hh"

int main()
{
	PA::Province::ProvinceLoader province_loader;
	PA::Country::CountryLoader country_loader;
	PA::Map map;

	PA::FrameRate frame_rate;

	Mikan::Engine engine;
	engine.run();

	return 0;
}
