#include "Views/PlayerView.h"
#include "Resources.h"

const float PLAYER_SIZE = 50.0f;

PlayerView::PlayerView()
{
	buildPlayer();
}


void PlayerView::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}

void PlayerView::buildPlayer()
{
	m_shape.setSize(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
	m_shape.setFillColor(sf::Color::Blue);
}

void PlayerView::setPosition(sf::Vector2f position)
{
	m_shape.setPosition(position);
}

void PlayerView::move(sf::Vector2f move)
{
	m_shape.move(move);
}

sf::FloatRect PlayerView::getGlobalBound() const
{
	return m_shape.getGlobalBounds();
}

sf::Vector2f PlayerView::getPosition() const
{
	return m_shape.getPosition();
}
