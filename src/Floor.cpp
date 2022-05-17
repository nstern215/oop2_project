#include "Floor.h"

Floor::Floor(int width, int xAxis, int floorLevel):
	m_view(std::make_unique<FloorView>(width, xAxis, floorLevel))
{}

void Floor::draw(sf::Window& window) const
{
	m_view->draw(window);
}

void Floor::handleCollision()
{
	
}
