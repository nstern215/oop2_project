#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

class Resources
{
public:
	~Resources();
	static Resources* instance();
	
	sf::Font* getFont(std::string& fontName);

private:
	Resources(const Resources&) = default;
	Resources();

	Resources& operator=(const Resources&) = default;

	static Resources* m_instance;
	
	void loadResources();

	void loadFonts();
	void loadImages();
	void loadSpritesheet();
	void loadAudio();

	std::map<std::string, std::unique_ptr<sf::Font>> m_fonts;
};
