#include "State.h"

State::State(sf::RenderWindow& window, std::stack<State::ptr>& states)
	: window(window), states(states)
{
	dt = 0.f;
	keytime = 0.f;
	keytimeMax = 25.f;
}

void State::updateMousePosition()
{
	mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
}
//
//void State::updateDT()
//{
//	this->dt = dtClock.restart().asSeconds();
//}
//
//void State::updateKeytime()
//{
//	if (keytime < keytimeMax)
//		keytime += 105.f * dt;
//}
//
//const bool State::getKeytime()
//{
//	if (this->keytime >= this->keytimeMax)
//	{
//		this->keytime = 0.f;
//		return true;
//	}
//	return false;
//}

State::~State()
{
	std::cout << "State destructor!\n";
}