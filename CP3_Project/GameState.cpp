#include "GameState.h"
#include <random>
#include <typeinfo>

template <typename T>
 T getRandom(T lower, T upper) {
	static std::random_device random{};
	static std::default_random_engine engine{ random() };

	std::uniform_int_distribution dist{ static_cast<int>(lower), static_cast<int>(upper) };
	return static_cast<T>(dist(engine));
};


GameState::GameState(sf::RenderWindow& window, std::stack<State::ptr>& states)
	: State(window, states), player(player_text, sf::Vector2f(window.getSize()))
{
	all.loadFromFile("../textures/everything.png");
	player_text.loadFromFile("../textures/player.png");
	initVariables();
	initPlayer();
	initEnemies();
	initFont();
}

GameState::~GameState()
{
	playerBullets.clear();
	alienBullets.clear();
	aliens.clear();
}

void GameState::initVariables()
{
	playerWon = 0;
	playerLoose = 0;
}

void GameState::initPlayer()
{

}

void GameState::initEnemies()
{
	for (int i = 1; i < 17; i++)
	{
		auto alien = std::make_unique<BlueAlien>(all, sf::Vector2f(257 + 50 * i, 400));
		aliens.push_back(std::move(alien));
	}

	for (int i = 1; i < 17; i++)
	{
		auto alien = std::make_unique<RedAlien>(all, sf::Vector2f(257 + 50 * i, 350));
		aliens.push_back(std::move(alien));
	}

	for (int i = 1; i < 17; i++)
	{
		auto alien = std::make_unique<YellowAlien>(all, sf::Vector2f(257 + 50 * i, 300));
		aliens.push_back(std::move(alien));
	}
}

void GameState::initFont()
{
	font.loadFromFile("../fonts/font123.ttf");
	text.setFont(font);
	text.setCharacterSize(32);
	//text.setColor(sf::Color::White);

	text.setString("HP: " + std::to_string(player.currentHP()));
	text.setPosition(100, 900);
}

void GameState::updateInput()
{
	//player movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		player.move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		player.move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		player.move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		player.move(0.f, 1.f);

	//shooting
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player.canAttack())
	{
		playerBullets.emplace_back(all, player.getPosition(), player.dealDamage());
		playerBullets.back().setDirection(sf::Vector2f(0, -1));
	}
}

void GameState::updateEnemyBullet()
{
	time = sf::milliseconds(400);
	elapsedTime += clock.restart();

	while (elapsedTime >= time)
	{

		if (!aliens.empty())
		{
			int i = getRandom<int>(0, (int)(aliens.size() - 1));
			if (aliens[i]->canAttack())
			{
				alienBullets.emplace_back(all, aliens[i]->getPosition(), aliens[i]->dealDamage());
				alienBullets.back().setDirection(sf::Vector2f(0, 1));
			}
		}
		elapsedTime -= time;
	}
}

void GameState::updatePlayerBullet()
{
	int counter = 0;

	for (auto&& enemy : aliens)
		enemy->update(1.f / 60.f);

	for (auto& i : playerBullets)
	{
		i.update(1.f / 60.f);
		++counter;
	}

	for (auto& i : alienBullets)
	{
		i.update(1.f / 60.f);
		++counter;
	}
}

void GameState::updateCombat()
{
	//alien removing
	for (size_t k = 0; k < playerBullets.size(); k++)
	{
		for (int i = 0; i < aliens.size(); i++)
		{
			//std::cout << "i: " << i << "\tk:" << k << "\n";
			if (playerBullets[k].getBounds().intersects(aliens[i]->getBounds()))
			{
				aliens[i]->receiveDamage(playerBullets[k].getDamage());
				playerBullets.erase(playerBullets.begin() + k);
				k--;

				break;
				//std::cout << "blueAlien size: " << blueAlien.size() << std::endl;
			}
		}
	}

	for (int i = 0; i < aliens.size(); i++)
		if (!aliens[i]->isAlive())
		{
			aliens.erase(aliens.begin() + i);
			i--;
		}

	//player got hit by enemy
	for (size_t k = 0; k < alienBullets.size(); k++)
	{
		if (alienBullets[k].getBounds().intersects(player.getBounds()))
		{
			player.updateHP(alienBullets[k].getDamage());
			alienBullets.erase(alienBullets.begin() + k);
			k--;
		}
	}
}

void GameState::updateText()
{
	text.setString("HP: " + std::to_string(player.currentHP()));
}

void GameState::updateWinLoose()
{
	if (aliens.size() <= 0)
	{
		playerWon = 1;
		text.setCharacterSize(100);
		text.setString("You win");
		text.setPosition(420, 450);
	}
	if (player.currentHP() <= 0)
	{
		text.setCharacterSize(100);
		text.setString("You lose");
		text.setPosition(420, 400);
		playerLoose = 1;
	}

}

void GameState::update()
{
	//updateEvents();
	updateInput();
	updateEnemyBullet();
	updatePlayerBullet();
	player.update(0.5f); //cooldown update
	updateCombat();
	updateText();
	updateWinLoose();
}

void GameState::render()
{

	//draw all the things
	if (playerWon == 0 && playerLoose == 0)
	{
		window.draw(player);

		//render bullets
		for (auto& i : playerBullets)
		{
			window.draw(i);
		}

		for (auto& i : alienBullets)
		{
			window.draw(i);
		}

		//render enemies
		for (auto& i : aliens)
		{
			window.draw(*i);
		}
	}

	window.draw(text);
}
