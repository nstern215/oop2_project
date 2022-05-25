#include "Components/MenuComponent.h"

MenuComponent::MenuComponent(void (Controller::* changeModeFunc)(Mode, Metadata), Controller* controller)
{
	m_changeModeFunc = changeModeFunc;
	m_controller = controller;
}

void MenuComponent::draw(sf::RenderWindow& window)
{
	
}

void MenuComponent::eventHandler(sf::RenderWindow& window, sf::Event& event)
{
	
}

void MenuComponent::updateView()
{
	
}

void MenuComponent::active(Metadata& metadata)
{
	
}
