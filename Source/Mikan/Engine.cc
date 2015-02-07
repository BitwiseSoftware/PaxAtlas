#include "Engine.hh"

#include "Debug.hh"
#include "Entity.hh"

// Initialize static variables
std::unique_ptr<sf::RenderWindow>  Mikan::Engine::window;
sf::RenderTexture Mikan::Engine::terrain_layer;
sf::RenderTexture Mikan::Engine::ui_layer;
const std::string Mikan::Engine::ROOT_DIR;

Mikan::Engine::Engine()
{
	paused = false;

	init_window();
	init_layers();

	Debug();
}

void Mikan::Engine::run()
{
	sf::Clock delta_clock;

	while (window->isOpen())
	{
		const float delta_seconds = delta_clock.restart().asSeconds();

		control_window(delta_seconds);
		if (paused)
		{
			continue;
		}
		control_camera(delta_seconds);

		terrain_layer.clear(sf::Color(0, 0, 0, 0));
		ui_layer.clear(sf::Color(0, 0, 0, 0));
		window->clear(sf::Color::Black);

		for (auto entity : Entity::entities)
		{
			entity->tick(delta_seconds);
		}

		window->setView(camera);
		terrain_layer.display();
		sf::Sprite terrain_sprite(terrain_layer.getTexture());
		window->draw(terrain_sprite);

		window->setView(window->getDefaultView());
		ui_layer.display();
		sf::Sprite ui_sprite(ui_layer.getTexture());
		window->draw(ui_sprite);

		window->display();
	}
}

void Mikan::Engine::init_window()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 16;

	window.reset(new sf::RenderWindow(sf::VideoMode(1024, 768), "Pax Atlas", sf::Style::Default, settings));
	window->setFramerateLimit(60);
}

void Mikan::Engine::init_layers()
{
	terrain_layer.create(5000, 5000);
	ui_layer.create(5000, 5000);
}

void Mikan::Engine::control_camera(const float delta_seconds)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		camera.move(sf::Vector2f(0, -500 * delta_seconds));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		camera.move(sf::Vector2f(-500 * delta_seconds, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		camera.move(sf::Vector2f(0, 500 * delta_seconds));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		camera.move(sf::Vector2f(500 * delta_seconds, 0));
	}
}

void Mikan::Engine::control_window(float delta_seconds)
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();

		case sf::Event::LostFocus:
			paused = true;
			break;

		case sf::Event::GainedFocus:
			paused = false;
			break;

		// camera zoom
		case sf::Event::MouseWheelMoved:
			if (event.mouseWheel.delta > 0)
			{
				camera.zoom(0.9f);
			}
			else
			{
				camera.zoom(1.1f);
			}

		default:
			break;
		}
	}
}
