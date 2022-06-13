#pragma once
#include "BaseComponent.h"
#include "Tower.h"
#include "Player.h"
#include "box2d/box2d.h"

class Controller;

class GameComponent : public BaseComponent
{
public:
	GameComponent(void (Controller::*changeModeFunc)(Mode, std::map<std::string, std::string>), sf::Vector2u windowSize);

	void active(std::map<std::string, std::string>& metadata) override;
	void draw(sf::RenderWindow& window) override;

	void eventHandler(sf::RenderWindow& window, sf::Event& event) override;

	void updateView() override;

private:

	b2World m_world;

	std::unique_ptr<Tower> m_tower;

	std::unique_ptr<Player> m_player;
};
