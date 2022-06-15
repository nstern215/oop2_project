#pragma once

#include <SFML/Graphics.hpp>

#include "BaseView.h"

class WallView : public BaseView
{
public:
	WallView(sf::Vector2u windowSize, int wallNum);
	void draw(sf::RenderWindow& window) override;

	void setPosition(sf::Vector2f position) override;

	sf::FloatRect getGlobalBound() const override;
	sf::Vector2f getPosition() const override;
	

private:

	void buildWall(sf::Vector2u windowSize, int wallNum);

	sf::RectangleShape m_rect;
	void buildBackground();
	const std::string m_BACKGROUND_TEXTURE = "front_background";
	const int m_MENU_ITEM_FONT_SIZE = 60;
	const sf::Vector2u m_windowSize;;

};