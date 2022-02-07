#include "Game.h"

Game::Game()
	: window(sf::VideoMode(1400, 1000), "Game", sf::Style::Close)
{
	initVariables();
	initWindow();
	initStates();
}

Game::~Game()
{
	while (!states.empty())
	{
		states.pop();
	}

}

void Game::initWindow()
{
	window.setFramerateLimit(60);

}

void Game::initVariables()
{
	windowHeight = 1000;
	windowWidth = 1400;
}


void Game::initStates()
{
	auto menu = std::make_unique<MainMenuState>(window, states);
	states.push(std::move(menu));
}

void Game::update()
{
	updateSFMLEvents();



	if (!this->states.empty())
		this->states.top()->update();
	else
	{
		try
		{
			throw std::runtime_error("State stack empty!\n");
		}
		catch (std::runtime_error& e)
		{
			std::cout << e.what();
			window.close();
		}
	}
}

void Game::updateSFMLEvents()
{
	//closing the window
	sf::Event sfEvent;
	while (window.pollEvent(sfEvent))
	{
		if (sfEvent.Event::type == sf::Event::Closed)
			window.close();
		if (sfEvent.Event::KeyPressed && sfEvent.Event::key.code == sf::Keyboard::Escape)
			window.close();
	}
}

void Game::render()
{
	window.clear();

	if (!this->states.empty())
		this->states.top()->render();
	else
	{
		try
		{
			throw std::runtime_error("State stack empty!\n");
		}
		catch (std::runtime_error& e)
		{
			std::cout << e.what();
			window.close();
		}
	}


	window.display();
}

void Game::run()
{
	while (window.isOpen()) {
		update();
		render();



		if (!states.empty() && states.top()->quit()) {
			states.pop();
			if (states.empty())
				window.close();
		}
	}
}



