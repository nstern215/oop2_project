#pragma once

#include <map>
#include <string>

#include "Mode.h"

class Controller;

class BaseComponent
{
public:
	BaseComponent() = default;
	virtual ~BaseComponent() = default;

	virtual void active();
	virtual void active(std::map<std::string, std::string>& metadata) = 0;

protected:
	void (Controller::*m_changeModeFunc)(Mode, std::map<std::string, std::string>);
};
