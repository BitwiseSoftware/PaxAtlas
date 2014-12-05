#include "Mikan\Engine.hh"

#include "Province\ProvinceLoader.hh"
#include "Province\MapConverter.hh"
#include "Map.hh"
#include "FrameRate.hh"

int main()
{
	//PA::ProvinceLoader province_loader;
	PA::Province::MapConverter map_converter;
	PA::Map map;

	PA::FrameRate frame_rate;

	Mikan::Engine engine;
	engine.run();

	return 0;
}
