#include "Tower.h"

#include "FloorGenerator.h"

#define FLOORS_LOWER_BOUND 20

Tower::Tower():
	m_state(PAUSE),
	m_floorsCount(0)
{
	buildTower();
}

void Tower::draw(sf::Window& window)
{
	for (const auto& floor : m_floors)
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
	buildTower();
}

void Tower::buildTower()
{
	const FloorGenerator generator;
	
	while(m_floors.size() < FLOORS_LOWER_BOUND)
	{
		const auto [fst, snd] = generator();
		auto width = snd;
		auto x = fst.x;
		auto y = fst.y;
		
		m_floors.push_back(std::make_unique<Floor>(width, x, ++m_floorsCount));
	}
}
