#pragma once

#include <utility>
#include <SFML/Graphics.hpp>

class FloorGenerator
{
public:
	FloorGenerator();
	std::pair<sf::Vector2i, int> operator()() const;
};
