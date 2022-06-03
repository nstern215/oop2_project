#pragma once
#include "BaseComponent.h"
#include "FileEditor.h"
#include "Views/ScoreBoardView.h"
#include "Views/TextView.h"

class HighscoreComponent : public BaseComponent
{
public:
	HighscoreComponent(void (Controller::* changeModeFunc)(Mode, Metadata), Controller* controller, sf::Vector2u windowSize, std::string path);
	void draw(sf::RenderWindow& window) override;
	void updateView() override;
	void eventHandler(sf::RenderWindow& window, sf::Event& event) override;
	void active(Metadata& metadata) override;

private:
	void buildView();
	void setPosition();
	void buildBackground();

	ScoreBoardView m_boardView;
	
	FileEditor m_scoresFile;
	TextView m_inputText;
	bool m_isReadingInput = true;

	const std::string m_BACKGROUND_TEXTURE = "bricks_background";
	const int m_A_ASCII_CODE = 65;

	int m_newScore;

	sf::RectangleShape m_background;
	
	std::vector<std::unique_ptr<TextView>> m_scoreViews;
};
