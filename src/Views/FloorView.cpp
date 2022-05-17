#include "Views/FloorView.h"

FloorView::FloorView(int width, int xAxis, int floorLevel):
	m_width(width),
	m_xAxis(xAxis),
	m_floorLevel(floorLevel)
{
	buildFloor();
}

void FloorView::draw(sf::Window& window)
{
	
}

void FloorView::setPosition(sf::Vector2f position)
{
	m_position.y = position.y;
}


void FloorView::buildFloor()
{
	
}
