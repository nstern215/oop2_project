#include "Components/GameComponent.h"

#define TIME_STEP 1.0f/60.0f
#define VELOCITY_INTERATIONS 6
#define POSITION_INTERATIONS 6

const float PIXEL_PER_METERS = 32.0f;
const float PI = 3.14159265358979323846f;

GameComponent::GameComponent(void (Controller::* changeModeFunc)(Mode, std::map<std::string, std::string>), sf::Vector2u windowSize):
	m_world(b2Vec2(0.0f, 9.8f)),
	m_tower(std::make_unique<Tower>(windowSize, &m_world)),
	m_player(std::make_unique<Player>(&m_world, (m_tower->getFirstFloorPosition()/PIXEL_PER_METERS),
				(b2Vec2((50.f / 2.0f) / PIXEL_PER_METERS, (50.f / 2.0f) / PIXEL_PER_METERS))))
{
	m_changeModeFunc = changeModeFunc;
}

void GameComponent::active(std::map<std::string, std::string>& metadata)
{
	m_clock.restart();
	m_tower->play();
}

void GameComponent::updateView()
{
	const auto deltaTime = m_clock.restart().asSeconds();

	//m_tower->move(deltaTime);
}


void GameComponent::draw(sf::RenderWindow& window)
{
	
	m_world.Step(TIME_STEP, VELOCITY_INTERATIONS, POSITION_INTERATIONS);
	m_tower->draw(window);

	b2Vec2 position = m_player->getBodyPosition();
	position *= PIXEL_PER_METERS;

	m_player->updatePosition({ position.x, position.y });

	m_player->draw(window);
}

void GameComponent::eventHandler(sf::RenderWindow& window, sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyReleased:
		if (event.key.code == sf::Keyboard::Key::Add)
			m_tower->increseSpeed();
	case sf::Event::KeyPressed:
		m_player->keyPress(event.key.code);

		break;
	}
	
	updateView();
}