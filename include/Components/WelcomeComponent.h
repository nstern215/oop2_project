#pragma once
#include "BaseComponent.h"

class WelcomeComponent : public BaseComponent
{
public:
	WelcomeComponent(void (Controller::* changeModeFunc)(Mode, Metadata), Controller* controller);
	void updateView() override;
	void active(Metadata& metadata) override;
	void draw(sf::RenderWindow& window) override;
	void eventHandler(sf::RenderWindow& window, sf::Event& event) override;
};
