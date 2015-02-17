#include "Mikan/Engine.hh"

#include "Province/ProvinceLoader.hh"
#include "Country/CountryLoader.hh"
#include "Army/Loader.hh"
#include "Map.hh"
#include "FrameRate.hh"

int main()
{
	const PA::Province::ProvinceLoader province_loader;
	const PA::Country::CountryLoader country_loader;
	const PA::Army::Loader army_loader;
        const PA::Map map;

	const PA::FrameRate frame_rate;

	Mikan::Engine engine;
	engine.run();

	return 0;
}
