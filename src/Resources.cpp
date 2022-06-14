#include "Resources.h"

Resources* Resources::m_instance = nullptr;

namespace
{
	AnimationData playerData()
	{
		const auto size = sf::Vector2i(30, 57);
		const auto initSpace = sf::Vector2i(5, 8);
		const auto middleSpace = sf::Vector2i(7, 0);

		auto player = AnimationData{};
		auto currentStart = initSpace;

		auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};

		player.m_data[Direction::Stay].emplace_back(currentStart, size);
		player.m_data[Direction::Stay].emplace_back(nextStart(), size);
		player.m_data[Direction::Stay].emplace_back(nextStart(), size);

		player.m_data[Direction::Right].emplace_back(nextStart(), size);
		player.m_data[Direction::Right].emplace_back(nextStart(), size);
		player.m_data[Direction::Right].emplace_back(nextStart(), size);
		player.m_data[Direction::Right].emplace_back(nextStart(), size);

		player.m_data[Direction::Up].emplace_back(nextStart(), size);

		player.m_data[Direction::Down] = player.m_data[Direction::Up];
		player.m_data[Direction::Left] = player.m_data[Direction::Right];

		return player;
	}
}

Resources* Resources::instance()
{
	if (m_instance == nullptr)
		m_instance = new Resources();

	return m_instance;
}


Resources::Resources():
	m_data(Max)
{
	loadResources();

	buildAnimation();
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

sf::SoundBuffer* Resources::getMusic(std::string musicName)
{
	if (!m_audio.count(musicName))
		return nullptr;

	return m_audio[musicName].get();
}

void Resources::loadAudio()
{
	std::vector<std::string> audio = { "opening_track",
		"100_floors",
		"alarm",
		"game_over",
		"new_high_score",
		"new_record_claps" };

	for (const auto& item : audio)
	{
		m_audio.insert({ item, std::make_unique<sf::SoundBuffer>() });

		std::string trackName(item);
		trackName += ".wav";
		m_audio[item]->loadFromFile(trackName);
	}	
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

	m_textures.insert({ "game_sprite", std::make_unique<sf::Texture>() });
	m_textures["game_sprite"]->loadFromFile("icytower_sprite.png");
}

void Resources::buildAnimation()
{
	m_data[Player] = playerData();
}
