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
		item.draw(window);
}

void MenuComponent::eventHandler(sf::RenderWindow& window, sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		if (event.key.code == sf::Keyboard::Key::Down)
			selectNextItem();
		else if (event.key.code == sf::Keyboard::Key::Up)
			selectPreviousItem();
		else if (event.key.code == sf::Keyboard::Key::Space ||
			event.key.code == sf::Keyboard::Key::Enter)
		{
			//execute command
		}
		break;
	case sf::Event::MouseMoved:
		//const auto mousePosition = event.mouseMove

		for (auto i = m_items.begin(); i != m_items.end(); ++i)
		{
			if (m_selectedItem != i && i->getGlobalBound().contains(event.mouseMove.x, event.mouseMove.y))
			{
				m_selectedItem->selectedItem(false);
				m_selectedItem = i;
				m_selectedItem->selectedItem(true);
				break;
			}
		}
		break;
	}

	//todo: add mouse hover support
}

void MenuComponent::updateView()
{

}

void MenuComponent::active(Metadata& metadata)
{

}

void MenuComponent::buildMenu()
{
	std::vector<std::string> items = { "New Game", "Tutorial", "High Score", "Settings", "Exit" };
	for (const auto& item : items)
		addMenuItem(item);

	setItemsPosition();

	m_items.begin()->selectedItem(true);
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
		item.setPosition({ 10, height });
		height += 10 + item.getGlobalBound().height;
	}
}

void MenuComponent::addMenuItem(const std::string& title)
{
	m_items.emplace_back(title, m_MENU_ITEM_FONT, m_MENU_ITEM_FONT_SIZE, sf::Color::Green);
}

void MenuComponent::selectNextItem()
{
	m_selectedItem->selectedItem(false);

	if (++m_selectedItem == m_items.end())
		m_selectedItem = m_items.begin();

	m_selectedItem->selectedItem(true);
}

void MenuComponent::selectPreviousItem()
{
	m_selectedItem->selectedItem(false);

	if (m_selectedItem == m_items.begin())
		m_selectedItem = --m_items.end();
	else
		--m_selectedItem;

	m_selectedItem->selectedItem(true);
}
