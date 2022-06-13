#include "Floor.h"

const float PIXEL_PER_METERS = 32.0f;
const float HIGHT = (20.0f / 2.0f) / PIXEL_PER_METERS;

Floor::Floor(b2World* world, float width, float x, float y, float floorLevel):
	m_view(std::make_unique<FloorView>(width, floorLevel))
{
	buildFloorBody(world, width, x, y, floorLevel);
}

void Floor::buildFloorBody(b2World* world, float width, float x, float y, float floorLevel)
{
	m_bodyDef.type = b2_staticBody;
	m_bodyDef.position.Set(x/PIXEL_PER_METERS, y/PIXEL_PER_METERS);
	m_body = world->CreateBody(&m_bodyDef);

	m_staticBox.SetAsBox((width / 2.0f)/PIXEL_PER_METERS, HIGHT);
	m_body->CreateFixture(&m_staticBox, 0.0f);
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
	m_view->move(update);
}

sf::Vector2f Floor::getPosition() const
{
	return m_view->getPosition();
}