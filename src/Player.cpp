#include "Player.h"

Player::Player(b2World* gameWorld, sf::Vector2f startingPosition, b2Vec2 size) :
	m_view(std::make_unique<PlayerView>()),
	m_playerSpeed(500)
{
	buildBody(gameWorld, startingPosition, size);
}

void Player::buildBody(b2World* world, sf::Vector2f startingPosition, b2Vec2 size)
{
	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position.Set(startingPosition.x, startingPosition.y);
	m_body = world->CreateBody(&m_bodyDef);

	m_dynamicBox.SetAsBox(size.x, size.y);

	m_fixtureDef.shape = &m_dynamicBox;
	m_fixtureDef.density = 1.0f;
	m_fixtureDef.friction = 0.3f;
	m_body->CreateFixture(&m_fixtureDef);
}

b2Vec2 Player::getBodyVelocity()
{
	return m_body->GetLinearVelocity();
}

void Player::setBodyVelocity(b2Vec2 vel)
{
	m_body->SetLinearVelocity(vel);
}

b2Vec2 Player::getBodyPosition()
{
	return m_body->GetPosition();
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
	b2Vec2 vel = m_body->GetLinearVelocity();

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

	m_body->SetLinearVelocity(vel);

}

void Player::handleCollision()
{

}