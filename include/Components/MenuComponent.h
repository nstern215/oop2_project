#pragma once
#include "BaseComponent.h"

class MenuComponent : public BaseComponent
{
public:
	MenuComponent(void (Controller::* changeModeFunc)(Mode, Metadata), Controller* controller);
	void updateView() override;
	void draw(sf::RenderWindow& window) override;
	void eventHandler(sf::RenderWindow& window, sf::Event& event) override;
	void active(Metadata& metadata) override;
};
