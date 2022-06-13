#pragma once
#include "BaseComponent.h"
#include "FileEditor.h"
#include "Views/TextView.h"

class TutorialComponent : public BaseComponent
{
public:
	TutorialComponent(void (Controller::* changeModeFunc)(Mode, Metadata), Controller* controller, sf::Vector2u windowSize);
	void updateView() override;
	void active(Metadata& metadata) override;
	void draw(sf::RenderWindow& window) override;
	void eventHandler(sf::RenderWindow& window, sf::Event& event) override;
private:
	void buildView();
	std::string prepareTutorialText() ;
	
	Mode m_previousMode = NONE;
	FileEditor m_tutorialFile;

	const std::string m_BACKGROUND_TEXTURE = "bricks_background";
	const std::string m_TUTORIAL_FONT = "Tower";
	const int m_FONT_SIZE = 40;
	
	TextView m_textView;
	sf::RectangleShape m_background;
	const sf::Color m_BACKGROUND_COLOR;
};
