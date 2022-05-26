#pragma once

#include <SFML/Graphics.hpp>

enum class Direction
{
    Up,
    Down,
    Right,
    Left,
    Stay,
};

sf::Vector2f toVector(Direction dir);