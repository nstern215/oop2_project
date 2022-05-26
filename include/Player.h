#pragma once
#include "Views/PlayerView.h"

class Player
{
public:
	Player(int windowHeight);

	void draw(sf::RenderWindow& window) const;

	void handleCollision();

	void updatePosition(sf::Vector2f update) const;

	void playerDirection(sf::Keyboard::Key key);

	void playerMove(float deltaTime);

	sf::Vector2f getPosition() const;

private:

	std::unique_ptr<PlayerView> m_view;

	float m_playerSpeed;
};
