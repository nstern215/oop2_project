#pragma once
#include "TextView.h"

class MenuItemView : public TextView
{
public:
	MenuItemView(std::string title, std::string font, unsigned int fontSize, sf::Color selectedColor, bool isActive = true, bool isSelected = false);
	void selectedItem(bool selected);
	bool isSelected() const;
	bool isItemActive() const;
	void setActive(bool active);
private:
	//void buildFrame();

	bool m_isSelected;
	bool m_isActive = true;
	sf::Color m_outlineColor;

	const int m_OUTLINE_THIKNESS = 10;
};
