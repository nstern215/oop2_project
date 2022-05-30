#include "Components/HighscoreComponent.h"

HighscoreComponent::HighscoreComponent(void (Controller::* changeModeFunc)(Mode, Metadata), Controller* controller, sf::Vector2u windowSize)
{
	m_changeModeFunc = changeModeFunc;
	m_controller = controller;
}

void HighscoreComponent::active(Metadata& metadata)
{
	
}

void HighscoreComponent::eventHandler(sf::RenderWindow& window, sf::Event& event)
{
	
}

void HighscoreComponent::draw(sf::RenderWindow& window)
{
	
}

void HighscoreComponent::updateView()
{

}