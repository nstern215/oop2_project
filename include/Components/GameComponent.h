#pragma once
#include "BaseComponent.h"
#include "Tower.h"

class Controller;

class GameComponent : public BaseComponent
{
public:
	GameComponent(void (Controller::*changeModeFunc)(Mode, Metadata), int windowHeight, Controller* controller);

	void active(Metadata& metadata) override;
	void draw(sf::RenderWindow& window) override;

	void eventHandler(sf::RenderWindow& window, sf::Event& event) override;

	void updateView() override;

private:
	std::unique_ptr<Tower> m_tower;
};
