#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include"registerstudent.h"
#include"findstudent.h"

#include"findpackage.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;

     RegisterStudent *ptrRegisterStudent;
     FindStudent *ptrFindStudent;
     FindPackage    *ptrFindPackage;
     //StudentManage  *ptrStudentManage;

};
#endif // MAINWINDOW_H
