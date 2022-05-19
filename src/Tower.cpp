#include "Tower.h"

#include "FloorGenerator.h"

Tower::Tower(int windowHeight) :
	m_state(PAUSE),
	m_floorsBufferCount(0),
	m_towerSpeed(150),
	m_windowHeight(windowHeight)
{
}

void Tower::increseSpeed()
{
	m_towerSpeed += 50;
}


void Tower::draw(sf::RenderWindow& window)
{
	for (const auto& floor : m_towerFloors)
		floor->draw(window);
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
	{
		const auto [fst, snd] = m_floorGen();
		auto width = snd;
		auto x = fst.x;
		auto y = fst.y;

		m_towerFloors.push_back(std::make_unique<Floor>(width, x, ++m_floorsBufferCount));
	}
}

void Tower::move(float deltaTime)
{
	if (m_state != PLAY)
		return;

	if (m_towerFloors.empty() || m_towerFloors.back()->getPosition().y >= 60)
	{
		buildFloor();
	}

	const sf::Vector2f direction(0, deltaTime * m_towerSpeed);
	
	for (auto& m_floor : m_towerFloors)
			m_floor->updatePosition(direction);
}
