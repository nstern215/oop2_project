#pragma once

#include <map>
#include <string>

class BaseComponent
{
public:
	BaseComponent();

	virtual void Active(std::map<std::string, std::string> metadata) = 0;
};
