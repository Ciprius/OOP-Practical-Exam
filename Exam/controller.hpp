#pragma once
#include <QWidget>
#include "Observer.h"
#include "ui_controller.h"
#include "Repository.h"
#include "Participant.h"
#include "Quiz.h"

class Controller : public QWidget , public Observer
{
	Q_OBJECT

public:
	Controller(Participant& p,Repository& repo,QWidget * parent = 0);
	~Controller();
	void update() override;
	void answer();
	void add();

private:
	Ui::Controller ui;
	Repository& repo;
	Participant par;
	int index();
private slots:
//void f();
	void itemchanged();
};
