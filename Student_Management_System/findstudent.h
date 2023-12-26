#ifndef FINDSTUDENT_H
#define FINDSTUDENT_H

#include <QDialog>

namespace Ui {
class FindStudent;
}

class FindStudent : public QDialog
{
    Q_OBJECT

public:
    explicit FindStudent(QWidget *parent = nullptr);
    ~FindStudent();

private:
    Ui::FindStudent *ui;
};

#endif // FINDSTUDENT_H
