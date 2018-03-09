#pragma once
#include <string>
#include <iostream>
#include <vector>

class Observer
{
public:
	virtual ~Observer() {}
	virtual void update() = 0;
};


class Subject
{
private:
	std::vector<Observer*> obs;
public:
	virtual ~Subject() {}
	void setObs(Observer* obs)
	{
		this->obs.push_back(obs);
	}

	void removeObs(Observer* obs)
	{
		this->obs.erase(find(this->obs.begin(), this->obs.end(), obs));
	}

	void notify()
	{
		for (auto s : this->obs)
			s->update();
	}
};