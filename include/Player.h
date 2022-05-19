#pragma once
#include "Views/PlayerView.h"

class Player
{
public:
	void draw(sf::RenderWindow& window);
private:
	PlayerView m_view;
};
