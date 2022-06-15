#pragma once
#include "BaseComponent.h"
#include "Tower.h"
#include "Player.h"
#include "ContactDecleare.h"
#include "box2d/box2d.h"
#include "Views/ClockView.h"

class Controller;

class GameComponent : public BaseComponent
{
public:
	GameComponent(void (Controller::*changeModeFunc)(Mode, std::map<std::string, std::string>), sf::Vector2u windowSize, Controller* conrtoller);

	static void increaseLevel();
	static void setLatestFloor(int floor);
	
	void active(Metadata& metadata) override;
	void draw(sf::RenderWindow& window) override;

	void eventHandler(sf::RenderWindow& window, sf::Event& event) override;

	void updateView() override;

private:

	static GameComponent* m_instance;
	
	b2World m_world;

	std::unique_ptr<Tower> m_tower;

	std::unique_ptr<Player> m_player;

	ContactDecleare m_contactDecler;

	ClockView m_clockView;

	int m_score = 0;
};

struct Data
{
	std::string type;
	void* elem;
};