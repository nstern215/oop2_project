#include "Components/GameComponent.h"

#define TIME_STEP 1.0f/60.0f
#define VELOCITY_INTERATIONS 6
#define POSITION_INTERATIONS 6


GameComponent::GameComponent(void (Controller::* changeModeFunc)(Mode, std::map<std::string, std::string>), int windowHeight):
	m_tower(std::make_unique<Tower>(windowHeight)),
	m_player(std::make_unique<Player>(windowHeight)),
	m_world(b2Vec2(0.0f, 9.8f))
{
	m_changeModeFunc = changeModeFunc;
	buildWorld();
	m_player->buildPlayerBody(m_world);
}

void GameComponent::buildWorld()
{ 
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(400.f / 30.f, 600.f / 30.f);

	m_ground = m_world.CreateBody(&groundBodyDef);

	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 10.0f);
	m_ground->CreateFixture(&groundBox, 0.0f);
}

void GameComponent::active(std::map<std::string, std::string>& metadata)
{
	m_clock.restart();
	m_tower->play();
}

void GameComponent::updateView()
{
	const auto deltaTime = m_clock.restart().asSeconds();

	m_tower->move(deltaTime);
}


void GameComponent::draw(sf::RenderWindow& window)
{
	m_tower->draw(window);

	b2Vec2 position = m_player->getPlayerPosition();
	m_world.Step(TIME_STEP, VELOCITY_INTERATIONS, POSITION_INTERATIONS);
	position *= 100.f;
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