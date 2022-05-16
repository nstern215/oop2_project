#pragma once

class Resources
{
public:
	Resources();
	~Resources();

private:
	void loadResources();

	void loadFonts();
	void loadImages();
	void loadSpritesheet();
	void loadAudio();
};
