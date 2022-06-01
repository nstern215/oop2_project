#pragma once
#include "BaseView.h"

#define DEFAULT_FRAME_MARGIN 10

class TextView : public BaseView
{
public:
	TextView(std::string text, std::string fontName, unsigned int fontSize, int frameMargin = DEFAULT_FRAME_MARGIN);
	virtual void draw(sf::RenderWindow& window) override;

	sf::Vector2f getPosition() const override;
	void setPosition(sf::Vector2f position) override;
	
	void setFont(std::string fontName);
	void setFontSize(int fontSize);
	void setFrameMargin(float margin);
	void setTextColor(sf::Color color);
	void setBackgroundColor(sf::Color color);
	void setOutline(sf::Color color, int thikness);

	sf::FloatRect getGlobalBound() const override;
	
	void setText(std::string text);
	std::string getText() const;
private:
	void buildTextFrame();

	std::string str;
	
	sf::Text m_sfText;
	sf::RectangleShape m_textFrame;

	float m_frameMargin = DEFAULT_FRAME_MARGIN;
};
