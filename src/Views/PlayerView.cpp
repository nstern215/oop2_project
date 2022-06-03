#include "Views/PlayerView.h"
#include "Resources.h"

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
	m_shape.move(move);
}


void PlayerView::buildBody(b2World &world)
{
	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position.Set(5.0f, 5.0f);
	m_body = world.CreateBody(&m_bodyDef);

	m_dynamicBox.SetAsBox(1.0f, 1.0f);

	m_fixtureDef.shape = &m_dynamicBox;
	m_fixtureDef.density = 1.0f;
	m_fixtureDef.friction = 0.3f;
	m_body->CreateFixture(&m_fixtureDef);
}

b2Vec2 PlayerView::getBodyVelocity()
{
 	return m_body->GetLinearVelocity();
}

void PlayerView::setBodyVelocity(b2Vec2 vel)
{
	m_body->SetLinearVelocity(vel);
}

b2Vec2 PlayerView::getBodyPosition()
{
	return m_body->GetPosition();
}

