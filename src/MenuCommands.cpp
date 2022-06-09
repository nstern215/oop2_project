#include "MenuCommands.h"

ChangeModeCommand::ChangeModeCommand(Mode mode, Controller* controller, Metadata metadata) :
	m_mode(mode),
	m_controller(controller),
	m_metadata(metadata)
{}

void ChangeModeCommand::execute()
{
	m_controller->changeMode(m_mode, m_metadata);
}
