#include "Components/GameComponent.h"
#include "Resources.h"

#include "Resources.h"

#define TIME_STEP 1.0f/30.0f
#define VELOCITY_INTERATIONS 6
#define POSITION_INTERATIONS 6
#define LEVEL_DURATION_SEC 30

GameComponent* GameComponent::m_instance = nullptr;

const float PIXEL_PER_METERS = 32.0f;
const float PI = 3.14159265358979323846f;

GameComponent::GameComponent(void (Controller::* changeModeFunc)(Mode, std::map<std::string, std::string>), sf::Vector2u windowSize, Controller* controller) :
	m_world(b2Vec2(0.0f, 9.8f)),
	m_windowSize(windowSize),
	m_tower(std::make_unique<Tower>(m_windowSize, &m_world)),
	m_player(std::make_unique<Player>(&m_world, m_tower->getFirstFloorPosition(),
		(b2Vec2((30.f / 2.0f) / PIXEL_PER_METERS, (57.f / 2.0f) / PIXEL_PER_METERS)))),
	m_clockView(increaseLevel, LEVEL_DURATION_SEC, 100),
	m_contactDecler(setLatestFloor),
	m_scoreView(m_baseScoreText, "Tower", 60)
{
	buildBackground();

	m_world.SetContactListener(&m_contactDecler);
	m_changeModeFunc = changeModeFunc;
	m_controller = controller;

	m_instance = this;

	m_scoreView.setTextColor(sf::Color::White);
	m_scoreView.setBackgroundColor(sf::Color::Green);

	m_sound.setVolume(100);
}

void GameComponent::buildBackground()
{
	m_background.setSize({ static_cast<float>(m_windowSize.x), static_cast<float>(m_windowSize.y) });
	m_background.setTexture(Resources::instance()->getTexture(m_BACKGROUND_TEXTURE));
}

void GameComponent::active(Metadata& metadata)
{
	m_clock.restart();

	if (metadata.count("status") != 0)
		if (metadata["status"] == "new")
		{
			m_tower->reset();
			m_tower->initiateNewGame();
			m_score = 0;

			m_player->reset(m_tower->getFirstFloorPosition());
			/*updateView();*/
		}
			//todo: start new game!!!!!
	
	
}

void GameComponent::updateView()
{
	
	const auto deltaTime = m_clock.restart();

	b2Vec2 vel = m_player->keyPress();

	m_player->update(deltaTime);
	m_clockView.update(deltaTime);

	if (isLoose())
		gameOver();
	
	m_tower->move(deltaTime.asSeconds());

	if (m_player->getPosition().y <= m_windowSize.y / 2)
  		m_tower->play();

	m_world.SetContactListener(&m_contactDecler);
}


void GameComponent::draw(sf::RenderWindow& window)
{
	window.draw(m_background);

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

	m_scoreView.setText(m_baseScoreText + std::to_string(m_score));
	
	const auto scoreWidth = m_scoreView.getGlobalBound().width;
	m_scoreView.setPosition({ m_windowSize.x - scoreWidth, 0 });
	
	m_scoreView.draw(window);
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
			m_tower->pause();

			const Metadata metadata = { {"status", "pause"} };
			(m_controller->*m_changeModeFunc)(MENU, metadata);
		}
		else if (event.key.code == sf::Keyboard::Key::A)
			m_tower->disableCollision();
		else if (event.key.code == sf::Keyboard::Key::S)
			m_tower->buildFloor();
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

void GameComponent::setLatestFloor(int floor)
{
	m_instance->m_score = floor;
}

bool GameComponent::isLoose() const
{
	return m_player->getPosition().y >= m_windowSize.y;
}

void GameComponent::gameOver()
{
	m_sound.setBuffer(*Resources::instance()->getMusic("game_over"));
	m_sound.play();

	const Metadata metadata = { {"score", std::to_string(m_score)} };
	(m_controller->*m_changeModeFunc)(SCORE_BOARD, metadata);
}
