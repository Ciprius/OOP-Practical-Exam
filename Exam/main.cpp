#include "exam.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <string>
#include "Repository.h"
#include "controller.hpp"
#include "Participant.h"
#include <vector>
#include <assert.h>
#include "Exception.h"

void tests()
{
	Repository r("text.txt", "text1.txt");
	assert(r.getQuiz().size() == 6);
	Quiz m{10,"sdfs","fff",55};
	r.add(m,0);
	assert(r.getQuiz().size() == 7);
	try
	{
		Quiz m1{ 10,"sdfs","fff",55 };
		r.add(m1, 0);
	}
	catch (RepositoryException& e)
	{
		assert(e.what() == "There is another quiz with the same id!");
	}

}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	void test();
	Repository repo("text.txt","text1.txt");
	Participant p{"Presenter",0};

	Controller c(p,repo);
	c.show();

	std::ifstream file("text1.txt");
	Participant part;
	std::vector<Controller*> vec;
	while (file >> part)
	{
		Controller * cont = new Controller(part,repo);
		vec.push_back(cont);
	}

	for (auto s : vec)
		s->show();

	return a.exec();
}
