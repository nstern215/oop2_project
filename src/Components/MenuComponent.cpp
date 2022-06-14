#include <algorithm>

#include "Components/MenuComponent.h"

#include "Controller.h"
#include "Resources.h"

MenuComponent::MenuComponent(void (Controller::* changeModeFunc)(Mode, Metadata), Controller* controller, sf::Vector2u windowSize) :
	m_WINDOW_SIZE(windowSize),
	m_selectedItem(m_items.end())
{
	m_changeModeFunc = changeModeFunc;
	m_controller = controller;

	m_sound.setBuffer(*Resources::instance()->getMusic("opening_track"));
	m_sound.setLoop(true);
	m_sound.setVolume(100);
	
	buildBackground();
	buildMenu();
}

void MenuComponent::draw(sf::RenderWindow& window)
{
	window.draw(m_background);
	
	for (auto& item : m_items)
		item.first->draw(window);
}

void MenuComponent::eventHandler(sf::RenderWindow& window, sf::Event& event)
{
	//auto status = m_music->getStatus();
	
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

			m_sound.stop();
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
	case sf::Event::MouseButtonReleased:
		if (event.mouseButton.button == sf::Mouse::Button::Left)
			for (const auto& item : m_items)
				if (item.first->getGlobalBound().contains(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
				{
					m_sound.stop();
					item.second->execute();
					break;
				}
		break;
	}
}

void MenuComponent::updateView()
{

}

void MenuComponent::active(Metadata& metadata)
{
	m_sound.play();
}

void MenuComponent::buildMenu()
{
	m_items.emplace_back(std::make_pair(createMenuItem("New Game"), std::make_unique<ChangeModeCommand>(GAME, m_controller)));
	m_items.emplace_back(std::make_pair(createMenuItem("Tutorial"), std::make_unique<ChangeModeCommand>(TUTORIAL, m_controller) ));
	m_items.emplace_back(std::make_pair(createMenuItem("High Score"), std::make_unique<ChangeModeCommand>(SCORE_BOARD, m_controller) ));
	//m_items.emplace_back(std::make_pair(createMenuItem("Settings"), std::make_unique<ChangeModeCommand>(, m_controller) ));
	m_items.emplace_back(std::make_pair(createMenuItem("Exit"), std::make_unique<ExitCommand>() ));

	setItemsPosition();

	m_items.begin()->first->selectedItem(true);
	m_selectedItem = m_items.begin();
}

void MenuComponent::setItemsPosition()
{
	const auto midWindow = m_WINDOW_SIZE.x / 2;

	float itemsHeight = 0;

	for (const auto& item : m_items)
		itemsHeight += item.first->getGlobalBound().height;

	float height = midWindow - itemsHeight / 2;
	
	for (auto& item : m_items)
	{
		const auto width = item.first->getGlobalBound().width;
		item.first->setPosition({ midWindow - (width / 2), height });
		height += item.first->getGlobalBound().height;
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
void MenuComponent::buildBackground()
{
	m_background.setSize({ static_cast<float>(m_WINDOW_SIZE.x), static_cast<float>(m_WINDOW_SIZE.y) });
	m_background.setTexture(Resources::instance()->getTexture(m_BACKGROUND_TEXTURE));
}
