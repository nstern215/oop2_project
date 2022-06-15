#pragma once
#include "BaseView.h"

#include <SFML/Audio.hpp>

class ClockView : public BaseView
{
public:
	ClockView(void(*callback)(), int intervalInSeconds, float radius);
	void draw(sf::RenderWindow& window) override;
	sf::FloatRect getGlobalBound() const override;
	sf::Vector2f getPosition() const override;
	void setPosition(sf::Vector2f position) override;

	void update(sf::Time delta);
	void resetClock();

private:
	void buildClock();

	void(*m_callback)();

	const double DEG_PER_SECOND;
	const float RADIUS;
	
	sf::Sound m_sound;
	sf::CircleShape m_clock;
	sf::RectangleShape m_hand;

	double m_deg = 0;
};