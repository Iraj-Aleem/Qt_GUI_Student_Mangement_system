#include "findstudent.h"
#include "ui_findstudent.h"

FindStudent::FindStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindStudent)
{
    ui->setupUi(this);
}

FindStudent::~FindStudent()
{
    delete ui;
}
