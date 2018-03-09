#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>

class Participant
{
public:
	Participant() : name(""),score(0) {}
	Participant(const std::string&  name, const int& score);

	std::string getName() { return this->name; }
	int getScore() { return this->score; }
	void setScore(int& sc) { this->score += sc; }
	friend std::istream& operator >> (std::istream& is, Participant& par);

private:
	std::string name;
	int score;
};
