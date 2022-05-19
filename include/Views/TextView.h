#pragma once
#include "BaseView.h"

class TextView : public BaseView
{
public:
	TextView();
	void draw(sf::RenderWindow& window) override;
};
