#include "Quiz.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>

Quiz::Quiz(const int & id, const std::string & text, const std::string & correct, const int & score)
{
	this->id = id;
	this->text = text;
	this->correct = correct;
	this->score = score;
	this->ans = -1;
}

std::ostream & operator<<(std::ostream & os, Quiz & quiz)
{
	os << quiz.id << "," << quiz.text << "," << quiz.correct << "," << quiz.score << "\n";
	return os;
}

std::istream & operator >> (std::istream & is, Quiz & quiz)
{
	std::string line;
	std::getline(is, line);

	std::vector<std::string> result;
	std::stringstream ss(line);
	std::string token;
	while (std::getline(ss, token, ','))
		result.push_back(token);

	if (result.size() != 4)
		return is;

	quiz.id = stoi(result[0]);
	quiz.text = result[1];
	quiz.correct = result[2];
	quiz.score = stoi(result[3]);

	return is;
}
