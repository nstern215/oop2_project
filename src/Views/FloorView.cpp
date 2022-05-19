#include "Views/FloorView.h"

#define FLOOR_HEIGHT 20
#define FLOOR_UNIT_WIDTH 40

FloorView::FloorView(int width, int xAxis, int floorLevel):
	m_width(width),
	m_xAxis(xAxis),
	m_floorLevel(floorLevel)
{
	buildFloor();
}

void FloorView::draw(sf::RenderWindow& window)
{
	window.draw(m_rect);
}

void FloorView::setPosition(sf::Vector2f position)
{
	m_position.y = position.y;
}

sf::Vector2f FloorView::getPosition() const
{
	return m_rect.getPosition();
}

void FloorView::buildFloor()
{
	m_rect.setPosition(m_xAxis * FLOOR_UNIT_WIDTH, -FLOOR_HEIGHT);
	
	m_rect.setSize({static_cast<float>(m_width * FLOOR_UNIT_WIDTH), FLOOR_HEIGHT});
	m_rect.setFillColor(sf::Color(212, 165, 38));
	m_rect.setOutlineColor(sf::Color::White);
	m_rect.setOutlineThickness(5);
}

void FloorView::move(sf::Vector2f move)
{
	m_rect.move(move);
}