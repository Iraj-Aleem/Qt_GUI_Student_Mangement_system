#include "findpackage.h"
#include "ui_findpackage.h"

FindPackage::FindPackage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindPackage)
{
    ui->setupUi(this);

}

FindPackage::~FindPackage()
{
    delete ui;
}
