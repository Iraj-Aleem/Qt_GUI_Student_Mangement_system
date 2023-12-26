#ifndef NEWPACKAGE_H
#define NEWPACKAGE_H

#include <QDialog>

namespace Ui {
class NewPackage;
}

class NewPackage : public QDialog
{
    Q_OBJECT

public:
    explicit NewPackage(QWidget *parent = nullptr);
    ~NewPackage();

private:
    Ui::NewPackage *ui;
};

#endif // NEWPACKAGE_H
