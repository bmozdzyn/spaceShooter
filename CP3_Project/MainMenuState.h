#pragma once
#include "State.h"
#include <optional>
class MainMenuState : public State
{
	sf::RectangleShape background;

	void initBackground();

	sf::Event sfEvent;

	void initButtons();
	void renderButtons();
	void updateButtons();


public:
	MainMenuState(sf::RenderWindow& window, std::stack<State::ptr>& states);
	virtual ~MainMenuState();


	void update();
	void render();

};

