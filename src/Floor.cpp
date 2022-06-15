#include "Floor.h"

const float PIXEL_PER_METERS = 32.0f;
const float HIGHT = (20.0f) ;

Floor::Floor(b2World* world, float width, float x, float y, int floorLevel) :
	m_view(std::make_unique<FloorView>(width, floorLevel)),
	m_gameWorld(world),
	m_level(floorLevel)
{
	buildFloorBody(width, x, y);
}

void Floor::buildFloorBody(float width, float x, float y)
{
	m_collisionFilter.categoryBits = 1;
	m_collisionFilter.maskBits = 3;
	
	m_bodyDef.type = b2_staticBody;
	m_bodyDef.position.Set((x + width / 2)/ PIXEL_PER_METERS, y / PIXEL_PER_METERS);
	m_body = m_gameWorld->CreateBody(&m_bodyDef);
	
	m_staticBox.SetAsBox((width / 2.0f) / PIXEL_PER_METERS, (HIGHT / 2.0f) / PIXEL_PER_METERS);
	m_fixtureDef.shape = &m_staticBox;

	m_fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(this);
	
	m_fixtureDef.filter.categoryBits = 1;
	m_fixtureDef.filter.maskBits = 3;
	m_body->CreateFixture(&m_fixtureDef);
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

void Floor::updatePosition(sf::Vector2f update) const
{
	m_view->setPosition(update);

	const auto newPosition = m_view->getPosition();
	const b2Vec2 newBodyPosition(newPosition.x / PIXEL_PER_METERS, newPosition.y / PIXEL_PER_METERS);

	m_body->SetTransform(newBodyPosition, 0);
}

sf::Vector2f Floor::getPosition() const
{
	return m_view->getPosition();
}

void Floor::enableCollision()
{
	const auto currentFilter = m_body->GetFixtureList()->GetFilterData();
	if (currentFilter.maskBits == 3)
		return;

	m_collisionFilter.categoryBits = 1;
	m_collisionFilter.maskBits = 3;

	m_body->GetFixtureList()->SetFilterData(m_collisionFilter);
}

void Floor::disableCollision()
{
	const auto currentFilter = m_body->GetFixtureList()->GetFilterData();
	if (currentFilter.maskBits == 2)
		return;
	m_collisionFilter.categoryBits = 1;
	m_collisionFilter.maskBits = 2;
	
	m_body->GetFixtureList()->SetFilterData(m_collisionFilter);
}

int Floor::getLevel() const
{
	return m_level;
}
