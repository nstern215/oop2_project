#pragma once
#include "Animation.h"
#include "BaseView.h"

class PlayerView : public BaseView
{
public:
	PlayerView(sf::Vector2f size);

	void buildPlayer(sf::Vector2f size);
	void draw(sf::RenderWindow& window) override;
	sf::Vector2f getPosition() const override;
	void setPosition(sf::Vector2f position) override;
	sf::FloatRect getGlobalBound() const override;
	void move(sf::Vector2f move) override;

	void update(sf::Time delta);
	void direction(Direction direction);

private:
	sf::Sprite m_sprite;
	Direction m_dir = Direction::Stay;
	sf::Vector2f m_directionScaleVector = { 1,1 };
	Animation m_animation;
	
	sf::RectangleShape m_shape;
}; 