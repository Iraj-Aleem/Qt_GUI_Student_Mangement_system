#ifndef REGISTERSTUDENT_H
#define REGISTERSTUDENT_H

#include <QDialog>
#include"databaseheader.h"
namespace Ui {
class RegisterStudent;
}

class RegisterStudent : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterStudent(QWidget *parent = nullptr);
    ~RegisterStudent();

private slots:
    void on_btnSave_clicked();

private:
    Ui::RegisterStudent *ui;
};

#endif // REGISTERSTUDENT_H
