#pragma once
#include "BaseComponent.h"
#include "Command.h"
#include "MenuCommands.h"
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
	typedef std::pair<std::unique_ptr<MenuItemView>, std::unique_ptr<Command>> option;
	
	void buildMenu();
	std::unique_ptr<MenuItemView> createMenuItem(const std::string& title);
	void setItemsPosition();
	void selectNextItem();
	void selectPreviousItem();

	std::vector<option> m_items;
	std::vector<option>::iterator m_selectedItem;
	/*std::vector<std::unique_ptr<MenuItemView>> m_items;
	std::vector<std::unique_ptr<MenuItemView>>::iterator m_selectedItem;*/
	
	const std::string m_MENU_ITEM_FONT = "Tower";
	const int m_MENU_ITEM_FONT_SIZE = 60;

	const sf::Vector2u m_WINDOW_SIZE;
};
