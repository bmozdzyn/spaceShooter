#include "MainMenuState.h"
#include "GameState.h"

MainMenuState::MainMenuState(sf::RenderWindow& window, std::stack<State::ptr>& states)
	: State(window, states)
{
	initBackground();
	initButtons();
}

MainMenuState::~MainMenuState()
{
	std::cout << "MainMenuState destructor!\n";

}

void MainMenuState::initBackground()
{
	background.setSize((sf::Vector2f)window.getSize());
	background.setFillColor(sf::Color::Black);
}

void MainMenuState::initButtons()
{
	this->buttons["START"] = std::make_unique<Gui>(sf::Vector2f(400, 150), sf::Vector2f(350, 100), sf::Color::White, std::string("START"), 50, sf::Color::Black, sf::Color::Yellow);
	this->buttons["EXIT"] = std::make_unique<Gui>(sf::Vector2f(400, 150), sf::Vector2f(350, 600), sf::Color::White, std::string("EXIT"), 50, sf::Color::Black, sf::Color::Yellow);
}

void MainMenuState::renderButtons()
{
	for (auto&& it : buttons)
		it.second->render(window);
}

void MainMenuState::updateButtons()
{
	if (buttons["START"]->isButtonPressed(mousePos)) {
		auto game = std::make_unique<GameState>(window, states);
		states.emplace(std::move(game));
	}

	if (buttons["EXIT"]->isButtonPressed(mousePos))
		wantsQuit = true;
}

void MainMenuState::update()
{
	updateMousePosition();
	//updateDT();
	updateButtons();
}

void MainMenuState::render()
{
	window.draw(background);
	renderButtons();
}
