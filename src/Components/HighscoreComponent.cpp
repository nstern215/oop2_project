#include "Components/HighscoreComponent.h"

HighscoreComponent::HighscoreComponent(void (Controller::* changeModeFunc)(Mode, Metadata), Controller* controller, sf::Vector2u windowSize, std::string path) :
	m_scoresFile(path),
	m_inputText("", "Tower", 60)
{
	m_changeModeFunc = changeModeFunc;
	m_controller = controller;
	m_windowSize = windowSize;

	m_scoresFile.loadFile();

	buildView();
}

void HighscoreComponent::active(Metadata& metadata)
{
	if (metadata.count("score") != 0)
	{
		m_newScore = stoi(metadata["score"]);
		m_isReadingInput = true;
	}
}

void HighscoreComponent::eventHandler(sf::RenderWindow& window, sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyReleased:

		if (!m_isReadingInput && (
			event.key.code == sf::Keyboard::Key::Space ||
			event.key.code == sf::Keyboard::Key::Enter ||
			event.key.code == sf::Keyboard::Key::Escape))
		{
			const std::map<std::string, std::string> metadata;
			const Mode mode = MENU;

			(m_controller->*m_changeModeFunc)(mode, metadata);
		}
		else if (m_isReadingInput)
		{
			std::string input = m_inputText.getText();

			if (event.key.code >= sf::Keyboard::Key::A && event.key.code <= sf::Keyboard::Key::Z)
			{
				const char addedChar = event.key.code + m_A_ASCII_CODE;
				input += addedChar;
			}
			else if (event.key.code == sf::Keyboard::Space)
			{
				input += " ";
			}
			else if (event.key.code == sf::Keyboard::BackSpace)
			{
				input.pop_back();
			}
			else if (event.key.code == sf::Keyboard::Enter)
			{
				//todo: save new score
				m_isReadingInput = false;
			}

			m_inputText.setText(input);
		}
	}
}

void HighscoreComponent::draw(sf::RenderWindow& window)
{
	for (const auto& scoreView : m_scoreViews)
		scoreView->draw(window);

	if (m_isReadingInput)
		m_inputText.draw(window);
}

void HighscoreComponent::updateView()
{

}

void HighscoreComponent::buildView()
{
	m_inputText.setTextColor(sf::Color::Red);
	m_inputText.setFontSize(75);
	m_inputText.setPosition({ 150, 50 });

	for (const auto& line : m_scoresFile)
		m_scoreViews.push_back(std::make_unique<TextView>(line, "Tower", 60));

	for (const auto& line : m_scoreViews)
	{
		line->setTextColor(sf::Color::Yellow);
	}

	setPosition();
}

void HighscoreComponent::setPosition()
{
	auto midWindow = m_windowSize.x / 2;
	float height = 0;

	/*const auto item = std::max_element(m_items.begin(), m_items.end(), [](const auto& item) {return item.getGlobalBound().width; });
	auto maxItemBound = item->getGlobalBound().width;*/

	for (const auto& item : m_scoreViews)
	{
		item->setPosition({ 10, height });
		height += 10 + item->getGlobalBound().height;
	}
}
