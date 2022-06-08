#include "Controller.h"

#include "Components/GameComponent.h"
#include "Components/HighscoreComponent.h"
#include "Components/MenuComponent.h"
#include "Components/TutorialComponent.h"
#include "Components/WelcomeComponent.h"

#define GAME_TITLE "Icy Tower"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

Controller::Controller():
	m_activeMode(SCORE_BOARD),
	m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_TITLE, sf::Style::Close)
{
	buildComponents();

	m_window.setFramerateLimit(90);
}

void Controller::run()
{
	m_components[m_activeMode]->active();
	
	while (m_window.isOpen())
	{
		m_window.clear();

		for (auto event = sf::Event{}; m_window.pollEvent(event); )
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
				default:
					m_components[m_activeMode]->eventHandler(m_window, event);
					break;
			}
		}

		m_components[m_activeMode]->updateView();
		m_components[m_activeMode]->draw(m_window);

		m_window.display();
	}
}

void Controller::buildComponents()
{
	m_components.insert({ GAME,				std::make_unique<GameComponent>(&Controller::changeMode, WINDOW_HEIGHT, this) });
	m_components.insert({ OPENING_SCREEN,	std::make_unique<WelcomeComponent>(&Controller::changeMode, this) });
	m_components.insert({ TUTORIAL,			std::make_unique<TutorialComponent>(&Controller::changeMode, this) });
	m_components.insert({ MENU,				std::make_unique<MenuComponent>(&Controller::changeMode, this, m_window.getSize()) });
	m_components.insert({SCORE_BOARD,		std::make_unique<HighscoreComponent>(&Controller::changeMode, this, m_window.getSize(), m_HIGH_SCORE_FILE)});
}

void Controller::changeMode(Mode mode, std::map<std::string, std::string> metadata)
{
	if (m_components.count(mode) == 0)
		return;

	m_activeMode = mode;
	m_components[mode]->active(metadata);
}
