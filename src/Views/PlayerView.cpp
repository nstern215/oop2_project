#include <optional>

#include "Views/PlayerView.h"
#include "Resources.h"

const float PLAYER_SIZE = 50.0f;
constexpr auto PlayerSpeed = 60.f;

namespace
{
    std::optional<Direction> toDirection(sf::Keyboard::Key key)
    {
        switch (key)
        {
        case sf::Keyboard::Left:
            return Direction::Left;
        case sf::Keyboard::Right:
            return Direction::Right;
        case sf::Keyboard::Up:
            return Direction::Up;
        case sf::Keyboard::Down:
            return Direction::Down;
        case sf::Keyboard::Space:
            return Direction::Stay;
        }
        return {};
    }
}

PlayerView::PlayerView():
	m_animation(Resources::instance()->animationData(Resources::Player), Direction::Stay, m_sprite)
{	
	buildPlayer();
}

void PlayerView::update(sf::Time delta)
{
    m_animation.update(delta);
    move(toVector(m_dir) * delta.asSeconds() * PlayerSpeed);
}

void PlayerView::direction(Direction direction)
{
    if (m_dir == direction)
        return;
	
    m_dir = direction;
    m_animation.direction(m_dir);

    m_sprite.scale(m_directionScaleVector);

    if (m_dir == Direction::Left)
        m_directionScaleVector = { -1,1 };
    else
        m_directionScaleVector = { 1,1 };

    m_sprite.scale(m_directionScaleVector);
}

void PlayerView::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void PlayerView::buildPlayer()
{
	m_shape.setSize(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
	m_shape.setFillColor(sf::Color::Blue);
}

void PlayerView::setPosition(sf::Vector2f position)
{
	m_sprite.setPosition(position);
}

void PlayerView::move(sf::Vector2f move)
{
	m_shape.move(move);

	m_sprite.move(move);
}

sf::FloatRect PlayerView::getGlobalBound() const
{
	return m_sprite.getGlobalBounds();
}

sf::Vector2f PlayerView::getPosition() const
{
	return m_sprite.getPosition();
}