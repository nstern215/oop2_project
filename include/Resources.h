#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <SFML/Graphics.hpp>
#include <vector>

class Resources
{
public:
	~Resources();
	static Resources* instance();
	
	sf::Font* getFont(std::string fontName);
	sf::Texture* getTexture(std::string textureName);
	sf::Music* getMusic(std::string musicName);

private:
	Resources(const Resources&) = default;
	Resources();

	Resources& operator=(const Resources&) = default;

	static Resources* m_instance;
	
	void loadResources();

	void loadFonts();
	void loadTextures();
	void loadSpritesheet();
	void loadAudio();

	std::map<std::string, std::unique_ptr<sf::Font>> m_fonts;
	std::map<std::string, std::unique_ptr<sf::Texture>> m_textures;
	std::map<std::string, std::unique_ptr<sf::Music>> m_audio;
};
