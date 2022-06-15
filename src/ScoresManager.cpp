#include <algorithm>

#include "ScoresManager.h"

ScoresManager::ScoresManager(int numOfScores, std::vector<std::string> scores) :
	m_scores(std::move(scores)),
	m_NUM_OF_SCORES(numOfScores)
{	
	sortScores();

	if (m_scores.size() > m_NUM_OF_SCORES)
	{
		for (int i = 0; i < m_NUM_OF_SCORES - m_scores.size(); ++i)
		{
			m_scores.pop_back();
		}
	}
}

std::vector<std::string> ScoresManager::getScoresList() const
{
	return m_scores;
}

void ScoresManager::updateScores(std::vector<std::string> scores)
{
	m_scores = std::move(scores);
}

void ScoresManager::sortScores()
{
	std::ranges::sort(m_scores.begin(), m_scores.end(), [this](const auto& a, const auto& b)->bool
		{
			return extractScoreFromLine(a) > extractScoreFromLine(b);
		});
}

int ScoresManager::extractScoreFromLine(std::string line) const
{
	char* charLine = const_cast<char*>(line.c_str());
	
	char* token = strtok(charLine, " ");

	char* prev = nullptr;
	while (token != nullptr)
	{
		prev = token;
		token = strtok(nullptr, " ");
	}

	return prev ? std::stoi(prev) : 0;
}

int ScoresManager::getHigherstScore() const
{
	const auto maxScoreLine = std::ranges::min_element(m_scores, [this](const auto& a, const auto& b)
		{
			return extractScoreFromLine(a) < extractScoreFromLine(b);
		});

	return extractScoreFromLine(*maxScoreLine);
}

bool ScoresManager::isNewScore(int score) const
{
	const auto minScoreLine = std::ranges::min_element(m_scores, [this](const auto& a, const auto& b)
		{
			return extractScoreFromLine(a) < extractScoreFromLine(b);
		});

	if (minScoreLine == m_scores.end() || extractScoreFromLine(*minScoreLine) < score)
		return true;

	return false;
}

void ScoresManager::addNewScore(std::string name, int score)
{
	std::string line = name;
	line += " ";
	line += std::to_string(score);
	
	m_scores.emplace_back(line);
	sortScores();

	if (m_scores.size() > m_NUM_OF_SCORES)
	{
		for (int i = 0; i < m_NUM_OF_SCORES - m_scores.size(); ++i)
		{
			m_scores.pop_back();
		}
	}
}
