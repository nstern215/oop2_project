#include "Player.h"

Player::Player(int windowHeight):
	m_view(std::make_unique<PlayerView>(windowHeight))
{}


void Player::draw(sf::RenderWindow& window) const
{
	m_view->draw(window);
}

void Player::handleCollision()
{
	
}

void Player::updatePosition(sf::Vector2f update) const
{
	m_view->move(update);
}

sf::Vector2f Player::getPosition() const
{
	return m_view->getPosition();
}

void Player::jump()
{
	
}

void Player::sideMove(int x , int y)
{
	
}

//bool Player::hitWAll()
//{
//	
//}
