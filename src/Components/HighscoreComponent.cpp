#include "Components/HighscoreComponent.h"

#include "Resources.h"

HighscoreComponent::HighscoreComponent(void (Controller::* changeModeFunc)(Mode, Metadata), Controller* controller, sf::Vector2u windowSize, std::string path) :
	m_boardView(windowSize),
	m_scoresFile(path),
	m_scores(5, m_scoresFile.getLines()),
	m_inputText("", "Tower", 60)
{
	m_changeModeFunc = changeModeFunc;
	m_controller = controller;
	m_windowSize = windowSize;

	m_scoresFile.loadFile();

	buildView();

	m_sound.setVolume(100);
}

void HighscoreComponent::active(Metadata& metadata)
{
	if (metadata.count("score") != 0)
	{
		m_newScore = stoi(metadata["score"]);
		if (m_scores.isNewScore(m_newScore))
		{
			if (m_newScore > m_scores.getHigherstScore())
				m_sound.setBuffer(*Resources::instance()->getMusic("new_high_score"));
			else
				m_sound.setBuffer(*Resources::instance()->getMusic("new_record_claps"));

			m_sound.play();
			
			m_isReadingInput = true;
		}
	}
}

void HighscoreComponent::eventHandler(sf::RenderWindow& window, sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyReleased:

		if (!m_isReadingInput)
		{
			if (event.key.code == sf::Keyboard::Key::Space ||
				event.key.code == sf::Keyboard::Key::Enter ||
				event.key.code == sf::Keyboard::Key::Escape)
			{
				const std::map<std::string, std::string> metadata;
				const Mode mode = MENU;

				(m_controller->*m_changeModeFunc)(mode, metadata);
			}
		}
		else
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
				if (m_inputText.getText() != m_INPUT_BASE_STRING)
					input.pop_back();
			}
			else if (event.key.code == sf::Keyboard::Enter)
			{
				if (m_inputText.getText() != m_INPUT_BASE_STRING)
					addNewScore();
			}

			m_inputText.setText(input);
		}
	}
}

void HighscoreComponent::draw(sf::RenderWindow& window)
{
	window.draw(m_background);

	m_boardView.draw(window);

	if (m_isReadingInput)
		m_inputText.draw(window);
}

void HighscoreComponent::updateView()
{

}

void HighscoreComponent::buildView()
{
	buildBackground();
	buildScoreView();
}

void HighscoreComponent::buildScoreView()
{
	m_boardView.resetView(m_scores.getScoresList());

	const auto bound = m_boardView.getGlobalBound();

	const auto x = bound.left;
	const auto y = bound.height + bound.top + (m_windowSize.y * 0.01f);

	m_inputText.setPosition({ x, y });
	m_inputText.setBackgroundColor(sf::Color(255, 255, 255, 128));
	m_inputText.setTextColor(sf::Color::Black);
	m_inputText.setText(m_INPUT_BASE_STRING);
}

void HighscoreComponent::buildBackground()
{
	m_background.setSize({ static_cast<float>(m_windowSize.x), static_cast<float>(m_windowSize.y) });
	m_background.setTexture(Resources::instance()->getTexture(m_BACKGROUND_TEXTURE));
}

void HighscoreComponent::addNewScore()
{
	const std::string input = m_inputText.getText();
	const std::string name = input.substr(m_INPUT_BASE_STRING.length(), input.length());
	m_scores.addNewScore(name, m_newScore);

	m_scoresFile.updateFile(m_scores.getScoresList());

	m_isReadingInput = false;

	buildScoreView();
}
