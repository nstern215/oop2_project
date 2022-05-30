#include "Views/MenuItemView.h"

MenuItemView::MenuItemView(std::string title, std::string font, unsigned int fontSize, sf::Color selectedColor, bool isSelected) :
	m_isSelected(isSelected),
	m_outlineColor(selectedColor),
	TextView(std::move(title), std::move(font), fontSize)
{
	if (m_isSelected)
		setOutline(m_outlineColor, m_OUTLINE_THIKNESS);

	setTextColor(sf::Color::Blue);

	setBackgroundColor(sf::Color::Transparent);
}

void MenuItemView::selectedItem(bool selected)
{
	m_isSelected = selected;

	if (m_isSelected)
		setOutline(m_outlineColor, m_OUTLINE_THIKNESS);
	else
		setOutline(sf::Color::Transparent, 0);
}

bool MenuItemView::isSelected() const
{
	return m_isSelected;
}