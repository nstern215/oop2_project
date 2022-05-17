#pragma once
#include "Views/FloorView.h"

class Floor
{
public:
	Floor(int width, int xAxis, int floorLevel);

	void draw(sf::Window& window) const;
	void handleCollision();

private:
	std::unique_ptr<FloorView> m_view;
};
