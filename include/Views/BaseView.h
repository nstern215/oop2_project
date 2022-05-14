#pragma once

#include <SFML/Graphics.hpp>

class BaseView
{
public:
	virtual void draw(sf::Window& window) = 0;
};
