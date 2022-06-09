#pragma once
#include "Controller.h"

class Command
{
public:
	virtual ~Command() = default;
	virtual void execute() = 0;
};
