#include "Participant.h"

Participant::Participant(const std::string & name, const int & score)
{
	this->name = name;
	this->score = score;
}

std::istream & operator >> (std::istream & is, Participant & par)
{
	std::string line;
	std::getline(is, line);

	std::vector<std::string> result;
	std::stringstream ss(line);
	std::string token;
	while (std::getline(ss, token, ','))
		result.push_back(token);

	if (result.size() != 2)
		return is;

	par.name = result[0];
	par.score = stoi(result[1]);
	
	return is;
}
