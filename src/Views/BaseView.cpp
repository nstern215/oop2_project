#include "Views/BaseView.h"

//void BaseView::draw(sf::RenderWindow& window)
//{
//	
//}

sf::Vector2f BaseView::getPosition() const
{
	return m_position;
}

void BaseView::setPosition(sf::Vector2f position)
{
	m_position = position;
}

void BaseView::move(sf::Vector2f move)
{
	m_position += move;
}
