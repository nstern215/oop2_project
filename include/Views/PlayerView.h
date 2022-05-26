#pragma once
#include "BaseView.h"
#include "Direction.h"
#include "Animation.h"

class PlayerView : public BaseView
{
public:
	PlayerView(int windowHeight);

	void buildPlayer();
	void draw(sf::RenderWindow& window) override;
	void setPosition(sf::Vector2f position) override;
	void move(sf::Vector2f move) override;
	void setDirection(Direction dir);
	Direction getDirection();

private:

	sf::Sprite m_sprite;
	Animation m_animation;
	Direction m_dir;

	sf::RectangleShape m_shape;
}; 