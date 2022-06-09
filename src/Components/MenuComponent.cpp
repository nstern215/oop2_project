#include <algorithm>

#include "Components/MenuComponent.h"

#include "Controller.h"

MenuComponent::MenuComponent(void (Controller::* changeModeFunc)(Mode, Metadata), Controller* controller, sf::Vector2u windowSize) :
	m_WINDOW_SIZE(windowSize),
	m_selectedItem(m_items.end())
{
	m_changeModeFunc = changeModeFunc;
	m_controller = controller;

	buildMenu();
}

void MenuComponent::draw(sf::RenderWindow& window)
{
	for (auto& item : m_items)
		item.first->draw(window);
}

void MenuComponent::eventHandler(sf::RenderWindow& window, sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyReleased:
		switch (event.key.code)
		{
		case sf::Keyboard::Key::Down:
				selectNextItem();
				break;
		case sf::Keyboard::Key::Up:
				selectPreviousItem();
				break;
		case sf::Keyboard::Key::Space:
		case sf::Keyboard::Key::Enter:
			
			m_selectedItem->second->execute();
			break;
		}
		break;
	case sf::Event::MouseMoved:
		for (auto i = m_items.begin(); i != m_items.end(); ++i)
		{
			if (m_selectedItem != i && i->first->getGlobalBound().contains(event.mouseMove.x, event.mouseMove.y))
			{
				m_selectedItem->first->selectedItem(false);
				m_selectedItem = i;
				m_selectedItem->first->selectedItem(true);
				break;
			}
		}
		break;
	}
}

void MenuComponent::updateView()
{

}

void MenuComponent::active(Metadata& metadata)
{

}

void MenuComponent::buildMenu()
{
	m_items.push_back({ createMenuItem("New Game"), std::make_unique<ChangeModeCommand>(GAME, m_controller) });
	m_items.push_back({ createMenuItem("Tutorial"), std::make_unique<ChangeModeCommand>(TUTORIAL, m_controller) });
	m_items.push_back({ createMenuItem("High Score"), std::make_unique<ChangeModeCommand>(SCORE_BOARD, m_controller) });
	/*m_items.push_back({ createMenuItem("Settings"), std::make_unique<ChangeModeCommand>(, m_controller) });*/
	m_items.push_back({ createMenuItem("Exit"), std::make_unique<ChangeModeCommand>(GAME, m_controller) });
	
	/*std::vector<std::string> items = { "New Game", "Tutorial", "High Score", "Settings", "Exit" };
	for (const auto& item : items)
		createMenuItem(item);*/

	setItemsPosition();

	m_items.begin()->first->selectedItem(true);
	m_selectedItem = m_items.begin();
}

void MenuComponent::setItemsPosition()
{
	auto midWindow = m_WINDOW_SIZE.x / 2;
	float height = 0;

	/*const auto item = std::max_element(m_items.begin(), m_items.end(), [](const auto& item) {return item.getGlobalBound().width; });
	auto maxItemBound = item->getGlobalBound().width;*/

	for (auto& item : m_items)
	{
		item.first->setPosition({ 10, height });
		height += 10 + item.first->getGlobalBound().height;
	}
}

std::unique_ptr<MenuItemView> MenuComponent::createMenuItem(const std::string& title)
{
	return std::make_unique<MenuItemView>(title, m_MENU_ITEM_FONT, m_MENU_ITEM_FONT_SIZE, sf::Color::Green);
}

void MenuComponent::selectNextItem()
{
	m_selectedItem->first->selectedItem(false);

	if (++m_selectedItem == m_items.end())
		m_selectedItem = m_items.begin();

	m_selectedItem->first->selectedItem(true);
}

void MenuComponent::selectPreviousItem()
{
	m_selectedItem->first->selectedItem(false);

	if (m_selectedItem == m_items.begin())
		m_selectedItem = --m_items.end();
	else
		--m_selectedItem;

	m_selectedItem->first->selectedItem(true);
}
