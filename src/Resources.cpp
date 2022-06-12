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
	loadTextures();
	loadSpritesheet();
}

sf::Font* Resources::getFont(std::string fontName)
{
	if (!m_fonts.count(fontName))
		return nullptr;

	return m_fonts[fontName].get();
}

sf::Texture* Resources::getTexture(std::string textureName)
{
	if (!m_textures.count(textureName))
		return nullptr;

	return m_textures[textureName].get();
}

sf::Music* Resources::getMusic(std::string musicName)
{
	if (!m_audio.count(musicName))
		return nullptr;

	return m_audio[musicName].get();
}

void Resources::loadAudio()
{
	/*m_audio.insert({ "openning_track", std::make_unique<sf::Music>() });
	m_audio["openning_track"]->openFromFile("openning_track.mp3");*/
}

void Resources::loadFonts()
{
	m_fonts.insert({ "Tower", std::make_unique<sf::Font>() });
	m_fonts["Tower"]->loadFromFile("Tower.ttf");
}

void Resources::loadTextures()
{
	m_textures.insert({ "bricks_background", std::make_unique<sf::Texture>() });
	m_textures["bricks_background"]->loadFromFile("bricks_background.jpg");
}

void Resources::loadSpritesheet()
{
	
}