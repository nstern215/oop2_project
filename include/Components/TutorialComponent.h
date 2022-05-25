#pragma once
#include "BaseComponent.h"

class TutorialComponent : public BaseComponent
{
public:
	TutorialComponent(void (Controller::* changeModeFunc)(Mode, Metadata), Controller* controller);
	void updateView() override;
	void active(Metadata& metadata) override;
	void draw(sf::RenderWindow& window) override;
	void eventHandler(sf::RenderWindow& window, sf::Event& event) override;
private:
	Mode m_previousMode = NONE;
};
