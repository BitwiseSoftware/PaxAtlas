#include "Province.hh"

#include "..\Mikan\Engine.hh"

PA::Province::Province::Province(const std::vector<sf::Vector2f> points, const sf::Vector2f position)
{
	convex.setPointCount(points.size());

	for (unsigned int i = 0; i < points.size(); i++)
	{
		convex.setPoint(i, points[i]);
	}
	convex.setFillColor(sf::Color::Blue);
}

void PA::Province::Province::configure_display_name()
{
	sf::FloatRect textRect = name_text.getLocalBounds();
	name_text.setOrigin(
		textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f
	);
	name_text.setPosition(sf::Vector2f(100, 100));

	font.loadFromFile("Resources/Fonts/OpenSans-Regular.ttf");
	name_text.setString("U wut Bruv?");
	name_text.setCharacterSize(24);
	name_text.setFont(font);
	name_text.setColor(sf::Color::Yellow);
	name_text.setStyle(sf::Text::Bold);
}

void PA::Province::Province::tick(const float delta_seconds)
{
	Mikan::Engine::terrain_layer.draw(convex);
	Mikan::Engine::terrain_layer.draw(name_text);
}
