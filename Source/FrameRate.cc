#include "FrameRate.hh"

#include "Mikan\Engine.hh"
#include "Mikan\Debug.hh"
#include <sstream>
#include <string>

PA::FrameRate::FrameRate()
{
}

void PA::FrameRate::tick(const float delta_seconds)
{
	fps_incrementor++;
	if (fps_clock.getElapsedTime().asSeconds() >= 1.f) {
		current_fps = fps_incrementor;
		fps_incrementor = 0;
		fps_clock.restart();

		configure_text();
	}

	display_fps();
}

void PA::FrameRate::display_fps()
{
	Mikan::Debug::print_screen(configure_text());
}

std::string PA::FrameRate::configure_text()
{
	std::ostringstream convert;
	convert << current_fps;
	return std::string(convert.str());
}
