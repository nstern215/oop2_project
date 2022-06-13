#include "Components/TutorialComponent.h"

#include "Resources.h"

#define PREVIOUS_MODE_KEY "PREVIOUS_MODE"
#define TUTORIAL_FILE_NAME "tutorial.txt"

TutorialComponent::TutorialComponent(void (Controller::* changeModeFunc)(Mode, Metadata), Controller* controller, sf::Vector2u windowSize) :
	m_tutorialFile("tutorial.txt"),
	m_textView("", m_TUTORIAL_FONT, m_FONT_SIZE),
	m_BACKGROUND_COLOR(255, 255, 255, 128)
{
	m_windowSize = windowSize;

	m_changeModeFunc = changeModeFunc;
	m_controller = controller;

	buildView();
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
	window.draw(m_background);
	m_textView.draw(window);
}

void TutorialComponent::eventHandler(sf::RenderWindow& window, sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyReleased:
		const std::map<std::string, std::string> metadata;
		const Mode mode = m_previousMode == NONE ? MENU : m_previousMode;

		(m_controller->*m_changeModeFunc)(mode, metadata);

		break;
	}
}

void TutorialComponent::updateView()
{

}

void TutorialComponent::buildView()
{
	m_background.setSize({ static_cast<float>(m_windowSize.x), static_cast<float>(m_windowSize.y) });
	m_background.setTexture(Resources::instance()->getTexture(m_BACKGROUND_TEXTURE));

	m_textView.setText(prepareTutorialText());

	const auto textBound = m_textView.getGlobalBound();
	const auto midWindowX = m_windowSize.x / 2;
	const auto midWindowY = m_windowSize.y / 2;

	m_textView.setPosition({ midWindowX - (textBound.width / 2), midWindowY - (textBound.height / 2) });
	m_textView.setTextColor(sf::Color::Black);

	m_textView.setBackgroundColor(m_BACKGROUND_COLOR);
}

std::string TutorialComponent::prepareTutorialText()
{
	std::string tutorial = "Tutorial\n\n";

	for (auto& line : m_tutorialFile)
	{
		tutorial += line;
		tutorial += "\n";
	}

	return tutorial;
}
