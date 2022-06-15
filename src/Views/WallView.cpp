#include "Views/WallView.h"

#include "Resources.h"

#define WALL_UNIT_WIDTH 200

WallView::WallView(sf::Vector2u windowSize, int wallNum)
{
	buildWall(windowSize, wallNum);
}

void WallView::buildWall(sf::Vector2u windowSize, int wallNum)
{
	m_rect.setSize(sf::Vector2f(WALL_UNIT_WIDTH, windowSize.y));
	m_rect.setOrigin(sf::Vector2f(m_rect.getSize().x / 2.0f, m_rect.getSize().y / 2.0f));
	m_rect.setTexture(Resources::instance()->getTexture(m_BACKGROUND_TEXTURE));
}


void WallView::draw(sf::RenderWindow& window)
{
	window.draw(m_rect);
}

void WallView::setPosition(sf::Vector2f position)
{
	m_rect.setPosition(position);
}

sf::FloatRect WallView::getGlobalBound() const
{
	return {};
}

sf::Vector2f WallView::getPosition() const
{
	return {};
}
