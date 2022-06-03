#pragma once
#include "Views/PlayerView.h"

class Player
{
public:
	Player(int windowHeight);
	void draw(sf::RenderWindow& window) const;
	void handleCollision();
	void updatePosition(sf::Vector2f update) const;
	void keyPress(sf::Keyboard::Key key);
	void buildPlayerBody(b2World &world);
	sf::Vector2f getPosition() const;
	b2Vec2 getPlayerPosition();


private:
	std::unique_ptr<PlayerView> m_view;

	float m_playerSpeed;
};
