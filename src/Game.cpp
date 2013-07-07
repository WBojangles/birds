#include "../include/Game.hpp"

brd::Game::Game()
{
	SHE::StateManager::window.create(sf::VideoMode(800, 600), "birds", sf::Style::Titlebar | sf::Style::Close);
	//SHE::StateManager::window.create(sf::VideoMode(1440, 900), "Sailing the Seas of Sick", sf::Style::Fullscreen);
	SHE::StateManager::window.setMouseCursorVisible(true);
	SHE::StateManager::window.setFramerateLimit(60);

	// Player setup
	SHE::InputManager::setPlayers(1);
	SHE::InputManager::setJoystick(1, 0);
	// Bind keys
	SHE::InputManager::bind(1, "quit", sf::Keyboard::F4);
	SHE::InputManager::bind(1, "start", sf::Keyboard::Return);
	SHE::InputManager::bind(1, "up", sf::Keyboard::Up);
	SHE::InputManager::bind(1, "down", sf::Keyboard::Down);
	SHE::InputManager::bind(1, "left", sf::Keyboard::Left);
	SHE::InputManager::bind(1, "right", sf::Keyboard::Right);
	SHE::InputManager::bind(1, "start", sf::Keyboard::Z);
	SHE::InputManager::bind(1, "start", sf::Keyboard::X);
	SHE::InputManager::bind(1, "start", sf::Keyboard::Space);
	// Joystick
	SHE::InputManager::setThreshold(1, sf::Joystick::X, 60.f);
	SHE::InputManager::setThreshold(1, sf::Joystick::Y, 60.f);
	SHE::InputManager::bind(1, "start", 5);
	SHE::InputManager::bind(1, "up", sf::Joystick::Y, false);
	SHE::InputManager::bind(1, "down", sf::Joystick::Y, true);
	SHE::InputManager::bind(1, "left", sf::Joystick::X, false);
	SHE::InputManager::bind(1, "right", sf::Joystick::X, true);
	SHE::InputManager::bind(1, "start", 0);

	SHE::StateManager::create("Title", std::tr1::shared_ptr<SHE::State>(new brd::Title));
	SHE::StateManager::set("Title");
}

bool brd::Game::running()
{
	return SHE::StateManager::window.isOpen();
}

void brd::Game::update()
{
	// Time since last frame
	sf::Time frametime = delta.restart();

	// Events
	sf::Event E;
	while (SHE::StateManager::window.pollEvent(E))
	{
		switch (E.type)
		{
			case sf::Event::Closed:
				SHE::StateManager::window.close();
				break;
			default:
				break;
		}

		SHE::StateManager::events(E);
	}

	if (SHE::InputManager::check(1, "quit")) SHE::StateManager::window.close();
	if (SHE::StateManager::quit) SHE::StateManager::window.close();

	SHE::StateManager::update(frametime.asSeconds());

	draw();
}

void brd::Game::draw()
{
	SHE::StateManager::window.clear();
	SHE::StateManager::draw();
	SHE::StateManager::window.display();
}
