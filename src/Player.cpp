#include "Player.h"

Player::Player(int windowHeight) :
	m_view(std::make_unique<PlayerView>(windowHeight)),
	m_playerSpeed(500)
{}

void Player::buildPlayerBody(b2World& world)
{
	m_view->buildBody(world);
}

void Player::draw(sf::RenderWindow& window) const
{
	m_view->draw(window);
}

void Player::updatePosition(sf::Vector2f update) const
{
	m_view->setPosition(update);
}

sf::Vector2f Player::getPosition() const
{
	return m_view->getPosition();
}

void Player::keyPress(sf::Keyboard::Key key)
  {
	b2Vec2 vel = m_view->getBodyVelocity();

	switch (key)
	{
	case sf::Keyboard::Space:
 		vel.y = -5;
		break;
	case sf::Keyboard::Left:
		vel.x = -2;
		break;
	case sf::Keyboard::Right:
		vel.x = 2;
		break;
	default:
			break;
	}

	m_view->setBodyVelocity(vel);

}

b2Vec2 Player::getPlayerPosition()
{
	return m_view->getBodyPosition();
}

void Player::handleCollision()
{

}