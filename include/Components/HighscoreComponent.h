#pragma once
#include "BaseComponent.h"

class HighscoreComponent : public BaseComponent
{
public:
	HighscoreComponent(void (Controller::* changeModeFunc)(Mode, Metadata), Controller* controller, sf::Vector2u windowSize);
	void draw(sf::RenderWindow& window) override;
	void updateView() override;
	void eventHandler(sf::RenderWindow& window, sf::Event& event) override;
	void active(Metadata& metadata) override;
};
