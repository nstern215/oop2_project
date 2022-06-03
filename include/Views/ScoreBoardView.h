#pragma once
#include "BaseView.h"
#include "TextView.h"

class ScoreBoardView : public BaseView
{
public:
	ScoreBoardView(sf::Vector2u windowSize);

	void draw(sf::RenderWindow& window) override;
	sf::FloatRect getGlobalBound() const override;
	sf::Vector2f getPosition() const override;
	void setPosition(sf::Vector2f position) override;

	void resetView(std::vector<std::string> scores);

private:
	void setPositions();
	
	sf::Vector2u m_windowSize;
	sf::RectangleShape m_background;
	
	std::vector<std::unique_ptr<TextView>> m_scoreViews;
};
