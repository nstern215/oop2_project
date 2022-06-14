#include "FloorGenerator.h"

FloorGenerator::FloorGenerator()
{
	srand(time(NULL));
}


std::pair<sf::Vector2i, int> FloorGenerator::operator()() const
{
	int width = rand() % 7 + 3;
	int x = rand() % (20 - width) + 3;
	int y = rand() % 10 + 1;

	return std::make_pair<sf::Vector2i, int>(sf::Vector2i(x, y), std::move(width));
}
