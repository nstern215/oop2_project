#pragma once
#include "BaseComponent.h"
#include "Views/MenuItemView.h"

class MenuComponent : public BaseComponent
{
public:
	MenuComponent(void (Controller::* changeModeFunc)(Mode, Metadata), Controller* controller, sf::Vector2u windowSize);
	void updateView() override;
	void draw(sf::RenderWindow& window) override;
	void eventHandler(sf::RenderWindow& window, sf::Event& event) override;
	void active(Metadata& metadata) override;

private:
	void buildMenu();
	void addMenuItem(const std::string& title);
	void setItemsPosition();
	void selectNextItem();
	void selectPreviousItem();
	
	std::vector<MenuItemView> m_items;
	std::vector<MenuItemView>::iterator m_selectedItem;
	
	const std::string m_MENU_ITEM_FONT = "Tower";
	const int m_MENU_ITEM_FONT_SIZE = 60;

	const sf::Vector2u m_WINDOW_SIZE;
};
