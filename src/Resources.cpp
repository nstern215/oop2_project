#include "Resources.h"

Resources* Resources::m_instance = nullptr;

Resources* Resources::instance()
{
	if (m_instance == nullptr)
		m_instance = new Resources();

	return m_instance;
}


Resources::Resources()
{
	loadResources();
}

Resources::~Resources()
{
	delete m_instance;
}

void Resources::loadResources()
{
	loadAudio();
	loadFonts();
	loadImages();
	loadSpritesheet();
}

sf::Font* Resources::getFont(std::string& fontName)
{
	if (!m_fonts.count(fontName))
		return nullptr;

	return m_fonts[fontName].get();
}

void Resources::loadAudio()
{
	
}

void Resources::loadFonts()
{
	m_fonts.insert({ "Tower", std::make_unique<sf::Font>() });
	m_fonts["Tower"]->loadFromFile("Tower.ttf");
}

void Resources::loadImages()
{
	
}

void Resources::loadSpritesheet()
{
	
}