#pragma once
#include "BaseView.h"

class PlayerView : public BaseView
{
public:
	PlayerView();

	void buildPlayer();
	void draw(sf::RenderWindow& window) override;
	sf::Vector2f getPosition() const override;
	void setPosition(sf::Vector2f position) override;
	sf::FloatRect getGlobalBound() const override;
	void move(sf::Vector2f move) override;

private:	
	sf::Sprite m_sprite;

	sf::RectangleShape m_shape;
}; 