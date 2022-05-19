#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

#include "Mode.h"

class Controller;

class BaseComponent
{
public:
	BaseComponent() = default;
	virtual ~BaseComponent() = default;

	virtual void active();
	virtual void active(std::map<std::string, std::string>& metadata) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	
	virtual void eventHandler(sf::RenderWindow& window, sf::Event& event) = 0;

	virtual void updateView() = 0;

protected:
	void (Controller::*m_changeModeFunc)(Mode, std::map<std::string, std::string>);
	sf::Clock m_clock;
};
