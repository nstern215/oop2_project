#include "Components/GameComponent.h"

GameComponent::GameComponent(void (Controller::* changeModeFunc)(Mode, std::map<std::string, std::string>))
{
	m_changeModeFunc = changeModeFunc;
}

void GameComponent::active(std::map<std::string, std::string>& metadata)
{
	
}

void GameComponent::draw(sf::Window& window)
{
	
}

void GameComponent::clockUpdate(sf::Time delta)
{
	
}

void GameComponent::eventHandler(sf::Window& window, sf::Event& event)
{
	
}
