#pragma once
#include <SFML/Audio.hpp>

#include "BaseComponent.h"
#include "Tower.h"
#include "Player.h"
#include "ContactDecleare.h"
#include "box2d/box2d.h"
#include "Views/ClockView.h"
#include "Views/TextView.h"

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

	void buildBackground();
	sf::RectangleShape m_background;
	const std::string m_BACKGROUND_TEXTURE = "back_background";
	const int m_MENU_ITEM_FONT_SIZE = 60;
	const sf::Vector2u m_windowSize;;

	bool isLoose() const;
	void gameOver();
	
	static GameComponent* m_instance;
	
	b2World m_world;

	std::unique_ptr<Tower> m_tower;

	std::unique_ptr<Player> m_player;

	ContactDecleare m_contactDecler;

	ClockView m_clockView;

	int m_score = 0;

	const std::string m_baseScoreText = "Score:   ";
	TextView m_scoreView;


	sf::Sound m_sound;
};