#pragma once

#include <SFML/Graphics.hpp>

#include "BaseView.h"

class WallView : public BaseView
{
public:
	WallView(sf::Vector2u windowSize, int wallNum);
	void draw(sf::RenderWindow& window) override;

	void setPosition(sf::Vector2f position) override;

	sf::FloatRect getGlobalBound() const override;
	sf::Vector2f getPosition() const override;
	

private:

	void buildWall(sf::Vector2u windowSize, int wallNum);

	sf::RectangleShape m_rect;
};