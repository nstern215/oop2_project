#include "Components/GameComponent.h"

#define TIME_STEP 1.0f/30.0f
#define VELOCITY_INTERATIONS 6
#define POSITION_INTERATIONS 6

const float PIXEL_PER_METERS = 32.0f;
const float PI = 3.14159265358979323846f;

GameComponent::GameComponent(void (Controller::* changeModeFunc)(Mode, std::map<std::string, std::string>), sf::Vector2u windowSize, Controller* controller):
	m_world(b2Vec2(0.0f, 9.8f)),
	m_tower(std::make_unique<Tower>(windowSize, &m_world)),
	m_player(std::make_unique<Player>(&m_world, m_tower->getFirstFloorPosition(),
				(b2Vec2((30.f / 2.0f) / PIXEL_PER_METERS, (57.f / 2.0f) / PIXEL_PER_METERS))))
{
	m_world.SetContactListener(&m_contactDecler);
	m_changeModeFunc = changeModeFunc;
	m_controller = controller;
}

void GameComponent::active(Metadata& metadata)
{
	m_clock.restart();
	m_tower->play();
}

void GameComponent::updateView()
{
	const auto deltaTime = m_clock.restart();



	b2Vec2 vel = m_player->keyPress();

	m_player->update(deltaTime);

	/*m_tower->move(deltaTime);*/
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
	}
	
	updateView();
}