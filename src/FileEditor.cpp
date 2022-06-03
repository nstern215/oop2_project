#include <fstream>

#include "FileEditor.h"

FileEditor::FileEditor(std::string& path):
	m_path(path)
{
}

std::vector<std::string>::iterator FileEditor::begin()
{
	return m_lines.begin();
}

std::vector<std::string>::iterator FileEditor::end()
{
	return m_lines.end();
}

void FileEditor::loadFile()
{
	std::ifstream input;
	input.open(m_path);

	if (!input.is_open())
	{
		createFile();
		return;
	}

	std::string line;
	while(!input.eof())
	{
		std::getline(input, line);
		m_lines.emplace_back(line);
	}

	input.close();
}

void FileEditor::updateFile()
{
	
}

void FileEditor::createFile()
{
	std::ofstream file;
	file.open(m_path);
	file.close();
}

std::vector<std::string> FileEditor::getLines() const
{
	return m_lines;
}
