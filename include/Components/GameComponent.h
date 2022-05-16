#pragma once
#include "BaseComponent.h"

class Controller;

class GameComponent : public BaseComponent
{
public:
	GameComponent(void (Controller::*changeModeFunc)(Mode, std::map<std::string, std::string>));

	void active(std::map<std::string, std::string>& metadata) override;
	void draw(sf::Window& window) override;

	void eventHandler(sf::Window& window, sf::Event& event) override;
};
