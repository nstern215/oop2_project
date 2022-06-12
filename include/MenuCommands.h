#pragma once
#include "Command.h"

class ChangeModeCommand : public Command
{
public:
	ChangeModeCommand(Mode mode, Controller* controller, Metadata metadata = {});
	void execute() override;
private:
	const Mode m_mode;
	Controller* m_controller;
	Metadata m_metadata;
};

class ExitCommand : public Command
{
public:
	void execute() override;
};
