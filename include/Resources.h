#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "AnimationData.h"

class Resources
{
public:
	enum Objects
	{
		Player,
		Max
	};
	
	~Resources();
	static Resources* instance();

	const AnimationData& animationData(Objects object) { return m_data[object]; }
	
	sf::Font* getFont(std::string fontName);
	sf::Texture* getTexture(std::string textureName);
	sf::Music* getMusic(std::string musicName);

private:
	Resources(const Resources&) = delete;
	Resources& operator=(const Resources&) = delete;
	
	Resources();

	static Resources* m_instance;
	
	void loadResources();

	void buildAnimation();

	void loadFonts();
	void loadTextures();
	void loadAudio();

	std::map<std::string, std::unique_ptr<sf::Font>> m_fonts;
	std::map<std::string, std::unique_ptr<sf::Texture>> m_textures;
	std::map<std::string, std::unique_ptr<sf::Music>> m_audio;
	std::map<std::string, sf::Texture> m_spriteTextures;

	std::vector<AnimationData> m_data;
};
