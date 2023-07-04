#include "dialog.h"
#include <QMessagebox>
#include "ui_dialog.h"
#include "city.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

/**
 * @brief Funktion, die das Dialogfenster öffnet, in der man eine Stadt erstellen kann
 *
 * Diese Funktion stellt ein Fenster bereit, die alle notwendigen Parameter zum
 * erstellen einer Stadt, wie Name und Koordinaten, abfragt
 *
 */
bool Dialog::stadtErstellen()
{
    QString stadtName = ui->lineEdit_stadtname_eingabe->text();
    QString xKoordinate = ui->lineEdit_x_eingabe->text();
    QString yKoordinate = ui ->lineEdit_y_eingabe->text();
    bool okX;
    bool okY;
    int x = xKoordinate.toInt(&okX);
    int y = yKoordinate.toInt(&okY);
    std::string name = stadtName.toStdString();
    std::size_t found = name.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZÄÖÜabcdefghijklmnopqrstuvwxyzäöü -");
    if (found != std::string::npos)
    {
        QMessageBox::critical(0, "Error", "Der Stadtname darf nur alphabetische Zeichen, Umlaute, Leerzeichen und Bindestriche enthalten ");
        return false;
    }

    if (okX && okY)
    {
        this->stadt = new City(stadtName, x, y);
        return true;
    }
    else
    {
        QMessageBox::critical(0, "Error", "Die Koordinaten muessen ganzzahlige Werte haben.");
        return false;
    }

}

City* Dialog::getStadt()
{
    return stadt;
}

