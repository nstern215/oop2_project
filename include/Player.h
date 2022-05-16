#pragma once
#include "Views/PlayerView.h"

class Player
{
public:
	void draw(sf::Window& window);
private:
	PlayerView m_view;
};
