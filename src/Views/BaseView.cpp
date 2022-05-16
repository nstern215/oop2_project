#include "Views/BaseView.h";

void BaseView::draw(sf::Window& window)
{
	
}

sf::Vector2f BaseView::getPosition() const
{
	return m_position;
}

void BaseView::setPosition(sf::Vector2f position)
{
	m_position = position;
}
