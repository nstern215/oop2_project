#pragma once

#include <SFML/Graphics.hpp>

class BaseView
{
public:
	virtual void draw(sf::RenderWindow& window) = 0;

	virtual  void setPosition(sf::Vector2f position);
	virtual sf::Vector2f getPosition() const;

	virtual void move(sf::Vector2f move);

protected:
	sf::Vector2f m_position;
};
