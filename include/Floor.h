#pragma once
#include "Views/FloorView.h"

class Floor
{
public:
	Floor(int width, int xAxis, int floorLevel);

	void draw(sf::RenderWindow& window) const;
	void handleCollision();

	void updatePosition(sf::Vector2f update) const;

	sf::Vector2f getPosition() const;

private:
	std::unique_ptr<FloorView> m_view;
};
