#pragma once
#include "mainMenuState.h"

class Game {

	std::stack<State::ptr> states;
	sf::RenderWindow window;

	int windowWidth;
	int windowHeight;

	void initWindow();
	void initVariables();
	void initStates();

	void update();
	void updateSFMLEvents();

	void render();

public:

	Game();
	~Game();
	void run();
};

