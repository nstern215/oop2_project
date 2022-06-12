#pragma once

#include <map>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Mode.h"
#include "Components/BaseComponent.h"

class Controller
{
public:
	Controller();

	void run();
	void changeMode(Mode mode, std::map<std::string, std::string> metadata);
	void exitGame();

private:

	void buildComponents();
	
	Mode m_activeMode;
	std::map<Mode, std::unique_ptr<BaseComponent>> m_components;

	sf::RenderWindow m_window;
	sf::Clock m_clock;

	const std::string m_HIGH_SCORE_FILE = "highscore.txt";
};
