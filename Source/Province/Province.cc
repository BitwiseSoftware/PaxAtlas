#include "Province.hh"

#include "../Mikan/Engine.hh"
#include "../Country/Country.hh"

namespace PA {
namespace Province {

Province::Province(const unsigned int id) : owner(nullptr)
{
	this->id = id;
}

void Province::configure_display_name()
{
	font.loadFromFile(Mikan::Engine::ROOT_DIR + "Resources/Fonts/OpenSans-Regular.ttf");
	name_text.setString("U wut Bruv?");
	name_text.setCharacterSize(24);
	name_text.setFont(font);
	name_text.setColor(sf::Color::Yellow);
	name_text.setStyle(sf::Text::Bold);
}

void Province::tick(const float delta_seconds)
{
	Mikan::Engine::terrain_layer.draw(shape);
	Mikan::Engine::terrain_layer.draw(name_text);
}

void Province::set_shape(const sf::ConvexShape& value)
{
	shape = value;
}

void Province::set_owner(PA::Country::Country* owner)
{
	if (this->owner != nullptr)
	{
		this->owner->remove_province(this);
	}
	this->owner = owner;
	this->owner->add_province(this);
	shape.setFillColor(owner->get_color());
}

} // Province
} // PA
