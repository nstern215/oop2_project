#include "Tower.h"

#include "FloorGenerator.h"

#define FLOOR_HEIGHT 20
#define FLOOR_UNIT_WIDTH 40
const float PIXEL_PER_METERS = 32.0f;

Tower::Tower(sf::Vector2u windowSize, b2World* world) :
	m_state(PAUSE),
	m_floorsBufferCount(0),
	m_towerSpeed(150),
	m_windowSize(windowSize),
	m_gameWorld(world)
{
	initiateNewGame();
}

void Tower::initiateNewGame()
{
	m_towerFloors.push_back(std::make_unique<Floor>(m_gameWorld, m_windowSize.x, m_windowSize.x / 2, (m_windowSize.y * 9) / 10, m_floorsBufferCount));

	while (m_towerFloors.size() != 10)
	{
		buildFloor();
	}
}


void Tower::increseSpeed()
{
	m_towerSpeed += 50;
}


void Tower::draw(sf::RenderWindow& window)
{
	for (const auto& floor : m_towerFloors)
	{
		b2Vec2 newPosition = floor->getBodyPosition();
		newPosition *= PIXEL_PER_METERS;
		floor->updatePosition(sf::Vector2f(newPosition.x, newPosition.y));
		floor->draw(window);
	}
}

void Tower::play()
{
	m_state = PLAY;
}

void Tower::pause()
{
	m_state = PAUSE;
}

void Tower::reset()
{
	m_state = PAUSE;

	//todo: remove all floors

}

void Tower::buildFloor()
{

	const auto [fst, snd] = m_floorGen();
	auto width = snd * FLOOR_UNIT_WIDTH;
	auto x = fst.x * FLOOR_UNIT_WIDTH;
	auto y = (m_towerFloors.back()->getBodyPosition().y) * PIXEL_PER_METERS - 100.0f;

	m_towerFloors.push_back(std::make_unique<Floor>(m_gameWorld, width, x, y, ++m_floorsBufferCount));

}

void Tower::move(float deltaTime)
{
	if (m_state != PLAY)
		return;

	if (m_towerFloors.back()->getPosition().y >= 60)
	{
		buildFloor();
	}

	const sf::Vector2f direction(0, deltaTime * m_towerSpeed);

	for (auto& m_floor : m_towerFloors)
		m_floor->updatePosition(direction);

}

sf::Vector2f Tower::getFirstFloorPosition()
{
	return m_towerFloors.front()->getPosition();
}
