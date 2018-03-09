#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Exception.h"
#include "Observer.h"
#include "Quiz.h"
#include "Participant.h"
#include <map>
#include <vector>

class Repository :public Subject
{
public:
	Repository(const std::string& filename,const std::string& filename1)
	{
		this->filename = filename;
		this->filenam1 = filename1;
		this->readFromfile();
	}

	std::vector<Quiz> getQuiz() { return this->list; }
	
	void add(Quiz& m,const int& cond)
	{
		//This function adds a new element to the list
		//Input:m- the element which we have to add
		for (auto s : this->list)
			if (s.getId() == m.getId())
				throw DuplicateException();
		this->list.push_back(m);
		if (cond == 1)
		{
			this->wrieToFile();
			this->notify();
		}
	}

	int Answer(std::string& ans,int& id )
	{
		//This function answer to a question
		//Input:ans- is the answer to the question to be checked
		//Output:returns the postition of the element which has the score
		int c = 0;
		for (auto s : this->list)
			if (s.getCorrect() == ans)
				c++;

		for (int i = 0; i < this->list.size();i++)
			if (this->list[i].getId() == id)
				this->list[i].setans();
		this->notify();
		if (c == 0)
			return 0;
		else
			return this->list[c].getScore();
	}

	void sort()
	{
		Quiz aux;
		for (int i=0 ;i < this->list.size() -1 ;i++)
			for (int j=i+1;j < this->list.size(); j++)
				if (this->list[i].getScore() < this->list[j].getScore())
				{
					aux = this->list[i];
					this->list[i] = this->list[j];
					this->list[j] = aux;
				}
	}


	Participant updatePart(Participant& part,int& score)
	{
		part.setScore(score);
		return part;
	}
private:
	std::vector<Quiz> list;
	std::vector<Participant> part;
	std::string filename;
	std::string filenam1;

	void readFromfile()
	{
		std::ifstream file(this->filename);

		Quiz q;
		while (file >> q)
		{
			list.push_back(q);
		}
		file.close();

		Quiz aux;
		for (int i=0;i< this->list.size()-1;i++)
			for (int j=i+1;j<this->list.size();j++)
				if (this->list[i].getId() > this->list[j].getId())
				{
					aux = this->list[i];
					this->list[i] = this->list[j];
					this->list[j] = aux;
				}

		std::ifstream file1(this->filenam1);
		Participant parti;
		while (file1 >> parti)
		{
			part.push_back(parti);
		}
		file1.close();
	}

	void wrieToFile()
	{
		std::ofstream file(this->filename);
		for (auto s : this->list)
			file << s;

	}
};