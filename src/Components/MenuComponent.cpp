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
		if (item.first->isItemActive())
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

			m_sound.stop();
			m_selectedItem->second->execute();
			break;
		case sf::Keyboard::Key::Escape:
			if (isItemActive("Resume"))
			{
				m_sound.stop();
				runItemCommand("Resume");
			}
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
	if (metadata.count("status") != 0)
	{
		auto changeItemActive = [&](const std::string itemName, bool active)
		{
			const auto foundItem = std::ranges::find_if(m_items.begin(), m_items.end(), [itemName, active](const option& item)
				{
					return item.first->getText() == itemName;
				});

			foundItem->first->setActive(active);
		};

		const auto status = metadata["status"];

		if (status == "pause")
		{
			changeItemActive("New Game", false);
			changeItemActive("Resume", true);
		}
		else
		{
			changeItemActive("New Game", true);
			changeItemActive("Resume", false);
		}
		

		setItemsPosition();
	}

	m_sound.play();
}

void MenuComponent::buildMenu()
{
	const Metadata newGame = { {"status", "new"} };
	const Metadata resumeGmae = { {"status", "resume"} };

	m_items.emplace_back(std::make_pair(createMenuItem("New Game"), std::make_unique<ChangeModeCommand>(GAME, m_controller, newGame)));
	m_items.emplace_back(std::make_pair(createMenuItem("Resume", false), std::make_unique<ChangeModeCommand>(GAME, m_controller, resumeGmae)));
	m_items.emplace_back(std::make_pair(createMenuItem("Tutorial"), std::make_unique<ChangeModeCommand>(TUTORIAL, m_controller)));
	m_items.emplace_back(std::make_pair(createMenuItem("High Score"), std::make_unique<ChangeModeCommand>(SCORE_BOARD, m_controller)));
	m_items.emplace_back(std::make_pair(createMenuItem("Exit"), std::make_unique<ExitCommand>()));

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
		if (item.first->isItemActive())
		{
			const auto width = item.first->getGlobalBound().width;
			item.first->setPosition({ midWindow - (width / 2), height });
			height += item.first->getGlobalBound().height;
		}
	}
}

std::unique_ptr<MenuItemView> MenuComponent::createMenuItem(const std::string& title, bool isActive) const
{
	return std::make_unique<MenuItemView>(title, m_MENU_ITEM_FONT, m_MENU_ITEM_FONT_SIZE, sf::Color::Green, isActive);
}

void MenuComponent::selectNextItem()
{
	do
	{
		m_selectedItem->first->selectedItem(false);

		if (++m_selectedItem == m_items.end())
			m_selectedItem = m_items.begin();

		m_selectedItem->first->selectedItem(true);
	} while (!m_selectedItem->first->isItemActive());
}

void MenuComponent::selectPreviousItem()
{
	do
	{
		m_selectedItem->first->selectedItem(false);

		if (m_selectedItem == m_items.begin())
			m_selectedItem = --m_items.end();
		else
			--m_selectedItem;

		m_selectedItem->first->selectedItem(true);
	} while (!m_selectedItem->first->isItemActive());
}
void MenuComponent::buildBackground()
{
	m_background.setSize({ static_cast<float>(m_WINDOW_SIZE.x), static_cast<float>(m_WINDOW_SIZE.y) });
	m_background.setTexture(Resources::instance()->getTexture(m_BACKGROUND_TEXTURE));
}

bool MenuComponent::isItemActive(std::string item)
{
	const auto foundItem = std::ranges::find_if(m_items.begin(), m_items.end(), [item](const option& opt)
		{
			return opt.first->getText() == item;
		});

	return foundItem == m_items.end() ? false : foundItem->first->isItemActive();
}

void MenuComponent::runItemCommand(std::string item)
{
	const auto foundItem = std::ranges::find_if(m_items.begin(), m_items.end(), [item](const option& opt)
		{
			return opt.first->getText() == item;
		});

	foundItem->second->execute();
}
