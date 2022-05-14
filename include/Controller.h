#pragma once

#include <map>

#include "Mode.h"
#include "Components/BaseComponent.h"

class Controller
{
public:
	Controller();

private:
	Mode m_activeMode = OPENING_SCREEN;
	std::map<Mode, BaseComponent*> m_components;
};
