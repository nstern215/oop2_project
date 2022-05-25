#pragma once
#include <list>
#include <memory>

#include "Floor.h"
#include "FloorGenerator.h"

class Tower
{
public:
	enum TowerState
	{
		PLAY = 0,
		PAUSE = 1
	};
	
	Tower(int windowHeight);
	
	void play();
	void pause();
	void reset();

	void draw(sf::RenderWindow& window);

	void move(float deltaTime);

	void increseSpeed();

private:

	void buildFloor();

	std::list<std::unique_ptr<Floor>> m_towerFloors;
	
	TowerState m_state;

	unsigned int m_floorsBufferCount;
	float m_towerSpeed;

	const FloorGenerator m_floorGen;

	int m_windowHeight;
};
