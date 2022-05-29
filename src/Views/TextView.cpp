#include "Views/TextView.h"

#include "Resources.h"

TextView::TextView(std::string text, std::string fontName, unsigned int fontSize, int frameMargin)
{
	m_sfText.setString(text);
	m_sfText.setFont(*Resources::instance()->getFont(fontName));
	m_sfText.setCharacterSize(fontSize);

	buildTextFrame();
}

void TextView::draw(sf::RenderWindow& window)
{
	window.draw(m_textFrame);	
	window.draw(m_sfText);
}

std::string TextView::getText() const
{
	return m_sfText.getString();
}

void TextView::setText(std::string text)
{
	m_sfText.setString(text);
	buildTextFrame();
}

void TextView::setFont(std::string fontName)
{
	m_sfText.setFont(*Resources::instance()->getFont(fontName));
}

void TextView::setBackgroundColor(sf::Color color)
{
	m_textFrame.setFillColor(color);
}

void TextView::setFontSize(int fontSize)
{
	m_sfText.setCharacterSize(fontSize);
}

void TextView::setTextColor(sf::Color color)
{
	m_sfText.setFillColor(color);
}

void TextView::setFrameMargin(float margin)
{
	m_frameMargin = margin;
}

sf::Vector2f TextView::getPosition() const
{
	return m_sfText.getPosition();
}

void TextView::setPosition(sf::Vector2f position)
{
	m_sfText.setPosition(position.x, position.y);
	buildTextFrame();
}

void TextView::buildTextFrame()
{
	const auto textBound = m_sfText.getGlobalBounds();

	m_textFrame.setPosition(textBound.left - m_frameMargin, textBound.top - m_frameMargin);
	m_textFrame.setSize({textBound.width + 2 * m_frameMargin, textBound.height + 2 * m_frameMargin });
}
