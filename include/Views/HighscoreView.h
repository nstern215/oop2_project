#pragma once
#include "BaseView.h"

class HighscoreView : public BaseView
{
public:
	HighscoreView();

	void draw(sf::RenderWindow& window) override;
	sf::FloatRect getGlobalBound() const override;
	sf::Vector2f getPosition() const override;
	void setPosition(sf::Vector2f position) override;
private:
	
};
