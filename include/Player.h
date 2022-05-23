#pragma once
#include "Views/PlayerView.h"

class Player
{
public:
	Player(int windowHeight);

	void draw(sf::RenderWindow& window) const;

	void handleCollision();

	void updatePosition(sf::Vector2f update) const;

	void jump();

	void sideMove(int x, int y);

	bool hitWAll();

	sf::Vector2f getPosition() const;

private:
	std::unique_ptr<PlayerView> m_view;
};
