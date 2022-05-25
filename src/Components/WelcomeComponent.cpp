#include "Components/WelcomeComponent.h"

WelcomeComponent::WelcomeComponent(void (Controller::* changeModeFunc)(Mode, Metadata), Controller* controller)
{
	m_changeModeFunc = changeModeFunc;
	m_controller = controller;
}

void WelcomeComponent::draw(sf::RenderWindow& window)
{
	
}

void WelcomeComponent::active(Metadata& metadata)
{
	
}

void WelcomeComponent::updateView()
{
	
}

void WelcomeComponent::eventHandler(sf::RenderWindow& window, sf::Event& event)
{
	
}