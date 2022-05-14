#pragma once

class ResourcesService
{
public:
	ResourcesService();
	~ResourcesService();

private:
	void loadResources();

	void loadFonts();
	void loadImages();
	void loadSpritesheet();
	void loadAudio();
};
