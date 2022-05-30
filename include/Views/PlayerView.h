#pragma once
#include "BaseView.h"

class PlayerView : public BaseView
{
public:
	void draw(sf::RenderWindow& window) override;
	sf::Vector2f getPosition() const override;
	void setPosition(sf::Vector2f position) override;
	sf::FloatRect getGlobalBound() const override;
};
