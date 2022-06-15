#include "Player.h"

const float PIXEL_PER_METERS = 32.0f;

Player::Player(b2World* gameWorld, b2Vec2 startingPosition, b2Vec2 size) :
	m_view(std::make_unique<PlayerView>(sf::Vector2f(size.x* PIXEL_PER_METERS, size.y* PIXEL_PER_METERS))),
	m_playerSpeed(500),
	m_contacting(true),
	m_goingRight(1.0f),
	m_goingLeft(1.0f)
{
	buildBody(gameWorld, startingPosition, size);
	m_view->setPosition({ startingPosition.x * PIXEL_PER_METERS, startingPosition.y * PIXEL_PER_METERS });
}

void Player::buildBody(b2World* world, b2Vec2 startingPosition, b2Vec2 size)
{
	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position.Set(startingPosition.x, startingPosition.y);
	
	m_body = world->CreateBody(&m_bodyDef);

	m_dynamicBox.SetAsBox(size.x, size.y);

	m_fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(this);
	
	m_fixtureDef.shape = &m_dynamicBox;

	m_fixtureDef.filter.categoryBits = 1;
	m_fixtureDef.filter.maskBits = 3;

	m_fixtureDef.density = 1.0f;
	m_fixtureDef.friction = 0.3f;
	m_body->CreateFixture(&m_fixtureDef);
}

int Player::getYAxisDirection() const
{
	const auto currentPosition = m_view->getPosition();

	return m_oldPosition.y - currentPosition.y;
}

void Player::update(sf::Time delta) const
{
	m_view->update(delta);
}

b2Vec2 Player::getBodyVelocity() const
{
	return m_body->GetLinearVelocity();
}

void Player::setBodyVelocity(b2Vec2 vel) const
{
	m_body->SetLinearVelocity(vel);
}

b2Vec2 Player::getBodyPosition() const
{
	return m_body->GetPosition();
}

void Player::draw(sf::RenderWindow& window) const
{
	m_view->draw(window);
}

void Player::updatePosition(sf::Vector2f update)
 {
 	if (m_oldPosition == m_view->getPosition())
	{
		m_view->direction(Direction::Stay);
	}

	m_oldPosition = m_view->getPosition();
	
	m_view->setPosition(update);
}

sf::Vector2f Player::getPosition() const
{
	return m_view->getPosition();
}

b2Vec2 Player::keyPress()
{
	b2Vec2 vel = m_body->GetLinearVelocity();

	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (m_goingRight != 1.0f)) ||
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (m_goingLeft != 1.0f)))
	{
		if (m_contacting)
		{
			m_view->direction(Direction::Up);
			vel.y = -15;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (m_contacting)
		{
			m_view->direction(Direction::Up);
			vel.y = -10;          
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_goingRight = 1.0f;

		m_view->direction(Direction::Left);
		vel.x = -2*m_goingLeft;
		m_goingLeft += 0.03f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_goingLeft = 1.0f;

		m_view->direction(Direction::Right);
		vel.x = 2*m_goingRight;
		m_goingRight += 0.03f;
	}
	
	m_body->SetLinearVelocity(vel);

	return m_body->GetLinearVelocity();
}

void Player::startContact()
{
	m_contacting = true;
}

void Player::endContact()
{
	m_contacting = false;
}