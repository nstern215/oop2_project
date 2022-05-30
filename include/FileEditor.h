#pragma once
#include <string>
#include <vector>

class FileEditor
{
public:
	FileEditor(std::string&& path);

	void loadFile();
	std::vector<std::string>::const_iterator getLinesIterator() const;
	void updateFile();

private:
	std::string m_path;
	std::vector<std::string> m_lines;
};
