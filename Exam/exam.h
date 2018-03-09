#ifndef EXAM_H
#define EXAM_H

#include <QtWidgets/QMainWindow>
#include "ui_exam.h"

class Exam : public QMainWindow
{
	Q_OBJECT

public:
	Exam(QWidget *parent = 0);
	~Exam();

private:
	Ui::ExamClass ui;
};

#endif // EXAM_H
