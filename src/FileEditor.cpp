#include <fstream>

#include "FileEditor.h"

FileEditor::FileEditor(const std::string& path):
	m_path(path)
{
	loadFile();
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

void FileEditor::updateFile(const std::vector<std::string>& lines) const
{
	std::ofstream output;
	output.open(m_path);

	for (const auto& line : lines)
		output << line << std::endl;

	output.close();
}

void FileEditor::createFile() const
{
	std::ofstream file;
	file.open(m_path);
	file.close();
}

std::vector<std::string> FileEditor::getLines() const
{
	return m_lines;
}
