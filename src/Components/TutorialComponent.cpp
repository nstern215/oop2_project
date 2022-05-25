#include "Components/TutorialComponent.h"

#define PREVIOUS_MODE_KEY "PREVIOUS_MODE"

TutorialComponent::TutorialComponent(void (Controller::* changeModeFunc)(Mode, Metadata), Controller* controller)
{
	m_changeModeFunc = changeModeFunc;
	m_controller = controller;
}

void TutorialComponent::active(Metadata& metadata)
{
	if (metadata.count(PREVIOUS_MODE_KEY))
		m_previousMode = static_cast<Mode> (std::stoi(metadata[PREVIOUS_MODE_KEY]));
	else
		m_previousMode = NONE;

	
}

void TutorialComponent::draw(sf::RenderWindow& window)
{
	
}

void TutorialComponent::eventHandler(sf::RenderWindow& window, sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyReleased:
		const std::map<std::string, std::string> metadata;
		const Mode mode = m_previousMode == NONE ? MENU : m_previousMode;

		(m_controller->*m_changeModeFunc)(mode, metadata);

		
	}
}

void TutorialComponent::updateView()
{
	
}
