#pragma once

#include <SFML/Graphics.hpp>

class BaseView
{
public:
	virtual void draw(sf::Window& window) = 0;

	virtual  void setPosition(sf::Vector2f position);
	virtual sf::Vector2f getPosition() const;

protected:
	sf::Vector2f m_position;
};
