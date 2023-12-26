#include "newpackage.h"
#include "ui_newpackage.h"

NewPackage::NewPackage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewPackage)
{
    ui->setupUi(this);
}

NewPackage::~NewPackage()
{
    delete ui;
}
