#include "Floor.h"

const float PIXEL_PER_METERS = 32.0f;
const float HIGHT = (20.0f) ;

Floor::Floor(b2World* world, float width, float x, float y, float floorLevel) :
	m_view(std::make_unique<FloorView>(width, floorLevel)),
	m_gameWorld(world)
{
	buildFloorBody(width, x, y, floorLevel);
}

void Floor::buildFloorBody(float width, float x, float y, float floorLevel)
{
	m_bodyDef.type = b2_staticBody;
	m_bodyDef.position.Set((x + width / 2)/ PIXEL_PER_METERS, y / PIXEL_PER_METERS);
	m_body = m_gameWorld->CreateBody(&m_bodyDef);

	m_staticBox.SetAsBox((width / 2.0f) / PIXEL_PER_METERS, (HIGHT / 2.0f) / PIXEL_PER_METERS);
	m_body->CreateFixture(&m_staticBox, 1.0f);
	//m_body->SetUserData(m_contactDecleare.get());
	m_body->GetUserData().pointer = reinterpret_cast<uintptr_t>(m_contactDecleare.get());
}

void Floor::repositionFloor(b2Vec2 newPosition)
{

}

b2Vec2 Floor::getBodyPosition()
{
	return m_body->GetPosition();
}


void Floor::draw(sf::RenderWindow& window) const
{
	m_view->draw(window);
}

void Floor::handleCollision()
{

}

void Floor::updatePosition(sf::Vector2f update) const
{
	m_view->setPosition(update);

	const auto newPosition = m_view->getPosition();
	b2Vec2 newBodyPosition(newPosition.x / PIXEL_PER_METERS, newPosition.y / PIXEL_PER_METERS);
}

sf::Vector2f Floor::getPosition() const
{
	return m_view->getPosition();
}