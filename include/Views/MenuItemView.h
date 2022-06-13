#pragma once
#include "TextView.h"

class MenuItemView : public TextView
{
public:
	MenuItemView(std::string title, std::string font, unsigned int fontSize, sf::Color selectedColor, bool isSelected = false);
	void selectedItem(bool selected);
	bool isSelected() const;
private:
	void buildFrame();

	bool m_isSelected;
	sf::Color m_outlineColor;

	const int m_OUTLINE_THIKNESS = 10;
};
