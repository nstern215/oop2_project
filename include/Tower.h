#pragma once
#include <list>
#include <memory>

#include "Floor.h"
#include "FloorGenerator.h"
#include "box2d/box2d.h"

enum TowerState
{
	PLAY = 0,
	PAUSE = 1
};

class Tower
{
public:
	Tower(sf::Vector2u windowSize, b2World* world);
		
	void play();
	void pause();
	void reset();

	void draw(sf::RenderWindow& window);

	void move(float deltaTime);

	void increseSpeed();

	sf::Vector2f getFirstFloorPosition();


private:

	void initiateNewGame();

	void buildFloor();

	std::list<std::unique_ptr<Floor>> m_towerFloors;
	
	TowerState m_state;

	unsigned int m_floorsBufferCount;
	float m_towerSpeed;

	const FloorGenerator m_floorGen;

	b2World* m_gameWorld;

	sf::Vector2u m_windowSize;
};
