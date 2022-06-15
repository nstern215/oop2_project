#include "Components/GameComponent.h"

#define TIME_STEP 1.0f/30.0f
#define VELOCITY_INTERATIONS 6
#define POSITION_INTERATIONS 6
#define LEVEL_DURATION_SEC 30

GameComponent* GameComponent::m_instance = nullptr;

const float PIXEL_PER_METERS = 32.0f;
const float PI = 3.14159265358979323846f;

GameComponent::GameComponent(void (Controller::* changeModeFunc)(Mode, std::map<std::string, std::string>), sf::Vector2u windowSize, Controller* controller):
	m_world(b2Vec2(0.0f, 9.8f)),
	m_tower(std::make_unique<Tower>(windowSize, &m_world)),
	m_player(std::make_unique<Player>(&m_world, m_tower->getFirstFloorPosition(),
				(b2Vec2((30.f / 2.0f) / PIXEL_PER_METERS, (57.f / 2.0f) / PIXEL_PER_METERS)))),
	m_clockView(increaseLevel, LEVEL_DURATION_SEC, 100)
{
	m_world.SetContactListener(&m_contactDecler);
	m_changeModeFunc = changeModeFunc;
	m_controller = controller;

	m_instance = this;
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
	m_clockView.update(deltaTime);
	
	//m_tower->move(deltaTime);
}


void GameComponent::draw(sf::RenderWindow& window)
{
	if (m_player->getYAxisDirection() > 0)
		m_tower->disableCollision();
	else
		m_tower->enableCollision();
	
	m_world.Step(TIME_STEP, VELOCITY_INTERATIONS, POSITION_INTERATIONS);
	m_tower->draw(window);

	b2Vec2 position = m_player->getBodyPosition();
	position *= PIXEL_PER_METERS;

	m_player->updatePosition({ position.x, position.y });

	m_player->draw(window);

	m_clockView.draw(window);
}

void GameComponent::eventHandler(sf::RenderWindow& window, sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyReleased:
		if (event.key.code == sf::Keyboard::Key::Add)
			m_tower->increaseSpeed();
		else if (event.key.code == sf::Keyboard::Key::Escape)
		{
			const Metadata metadata = { {"status", "pause"} };
			(m_controller->*m_changeModeFunc)(MENU, metadata);
		}
		else if (event.key.code == sf::Keyboard::Key::A)
			m_tower->disableCollision();
	case sf::Event::KeyPressed:
		//m_player->keyPress(event.key.code);

		break;
	}
	
	updateView();
}

void GameComponent::increaseLevel()
{
	m_instance->m_tower->increaseSpeed();
}
