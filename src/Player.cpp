#include "Player.h"

const float PIXEL_PER_METERS = 32.0f;

Player::Player(b2World* gameWorld, b2Vec2 startingPosition, b2Vec2 size) :
	m_view(std::make_unique<PlayerView>(sf::Vector2f(size.x* PIXEL_PER_METERS, size.y* PIXEL_PER_METERS))),
	m_playerSpeed(500),
	m_contacting(true)
{
	buildBody(gameWorld, startingPosition, size);
}

void Player::buildBody(b2World* world, b2Vec2 startingPosition, b2Vec2 size)
{
	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position.Set(startingPosition.x, startingPosition.y);
	m_body = world->CreateBody(&m_bodyDef);

	m_dynamicBox.SetAsBox(size.x, size.y);

	m_fixtureDef.shape = &m_dynamicBox;
	m_fixtureDef.density = 1.0f;
	m_fixtureDef.friction = 0.3f;
	m_body->CreateFixture(&m_fixtureDef);
	//m_body->SetUserData(m_contactDecleare.get());
	m_body->GetUserData().pointer = reinterpret_cast<uintptr_t>(this);
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
	const auto v = getBodyVelocity();
	if (v.x == 0)
	{
		if (v.y > 0)
			m_view->direction(Direction::Up);
		else
			m_view->direction(Direction::Stay);
	}
	else if (v.x < 0)
		m_view->direction(Direction::Left);
	else
		m_view->direction(Direction::Right);

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

b2Vec2 Player::keyPress()
{
	b2Vec2 vel = m_body->GetLinearVelocity();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (m_contacting)
		{
			m_view->direction(Direction::Up);
			vel.y = -8;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_view->direction(Direction::Left);
		vel.x = -2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_view->direction(Direction::Right);
		vel.x = 2;
	}

	m_body->SetLinearVelocity(vel);

	return m_body->GetLinearVelocity();
}

void Player::handleCollision()
{

}

void Player::startContact()
{
	contactCounter++;
	m_contacting = true;
}

void Player::endContact()
{
	m_contacting = false;
	contactCounter++;
}
