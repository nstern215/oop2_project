#pragma once
#include <string>
#include <vector>

class FileEditor
{
public:
	FileEditor(std::string& path);

	void loadFile();
	std::vector<std::string>::iterator begin();
	std::vector<std::string>::iterator end();

	std::vector<std::string> getLines() const;
	
	void updateFile();

private:
	void createFile();
	
	std::string m_path;
	std::vector<std::string> m_lines;
};
