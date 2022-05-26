#include "Player.h"

Player::Player(int windowHeight):
	m_view(std::make_unique<PlayerView>(windowHeight)),
	m_playerSpeed(500)
{}


void Player::draw(sf::RenderWindow& window) const
{
	m_view->draw(window);
}

void Player::handleCollision()
{
	
}

//void Player::updatePosition(sf::Vector2f update) const
//{
//	m_view->move(update);
//}

sf::Vector2f Player::getPosition() const
{
	return m_view->getPosition();
}

void Player::playerDirection(sf::Keyboard::Key key)
{
	Direction dir;

	switch (key)
	{
	case sf::Keyboard::Left:
		dir = Direction::Left;
		break;
	case sf::Keyboard::Right:
		dir = Direction::Right;
		break;
	case sf::Keyboard::Up:
		dir = Direction::Up;
		break;
	case sf::Keyboard::Down:
		dir = Direction::Down;
		break;
	}

	m_view->setDirection(dir);
}

void Player::playerMove(float deltaTime)
{
	sf::Vector2f upComingMove = toVector(m_view->getDirection())*m_playerSpeed*deltaTime;
	
	m_view->move(upComingMove);
	m_view->setDirection(Direction::Stay);
}
