#include "Floor.h"

Floor::Floor(int width, int xAxis, int floorLevel):
	m_view(std::make_unique<FloorView>(width, xAxis, floorLevel))
{}

void Floor::draw(sf::RenderWindow& window) const
{
	m_view->draw(window);
}

void Floor::handleCollision()
{
	
}

void Floor::updatePosition(sf::Vector2f update) const
{
	m_view->move(update);
}

sf::Vector2f Floor::getPosition() const
{
	return m_view->getPosition();
}