#pragma once
#include <stack>
#include <map>
#include "SFML/Graphics.hpp"
#include "Gui.h"

class State
{
public:
	using ptr = std::unique_ptr<State>;
protected:


	sf::RenderWindow& window;
	std::stack<State::ptr>& states;
	sf::Vector2f mousePos;

	sf::Event sfEvent;

	std::map<std::string, Gui::ptr> buttons;

	float keytime, keytimeMax;

	float dt;
	sf::Clock dtClock;

	void updateMousePosition();
	/*void updateDT();
	void updateKeytime();
	const bool getKeytime();*/

	bool wantsQuit{ false };



public:
	State(sf::RenderWindow& window, std::stack<State::ptr>& states);
	virtual ~State();

	virtual void render() = 0;
	virtual void update() = 0;

	bool quit() const { return wantsQuit; };
};

