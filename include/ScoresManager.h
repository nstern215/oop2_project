#pragma once
#include <string>
#include <vector>

#define DEFAULT_NUM_OF_SCORES 10

class ScoresManager
{
public:
	ScoresManager(int numOfScores = DEFAULT_NUM_OF_SCORES, std::vector<std::string> scores = {});
	void updateScores(std::vector<std::string> scores);
	bool isNewScore(int score) const;
	std::vector<std::string> getScoresList() const;
	void addNewScore(std::string name, int score);
	int getHigherstScore() const;

private:
	void sortScores();
	int extractScoreFromLine(std::string line) const;
	
	std::vector<std::string> m_scores;
	const int m_NUM_OF_SCORES;
};
