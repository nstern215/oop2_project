#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

#include "Mode.h"

class Controller;

using Metadata = std::map<std::string, std::string>;

class BaseComponent
{
public:
	enum ComponentMode
	{
		STOP = 0,
		PLAY = 1
	};
	
	BaseComponent() = default;
	virtual ~BaseComponent() = default;

	virtual void active();
	virtual void active(Metadata& metadata) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	
	virtual void eventHandler(sf::RenderWindow& window, sf::Event& event) = 0;

	virtual void updateView() = 0;

protected:
	void (Controller::*m_changeModeFunc)(Mode, Metadata);
	sf::Clock m_clock;

	sf::Vector2u m_windowSize;
	
	Controller* m_controller = nullptr;

	ComponentMode m_mode = STOP;
};
