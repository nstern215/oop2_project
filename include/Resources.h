#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Resources
{
public:

	static Resources& instance();

	Resources(const Resources&) = delete;
	Resources& operator=(const Resources&) = delete;

	const sf::Texture& texture() const { return m_texture; }

	//sf::Texture* getTexture(std::string textureName);
	//sf::Font* getFont(std::string fontName);

private:
	Resources();
	~Resources() = default;

	//void loadResources();

	//void loadFonts();
	//void loadImages();
	//void loadSpritesheet();
	//void loadAudio();

	sf::Texture m_texture;
};
