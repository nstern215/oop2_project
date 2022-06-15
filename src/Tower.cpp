#include "Tower.h"

#include "FloorGenerator.h"

#define FLOOR_HEIGHT 20
#define FLOOR_UNIT_WIDTH 40
#define INITIATE_SPEED 100
const float PIXEL_PER_METERS = 32.0f;

Tower::Tower(sf::Vector2u windowSize, b2World* world) :
	m_state(PAUSE),
	m_floorsBufferCount(0),
	m_towerSpeed(INITIATE_SPEED),
	m_windowSize(windowSize),
	m_gameWorld(world)
{
	initiateNewGame();
}

void Tower::initiateNewGame()
{
	m_barrier = std::make_unique<Floor>(m_gameWorld, m_windowSize.x, 0, 0, m_floorsBufferCount);

	m_towerFloors.push_back(std::make_unique<Floor>(m_gameWorld, m_windowSize.x, 0, (m_windowSize.y * 9) / 10, m_floorsBufferCount));

	for (int numOfWalls = 0; numOfWalls < 2; numOfWalls++)
		m_walls.push_back(std::make_unique<Wall>(m_gameWorld, m_windowSize, numOfWalls));

	auto firstFloor = m_towerFloors.begin();
	b2Vec2 newPosition = firstFloor->get()->getBodyPosition();
	newPosition *= PIXEL_PER_METERS;
	firstFloor->get()->updatePosition(sf::Vector2f(newPosition.x, newPosition.y));
}

void Tower::increaseSpeed()
{
	m_towerSpeed += 50;
}

void Tower::draw(sf::RenderWindow& window)
{
	for (const auto& floor : m_towerFloors)
	{
		floor->draw(window);
	}       
             
    for(const auto& wall:m_walls)
	{
		b2Vec2 newPosition = wall->getBodyPosition();
		newPosition *= PIXEL_PER_METERS;
		wall->updatePosition(sf::Vector2f(newPosition.x, newPosition.y));
		wall->draw(window);
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

	m_towerFloors.clear();
	m_towerSpeed = INITIATE_SPEED;
	m_floorsBufferCount = 0;
}

void Tower::buildFloor()
{

	const auto [fst, snd] = m_floorGen();
	auto width = snd * FLOOR_UNIT_WIDTH;
	auto x = fst.x * FLOOR_UNIT_WIDTH;
	auto y = (m_towerFloors.back()->getBodyPosition().y) * PIXEL_PER_METERS - 120.0f;

	auto f = new Floor(m_gameWorld, width, x, y, ++m_floorsBufferCount);

	b2Vec2 newPosition = f->getBodyPosition();
	newPosition *= PIXEL_PER_METERS;
	f->updatePosition(sf::Vector2f(newPosition.x, newPosition.y));
	
	m_towerFloors.push_back(std::unique_ptr<Floor>(f));
	
}

void Tower::move(float deltaTime)
{

	if (m_towerFloors.back()->getPosition().y >= 90)
	{
		buildFloor();
	}

	/*auto it = std::remove_if(m_towerFloors.begin(), m_towerFloors.end(), 
		[&](const Floor* f) { return f->getPosition().y > m_windowSize.y; });*/

	//erase_if(m_towerFloors, [&](const Floor* f) { return f->getPosition().y > m_windowSize.y; });
	
	if (m_state != PLAY)
		return;

	const sf::Vector2f direction(0, deltaTime * m_towerSpeed);
	move(direction);
}

void Tower::move(sf::Vector2f direction)
{
	for (auto& m_floor : m_towerFloors)
	{
		sf::Vector2f newPosition = m_floor->getPosition() + direction;

		m_floor->updatePosition(newPosition);
	}
}

float Tower::getSpeed() const
{
	return m_towerSpeed;
}

void Tower::setSpeed(float speed)
{
	m_towerSpeed = speed;
}

b2Vec2 Tower::getFirstFloorPosition()
{

	return m_towerFloors.front()->getBodyPosition();
}


void Tower::enableCollision()
{
	for (const auto& floor : m_towerFloors)
		floor->enableCollision();
}

void Tower::disableCollision()
{
	for (const auto& floor : m_towerFloors)
		floor->disableCollision();
}

