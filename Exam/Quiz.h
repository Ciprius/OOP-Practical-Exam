#pragma once
#include <string>

class Quiz
{
private:
	std::string text;
	std::string correct;
	int id;
	int score;
	int ans;
public:
	Quiz() {}
	Quiz(const int& id, const std::string& text, const std::string& correct, const int& score);
	int getId() { return this->id; }
	int getScore() { return this->score; }
	std::string getText() { return this->text; }
	std::string getCorrect() { return this->correct; }
	int getans() { return this->ans; }
	void setans() { this->ans = 1; }
	friend std::ostream& operator<<(std::ostream& os,Quiz& quiz);
	friend std::istream& operator>>(std::istream& is, Quiz& quiz);
};