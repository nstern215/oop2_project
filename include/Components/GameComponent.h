#pragma once
#include "BaseComponent.h"

class Controller;

class GameComponent : public BaseComponent
{
public:
	GameComponent(void (Controller::*changeModeFunc)(Mode, std::map<std::string, std::string>));

	void active(std::map<std::string, std::string>& metadata) override;
};
