#include "Views/ClockView.h"

#include "Resources.h"

ClockView::ClockView(void(*callback)(), int intervalInSeconds, float radius) :
	m_callback(callback),
	RADIUS(radius),
	m_clock(RADIUS),
	DEG_PER_SECOND(360 / intervalInSeconds)
{
	buildClock();

	m_sound.setBuffer(*Resources::instance()->getMusic("alarm"));
	m_sound.setVolume(150);
}

void ClockView::buildClock()
{
	m_clock.setPosition(0, 0);
	m_clock.setTexture(Resources::instance()->getTexture("clock"));

	m_hand.setSize({ 20, static_cast<float>(RADIUS) });
	m_hand.setOrigin(10, RADIUS);
	m_hand.setPosition(RADIUS, RADIUS);
	m_hand.setTexture(Resources::instance()->getTexture("clock_hand"));

}

void ClockView::draw(sf::RenderWindow& window)
{
	window.draw(m_clock);
	window.draw(m_hand);
}

void ClockView::setPosition(sf::Vector2f position)
{

}

sf::Vector2f ClockView::getPosition() const
{
	return{};
}

sf::FloatRect ClockView::getGlobalBound() const
{
	return {};
}

void ClockView::update(sf::Time delta)
{
	const auto rotate = delta.asSeconds() * DEG_PER_SECOND;
	m_deg += rotate;

	if (m_deg >= 360)
	{
		m_deg = static_cast<int>(m_deg) % 360;
		m_sound.play();
		m_callback();
	}

	m_hand.rotate(rotate);
}

void ClockView::resetClock()
{
	m_deg = 0;
	m_hand.rotate(-m_hand.getRotation());
}
