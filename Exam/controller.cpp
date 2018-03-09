#include "controller.hpp"
#include <qmessagebox.h>


Controller::Controller(Participant& p, Repository& repo, QWidget * parent) : QWidget(parent), repo{ repo }, par{ p }
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(par.getName() + "-" + std::to_string(par.getScore())));
	this->repo.setObs(this);
	if (p.getName() == "Presenter")
	{

		for (auto s : this->repo.getQuiz())
		{
			QString item = QString::fromStdString("Id:" + std::to_string(s.getId()) + " Text:" + s.getText()+ " Answer:" +s.getCorrect() + " Score:"+ std::to_string(s.getScore()));
			QListWidgetItem* Item = new QListWidgetItem(item);
			this->ui.listWidget->addItem(Item);
		}
		this->ui.answerButton->setEnabled(false);
		QObject::connect(this->ui.addButton, &QPushButton::clicked, this, [&]() {this->add();});
	}
	else
	{
		this->ui.scoreEdit->hide();
		this->ui.textEdit->hide();
		this->ui.label_2->hide();
		this->ui.label_4->hide();
		this->repo.sort();
		for (auto s : this->repo.getQuiz())
		{
			QString item = QString::fromStdString("Id:" + std::to_string(s.getId()) + " Text:" + s.getText() + " Score:" + std::to_string(s.getScore()));
			QListWidgetItem* Item = new QListWidgetItem(item);
			this->ui.listWidget->addItem(Item);
		}
		this->ui.addButton->setEnabled(false);
		QObject::connect(this->ui.listWidget, SIGNAL(itemSelectionChanged()), this, SLOT(itemchanged()));
		QObject::connect(this->ui.answerButton, &QPushButton::clicked, this, [&]() {this->answer();});
	}
}

Controller::~Controller() 
{
	this->repo.removeObs(this);
}

void Controller::update()
{
	this->ui.listWidget->clear();
	if (par.getName() == "Presenter")
	{
		for (auto s : this->repo.getQuiz())
		{
			QString item = QString::fromStdString("Id:" + std::to_string(s.getId()) + " Text:" + s.getText() + " Answer:" + s.getCorrect() + " Score:" + std::to_string(s.getScore()));
			QListWidgetItem* Item = new QListWidgetItem(item);
			this->ui.listWidget->addItem(Item);
		}
	}
	else
	{
		for (auto s : this->repo.getQuiz())
		{
			QString item = QString::fromStdString("Id:" + std::to_string(s.getId()) + " Text:" + s.getText() + " Score:" + std::to_string(s.getScore()));
			QListWidgetItem* Item = new QListWidgetItem(item);
			this->ui.listWidget->addItem(Item);
		}
	}
}

void Controller::answer()
{
	std::string answeru = this->ui.answerEdit->text().toStdString();
	std::string id = this->ui.idEdit->text().toStdString();
	int Id = stoi(id);
	//this->a[Id]++;
	int c=this->repo.Answer(answeru,Id);
	QMessageBox msg;
	if (c != 0)
	{
		//par.setScore(c);
		par=this->repo.updatePart(this->par,c);
		this->setWindowTitle(QString::fromStdString(par.getName() + "-" + std::to_string(par.getScore())));
		msg.critical(0,"BAM","Good answer!");
	}
	else
		msg.critical(0, "BAM", "Wrong answer!");
}

void Controller::add()
{
	std::string id = this->ui.idEdit->text().toStdString();
	int Id = stoi(id);
	std::string text = this->ui.textEdit->text().toStdString();
	std::string correct = this->ui.answerEdit->text().toStdString();
	std::string score = this->ui.scoreEdit->text().toStdString();
	int Score = stoi(score);
	Quiz m{Id,text,correct,Score};
	try
	{
		this->repo.add(m,1);
	}
	catch (RepositoryException& e)
	{
		QMessageBox msg;
		msg.critical(0,"ERROR",e.what());
	}
	
}

int Controller::index()
{
	if (this->ui.listWidget->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = this->ui.listWidget->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->ui.answerEdit->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void Controller::itemchanged()
{
	if (par.getName() != "Presenter")
	{
		int index = this->index();
		if (index == -1)
			return;
		this->ui.idEdit->setText(QString::fromStdString(std::to_string(this->repo.getQuiz()[index].getId())));
		Quiz a = this->repo.getQuiz()[index];
		if (a.getans() == 1)
			this->ui.answerButton->setEnabled(false);
		else
			this->ui.answerButton->setEnabled(true);
	}
}
