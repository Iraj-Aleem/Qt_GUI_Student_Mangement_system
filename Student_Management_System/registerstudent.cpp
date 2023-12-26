#include "registerstudent.h"
#include "ui_registerstudent.h"

RegisterStudent::RegisterStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterStudent)
{
    ui->setupUi(this);
}

RegisterStudent::~RegisterStudent()
{
    delete ui;
}

void RegisterStudent::on_btnSave_clicked()
{
    QString StudentID=ui->txtStudentId->text();
    QString FirstName=ui->txtFirstName->text();
    QString LastName=ui->txtLastName->text();
    QString ContactNumber=ui->txtContactNo->text();
    QString PermanentAddress=ui->txtPermanentAddress->text();
    //QString ChooseDeparment=ui->cmbChooseDepartment->text();
    qDebug()  <<  "First  Name:"<<FirstName<<"Last Name:"<<LastName<<"Contact Number"
           <<ContactNumber<<"Permanent  Address"<<PermanentAddress;
    QSqlDatabase    database =   QSqlDatabase::addDatabase("QSQLITE");

  // database.setDatabaseName("C:/Users/Administrator/Documents/database/database");
    database.setDatabaseName("C:/Users/Administrator/Documents/Student_Management_System/database");

   // if(QFile::exists("C:/Users/Administrator/Documents/database/database"))
    if(QFile::exists("C:/Users/Administrator/Documents/Student_Management_System/database"))
    {
        qDebug()    <<"Database file    exist";
    }
    else{
        qDebug()    <<"Database file    does    not exist";
        return;
    }
    if(!database.open())
    {
        qDebug()    <<"Error:Unable to  open    Database";
        return;
    }
    else{
        qDebug()    <<"Database open    successfully";
    }

    QSqlQuery   query(database);
    query.prepare("insert   into    Student(StudentID,FirstName,LastName,ContactNumber,PermanentAddress)   values('"+StudentID+"','"+FirstName+"','"+LastName+"','"+ContactNumber+"','+"+PermanentAddress+"')");
    query.exec();
    //qDebug()<<"Last Error:"<<query.lastError().text();
    database.close();
}
