#include "Wall.h"

const float PIXEL_PER_METERS = 32.0f;
const float WIDTH = 50.0f;

Wall::Wall(b2World* world, sf::Vector2u windowSize, int wallNum):
	m_view(std::make_unique<WallView>(windowSize, wallNum)),
	m_gameWorld(world)
{
	buildWallBody(windowSize, wallNum);
}

void Wall::buildWallBody(sf::Vector2u windowSize, int wallNum)
{
	float xPosition;

	if (wallNum == 0)
		xPosition = WIDTH / 2.0f;
	else
		xPosition = windowSize.x - (WIDTH / 2.0f);

	m_bodyDef.type = b2_staticBody;
	m_bodyDef.position.Set(xPosition/PIXEL_PER_METERS, (windowSize.y / 2) / PIXEL_PER_METERS);
	m_body = m_gameWorld->CreateBody(&m_bodyDef);

	m_staticBox.SetAsBox((WIDTH / 2.0f)/PIXEL_PER_METERS, (windowSize.y/2.0f)/PIXEL_PER_METERS);
	m_body->CreateFixture(&m_staticBox, 1.0f);
}


void Wall::draw(sf::RenderWindow& window) const
{
	m_view->draw(window);
}

b2Vec2 Wall::getBodyPosition()
{
	return m_body->GetPosition();
}

void Wall::updatePosition(sf::Vector2f update) const
{
	m_view->setPosition(update);
}
