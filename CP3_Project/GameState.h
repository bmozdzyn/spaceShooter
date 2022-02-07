#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <time.h>
#include "State.h"
#include "Player.h"
#include "Bullet.h"
#include "BlueAlien.h"
#include "RedAlien.h"
#include "YellowAlien.h"
//#include <vld.h>

class GameState : public State
{
private:
	Player player;

	std::vector<Bullet> playerBullets;
	std::vector<Bullet> alienBullets;

	std::vector<Entity::ptr> aliens;

	bool playerWon;
	bool playerLoose;

	void initVariables();
	void initPlayer();
	void initEnemies();
	void initFont();

	sf::Texture all, player_text;
	sf::Font font;
	sf::Text text;

	sf::Time elapsedTime;
	sf::Time time;
	sf::Clock clock;

public:
	GameState(sf::RenderWindow& window, std::stack<State::ptr>& states);
	virtual ~GameState();

	void updateInput();
	void updateEnemyBullet();
	void updatePlayerBullet();
	void updateCombat();
	void updateText();
	void updateWinLoose();
	void update();
	void render();
};

