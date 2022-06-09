#include "Views/ScoreBoardView.h"



ScoreBoardView::ScoreBoardView(sf::Vector2u windowSize) :
	m_windowSize(windowSize)
{
	m_background.setFillColor(sf::Color(255, 255, 255, 128));

	m_background.setSize({ static_cast<float>(m_windowSize.x * 0.9), static_cast<float>(m_windowSize.y * 0.9) });
	m_background.setPosition({ static_cast<float>(m_windowSize.x * 0.05), static_cast<float>(m_windowSize.y * 0.05) });

}


void ScoreBoardView::draw(sf::RenderWindow& window)
{
	window.draw(m_background);

	for (const auto& view : m_scoreViews)
		view->draw(window);
}

void ScoreBoardView::resetView(std::vector<std::string> scores)
{

	if (m_scoreViews.empty())
	{
		for (const auto& score : scores)
			m_scoreViews.push_back(std::make_unique<TextView>(score, "Tower", 60));
	}
	else
	{
		auto viewIt = m_scoreViews.begin();

		for (const auto& score : scores)
		{
			if (viewIt != m_scoreViews.end())
				(viewIt++)->get()->setText(score);
			else
				m_scoreViews.push_back(std::make_unique<TextView>(score, "Tower", 60));
		}
	}

	setPositions();
}

void ScoreBoardView::setPositions()
{
	float maxWidth = m_scoreViews.begin()->get()->getGlobalBound().width;
	for (const auto& view : m_scoreViews)
	{
		const float width = view->getGlobalBound().width;
		if (width > maxWidth)
			maxWidth = width;
	}

	const float xPosition = (m_windowSize.x * 0.5) - (maxWidth * 0.5);
	float height = m_windowSize.y * 0.05;


	for (const auto& view : m_scoreViews)
	{
		view->setBackgroundColor(sf::Color::Transparent);
		view->setTextColor(sf::Color::Black);

		view->setPosition({ xPosition, height });
		height += view->getGlobalBound().height;
	}

	const auto bound = (--m_scoreViews.end())->get()->getGlobalBound();
	height = bound.top + bound.height;

	auto size = m_background.getSize();
	size.y = height;
	m_background.setSize(size);
}

sf::FloatRect ScoreBoardView::getGlobalBound() const
{
	return m_background.getGlobalBounds();
}

sf::Vector2f ScoreBoardView::getPosition() const
{
	return {};
}

void ScoreBoardView::setPosition(sf::Vector2f position)
{

}
