#include "Game.h"

void Game::initVariables()
{
	windowHeight = 1000;
	windowWidth = 1400;
}

void Game::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Game", sf::Style::Close);
	window->setFramerateLimit(60);
}

void Game::initPlayer()
{
	player = new Player(player_text, sf::Vector2f(window->getSize()));
}

void Game::initEnemies()
{
	for (int i = 1; i < 17; i++)
	{
		blueAlien.push_back(new BlueAlien(all, sf::Vector2f(257 + 50 * i, 400)));
	}

	for (int i = 1; i < 17; i++)
	{
		redAlien.push_back(new RedAlien(all, sf::Vector2f(257 + 50 * i, 350)));
	}

	for (int i = 1; i < 17; i++)
	{
		yellowAlien.push_back(new YellowAlien(all, sf::Vector2f(257 + 50 * i, 300)));
	}
}

Game::Game()
{
	all.loadFromFile("../textures/everything.png");
	player_text.loadFromFile("../textures/player.png");
	initVariables();
	initWindow();
	initPlayer();
	initEnemies();
}

Game::~Game()
{
	delete window;
	delete player;

	std::cout << "GAME\tDTOR\n";
	//delete player bullets

	playerBullets.clear();
}

void Game::updateEvents()
{
	//closing the window
	sf::Event sfEvent;
	while (window->pollEvent(sfEvent))
	{
		if (sfEvent.Event::type == sf::Event::Closed)
			window->close();
		if (sfEvent.Event::KeyPressed && sfEvent.Event::key.code == sf::Keyboard::Escape)
			window->close();
	}
}

void Game::updateInput()
{
	//player movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		player->move(0.f, 1.f);

	//shooting
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player->canAttack())
	{
		playerBullets.emplace_back(all, player->getPosition());
		playerBullets.back().setDirection(sf::Vector2f(0,-1));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		for (int i = 0; i < blueAlien.size(); i++)
		{
			if (blueAlien[i]->canAttack())
			{
				blueAlienBullets.emplace_back(all, blueAlien[i]->getPosition());
				blueAlienBullets.back().setDirection(sf::Vector2f(0, 1));
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		for (int i = 0; i < redAlien.size(); i++)
		{
			if (redAlien[i]->canAttack())
			{
				redAlienBullets.emplace_back(all, redAlien[i]->getPosition());
				redAlienBullets.back().setDirection(sf::Vector2f(0, 1));
			}
		}
	}

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		for (int i = 0; i < yellowAlien.size(); i++)
		{
			if (yellowAlien[i]->canAttack())
			{
				yellowAlienBullets.emplace_back(all, yellowAlien[i]->getPosition());
				yellowAlienBullets.back().setDirection(sf::Vector2f(0, 1));
			}
		}
	}*/
}

void Game::updateEnemyBullet()
{
	time = sf::milliseconds(400);
	elapsedTime += clock.restart();

	while (elapsedTime >= time)
	{
		int i, j;
		j = rand() % 3;
		if (j == 0)
		{
			i = rand() % yellowAlien.size();
			if (yellowAlien[i]->canAttack())
			{
				yellowAlienBullets.emplace_back(all, yellowAlien[i]->getPosition());
				yellowAlienBullets.back().setDirection(sf::Vector2f(0, 1));
			}
		}
		else if (j == 1)
		{
			i = rand() % blueAlien.size();
			if (blueAlien[i]->canAttack())
			{
				blueAlienBullets.emplace_back(all, blueAlien[i]->getPosition());
				blueAlienBullets.back().setDirection(sf::Vector2f(0, 1));
			}
		}
		else if (j == 2)
		{
			i = rand() % redAlien.size();
			if (redAlien[i]->canAttack())
			{
				redAlienBullets.emplace_back(all, redAlien[i]->getPosition());
				redAlienBullets.back().setDirection(sf::Vector2f(0, 1));
			}
		}
		elapsedTime -= time;
	}
}

void Game::updatePlayerBullet()
{
	int counter = 0;

	for (auto&& enemy : blueAlien)
		enemy->update(1.f / 60.f);

	for (auto&& enemy : redAlien)
		enemy->update(-1.f / 60.f);

	for (auto&& enemy : yellowAlien)
		enemy->update(1.f / 60.f);

	for (auto& i : playerBullets)
	{
		i.update(1.f/60.f);
		++counter;
	}

	for (auto& i : blueAlienBullets)
	{
		i.update(1.f / 60.f);
		++counter;
	}

	for (auto& i : redAlienBullets)
	{
		i.update(1.f / 60.f);
		++counter;
	}

	for (auto& i : yellowAlienBullets)
	{
		i.update(1.f / 60.f);
		++counter;
	}
}

void Game::updateCombat()
{
	//blue alien removing
	for (int i = 0; i < blueAlien.size(); i++)
	{
		for (size_t k = 0; k < playerBullets.size(); k++)
		{
			//std::cout << "i: " << i << "\tk:" << k << "\n";
			if (playerBullets[k].getBounds().intersects(blueAlien[i]->getBounds()))
			{
				playerBullets.erase(playerBullets.begin() + k);
				blueAlien.erase(blueAlien.begin() + i);
				k--;
				i--;
			}
		}
	}

	//red alien removing
	for (int i = 0; i < redAlien.size(); i++)
	{
		for (size_t k = 0; k < playerBullets.size(); k++)
		{
			//std::cout << "i: " << i << "\tk:" << k << "\n";
			if (playerBullets[k].getBounds().intersects(redAlien[i]->getBounds()))
			{
				playerBullets.erase(playerBullets.begin() + k);
				redAlien.erase(redAlien.begin() + i);
				k--;
				i--;
			}
		}
	}

	//yellow alien removing
	for (int i = 0; i < yellowAlien.size(); i++)
	{
		for (size_t k = 0; k < playerBullets.size(); k++)
		{
			//std::cout << "i: " << i << "\tk:" << k << "\n";
			if (playerBullets[k].getBounds().intersects(yellowAlien[i]->getBounds()))
			{
				playerBullets.erase(playerBullets.begin() + k);
				yellowAlien.erase(yellowAlien.begin() + i);
				k--;
				i--;
			}
		}
	}

	//player removing
	for (size_t k = 0; k < blueAlienBullets.size(); k++)
	{
		if (blueAlienBullets[k].getBounds().intersects(player->getBounds()))
		{
			blueAlienBullets.erase(blueAlienBullets.begin() + k);
			std::cout << "Player got hit" << std::endl;
			k--;
		}
	}

}

void Game::update()
{
	updateEvents();
	updateInput();
	updateEnemyBullet();
	updatePlayerBullet();
	player->update(0.5f); //cooldown update
	updateCombat();
}

void Game::render()
{
	window->clear(); //clear old frames

	//draw all the things
	window->draw(*player);

	//render bullets
	for (auto i : playerBullets)
	{
		window->draw(i);
	}

	for (auto i : blueAlienBullets)
	{
		window->draw(i);
	}

	for (auto i : redAlienBullets)
	{
		window->draw(i);
	}

	for (auto i : yellowAlienBullets)
	{
		window->draw(i);
	}

	//render enemies
	for (auto i : blueAlien)
	{
		window->draw(*i);
	}

	for (auto i : redAlien)
	{
		window->draw(*i);
	}

	for (auto i : yellowAlien)
	{
		window->draw(*i);
	}

	window->display();
}

void Game::run()
{
	while (window->isOpen())
	{
		update();
		render();
	}
	
}
