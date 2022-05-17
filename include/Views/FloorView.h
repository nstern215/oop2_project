#pragma once

#include <SFML/Graphics.hpp>

#include "BaseView.h"

class FloorView : public BaseView
{
public:
	FloorView(int width, int xAxis, int floorLevel);
	void draw(sf::Window& window) override;

	void setPosition(sf::Vector2f position) override;
private:

	void buildFloor();
	
	const int m_width;
	const int m_xAxis;
	const int m_floorLevel;
};
