#pragma once
#include "BaseView.h"

class PlayerView : public BaseView
{
public:
	PlayerView(int windowHeight);

	void buildPlayer();
	void draw(sf::RenderWindow& window) override;
	void setPosition(sf::Vector2f position) override;
	void move(sf::Vector2f move) override;


private:

	sf::RectangleShape m_shape;
}; 