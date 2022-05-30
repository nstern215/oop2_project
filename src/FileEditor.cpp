#include "FileEditor.h"

FileEditor::FileEditor(std::string&& path):
	m_path(path)
{
}

std::vector<std::string>::const_iterator FileEditor::getLinesIterator() const
{
	return m_lines.cbegin();
}

void FileEditor::loadFile()
{

}

void FileEditor::updateFile()
{
	
}
