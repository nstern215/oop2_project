#include "Views/PlayerView.h"

#define PLAYER_SIZE 50

PlayerView::PlayerView(int windowHeight)
{
	buildPlayer();
	float x = (windowHeight - PLAYER_SIZE) / 2;
	float y = windowHeight - PLAYER_SIZE;
	setPosition({x, y});
}


void PlayerView::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}

void PlayerView::buildPlayer()
{
	m_shape.setSize({ static_cast<float>(PLAYER_SIZE), static_cast<float>(PLAYER_SIZE)});
	m_shape.setFillColor(sf::Color::Blue);
}

void PlayerView::setPosition(sf::Vector2f position)
{
	m_shape.setPosition(position);
}

void PlayerView::move(sf::Vector2f move)
{
	auto newPosition = m_shape.getPosition();

	newPosition.x += move.x;
	newPosition.y += move.y;

	setPosition(newPosition);
}