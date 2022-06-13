#pragma once

#include <SFML/Graphics.hpp>

#include "BaseView.h"

class FloorView : public BaseView
{
public:
	FloorView(int width, int floorLevel);
	void draw(sf::RenderWindow& window) override;

	sf::Vector2f getPosition() const override;
	void setPosition(sf::Vector2f position) override;

	void move(sf::Vector2f move) override;
private:

	void buildFloor();
	
	const int m_width; // 1-10
	const int m_floorLevel;

	sf::RectangleShape m_rect;
};
