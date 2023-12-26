#include "mainwindow.h"
#include "./ui_mainwindow.h"

//#include"newpackage.h"
#include"registerstudent.h"
#include"findstudent.h"
#include"findpackage.h"
#include"students.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);


    //ptrNewPackage=new   NewPackage();
    ptrRegisterStudent=new  RegisterStudent();
    ptrFindStudent=new  FindStudent();
    ptrFindPackage=new  FindPackage();
   // ptrStudentManager=new   StudentManager();
}

MainWindow::~MainWindow()
{

    //delete  ptrNewPackage;
    delete  ptrRegisterStudent;
    delete  ptrFindStudent;
    delete  ptrFindPackage;
    //delete  ptrStudentManage;
    delete ui;
}




void MainWindow::on_pushButton_2_clicked()
{
    ptrRegisterStudent->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    ptrFindStudent->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    ptrFindPackage->show();
}


