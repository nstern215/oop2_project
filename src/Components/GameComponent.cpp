#include "Components/GameComponent.h"

GameComponent::GameComponent(void (Controller::* changeModeFunc)(Mode, Metadata), int windowHeight, Controller* controller):
	m_tower(std::make_unique<Tower>(windowHeight))
{
	m_changeModeFunc = changeModeFunc;
	m_controller = controller;
}

void GameComponent::active(Metadata& metadata)
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
}

void GameComponent::eventHandler(sf::RenderWindow& window, sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyReleased:
		if (event.key.code == sf::Keyboard::Key::Add)
			m_tower->increseSpeed();
		break;
	}
	
	updateView();
}
