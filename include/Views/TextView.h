#pragma once
#include "BaseView.h"

class TextView : public BaseView
{
public:
	TextView();
	void draw(sf::Window& window) override;
};
