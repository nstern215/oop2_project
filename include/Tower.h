#pragma once
#include <list>
#include <memory>

#include "Floor.h"

enum TowerState
{
	PLAY = 0,
	PAUSE = 1
};

class Tower
{
public:
	Tower();
	
	void play();
	void pause();
	void reset();

	void draw(sf::Window& window);

private:

	void buildTower();
	
	std::list<std::unique_ptr<Floor>> m_floors;
	TowerState m_state;

	unsigned int m_floorsCount;
};
