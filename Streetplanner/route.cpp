#include "route.h"
#include "ui_route.h"

Route::Route(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Route)
{
    ui->setupUi(this);
}

Route::~Route()
{
    delete ui;
}

void Route::setStart()
{
    start = ui->lineEdit_start->text();
}

void Route::setZiel()
{
    ziel = ui->lineEdit_ziel->text();
}

QString Route::getStart()
{
    return start;
}

 QString Route::getZiel()
{
    return ziel;
}
