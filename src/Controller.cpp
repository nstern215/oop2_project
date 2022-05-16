#include "Controller.h"

#include "Components/GameComponent.h"

#define GAME_TITLE "IcyTower"
#define WIDTH 800
#define HEIGHT 800

Controller::Controller():
	m_activeMode(GAME),
	m_window(sf::VideoMode(WIDTH, HEIGHT), GAME_TITLE, sf::Style::Close)
{
	buildComponents();
}

void Controller::run()
{
	m_components[m_activeMode]->active();
	
	while (m_window.isOpen())
	{
		m_window.display();

		for (auto event = sf::Event{}; m_window.pollEvent(event); )
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			}
		}
	}
}

void Controller::buildComponents()
{
	m_components.insert({ GAME, std::make_unique<GameComponent>(&Controller::changeMode) });
}

void Controller::changeMode(Mode mode, std::map<std::string, std::string> metadata)
{
	if (m_components.count(mode) == 0)
		return;

	m_activeMode = mode;
	m_components[mode]->active(metadata);
}
