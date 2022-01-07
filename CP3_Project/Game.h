#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <time.h>
#include "Player.h"
#include "Bullet.h"
#include "BlueAlien.h"
#include "RedAlien.h"
#include "YellowAlien.h"


class Game
{
private:
	sf::RenderWindow *window;
	Player* player;

	std::vector<Bullet> playerBullets;
	std::vector<Bullet> blueAlienBullets;
	std::vector<Bullet> redAlienBullets;
	std::vector<Bullet> yellowAlienBullets;


	std::vector<BlueAlien*> blueAlien;
	std::vector<RedAlien*> redAlien;
	std::vector<YellowAlien*> yellowAlien;

	int windowWidth;
	int windowHeight;

	void initVariables();
	void initWindow();
	void initPlayer();
	void initEnemies();

	sf::Texture all, player_text;

	sf::Time elapsedTime;
	sf::Time time;
	sf::Clock clock;

public:
	Game();
	~Game();

	void updateEvents();
	void updateInput();
	void updateEnemyBullet();
	void updatePlayerBullet();
	void updateCombat();
	void update();
	void render();

	void run();

};

