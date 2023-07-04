#include "dialogstreet.h"
#include "ui_dialogstreet.h"

DialogStreet::DialogStreet(QWidget *parent) :  // constructor for Dialog class,it initializes a new Ui::Dialog and calls setupUi to create the user interface.
    QDialog(parent),
    ui(new Ui::DialogStreet)
{
    ui->setupUi(this);
}

DialogStreet::~DialogStreet()
{
    delete ui;
}

void DialogStreet::strasseErstellen()
{
    strasseStadt1 = ui->lineEdit_street_stadt1->text();
    strasseStadt2 = ui->lineEdit_street_stadt2->text();
}

QString DialogStreet::getStrasseStadt1()
{
    return strasseStadt1;
}

QString DialogStreet::getStrasseStadt2()
{
    return strasseStadt2;
}
