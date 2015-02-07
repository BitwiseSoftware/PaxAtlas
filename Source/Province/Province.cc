#include "Province.hh"

#include "../Mikan/Engine.hh"

PA::Province::Province::Province(const unsigned int id)
{
	this->id = id;
}

void PA::Province::Province::configure_display_name()
{
	font.loadFromFile(Mikan::Engine::ROOT_DIR + "Resources/Fonts/OpenSans-Regular.ttf");
	name_text.setString("U wut Bruv?");
	name_text.setCharacterSize(24);
	name_text.setFont(font);
	name_text.setColor(sf::Color::Yellow);
	name_text.setStyle(sf::Text::Bold);
}

void PA::Province::Province::tick(const float delta_seconds)
{
	Mikan::Engine::terrain_layer.draw(shape);
	Mikan::Engine::terrain_layer.draw(name_text);
}

void PA::Province::Province::set_shape(const sf::ConvexShape& value)
{
	shape = value;
}
