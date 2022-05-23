#include "Components/GameComponent.h"

GameComponent::GameComponent(void (Controller::* changeModeFunc)(Mode, std::map<std::string, std::string>), int windowHeight):
	m_tower(std::make_unique<Tower>(windowHeight)),
	m_player(std::make_unique<Player>(windowHeight))
{
	m_changeModeFunc = changeModeFunc;
}

void GameComponent::active(std::map<std::string, std::string>& metadata)
{
	m_clock.restart();
	m_tower->play();
}

void GameComponent::updateView()
{
	const auto deltaTime = m_clock.restart().asSeconds();
	
	m_tower->move(deltaTime);
}


void GameComponent::draw(sf::RenderWindow& window)
{
	m_tower->draw(window);
	m_player->draw(window);
}

void GameComponent::eventHandler(sf::RenderWindow& window, sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyReleased:
		if (event.key.code == sf::Keyboard::Key::Add)
			m_tower->increseSpeed();
		if (event.key.code == sf::Keyboard::Key::Right)
			m_player->sideMove(0 , 1);
		break;
	}
	
	updateView();
}
