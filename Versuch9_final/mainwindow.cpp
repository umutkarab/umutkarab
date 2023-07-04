#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "city.h"
#include "dialogstreet.h"
#include "route.h"
#include "street.h"
#include "dialog.h"
#include "mapio.h"
#include "mapionrw.h"
#include "dijkstra.h"
#include <QDebug>
#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView_teste_was->setScene(&scene);
    this->karteIo = new MapIoNrw();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_test_was_clicked()
{
    QString eingabe;
    QMessageBox msgBox;
    int eingabeConv;
    bool ok;

    eingabe = ui->lineEdit_teste_was->text();
    eingabeConv = eingabe.toInt(&ok);

    qDebug() << "Test";

    if(!ok)
    {
        qDebug() << eingabe;
        msgBox.setText(eingabe);
    }
    else
    {
        eingabeConv = eingabeConv + 4;
        qDebug() << eingabeConv;
        eingabe = QVariant(eingabeConv).toString();
        msgBox.setText(eingabe);
    }
    msgBox.exec();
    int x = rand() % 500;
    int y = rand() % 500;
    int w = rand() % 500;
    int h = rand() % 500;
    scene.addRect(x, y, w, h, QPen(Qt::red));
}


void MainWindow::on_actionExit_triggered() // Closes the application
{
    close();
}


void MainWindow::on_actionClear_Scene_triggered() // Clears the map and the scene.
{
    karte.clear();
    scene.clear();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.about(this, "About", "Dieses GUI hat ein EIngabefeld, wenn Sie eine Zahl eingeben wird diese um 4 erhoet und asugegeben. \n"
                                "Ansonsten wird einfach nur Ihre Eingabe ausgegeben. Bei jeder Eingabe wird außerdem ein zufaelliges Rechteck eingezeichnet \n"
                                "Mit 'Alt + S' koennen Sie das Fenster in dem die Vierecke ausgegeben werden clearen. \n"
                                "Mit 'Alt + E koenne Sie das GUI schließen.");
}


void MainWindow::on_pushButton_draw_city_clicked() // Adds two new cities ("Aachen" and "Hamburg") to the scene.
{
    City* stadt = new City("Aachen", 0, 0);
    stadt->draw(scene);
    stadt = new City("Hamburg", 100, -150);
    stadt->draw(scene);
}


void MainWindow::on_pushButton_draw_map_clicked() // creates four cities and six streets connecting them, and adds them to the map and draws it on the scene
{
    karte.clear();
    City* aachen = new City("Aachen", 0, 0);
    City* hamburg = new City("Hamburg", 100, -150);
    City* berlin = new City("Berlin", 190, -50);
    City* muenchen = new City("Muenchen", 120, 180);
    Street* nordSued = new Street(hamburg, muenchen);
    Street* westOst = new Street(aachen, berlin);
    Street* nordOst = new Street(hamburg, berlin);
    Street* westSued = new Street(aachen, muenchen);
    Street* westNord = new Street(aachen, hamburg);
    Street* ostSued = new Street(berlin, muenchen);

    karte.addCity(aachen);
    karte.addCity(hamburg);
    karte.addCity(berlin);
    karte.addCity(muenchen);
    karte.addStreet(nordSued);
    karte.addStreet(westOst);
    karte.addStreet(nordOst);
    karte.addStreet(westSued);
    karte.addStreet(westNord);
    karte.addStreet(ostSued);
    karte.draw(scene);
}


void MainWindow::on_pushButton_test_street_clicked() // Creates a street between two cities and draws it
{
    City* Aachen = new City("Aachen", 0, 0);
    City* Hamburg = new City("Hamburg", 100, -150);
    Street* strasse = new Street(Aachen, Hamburg);
    strasse->draw(scene);
}


void MainWindow::on_checkBox_hide_tests_clicked() // Hides or shows certain UI elements
{
    if(ui->checkBox_hide_tests->isChecked())
    {
        ui->pushButton_test_was->hide();
        ui->pushButton_test_street->hide();
        ui->pushButton_draw_city->hide();
        ui->pushButton_draw_map->hide();
        ui->pushButton_test_abstract_map->hide();
        ui->pushButton_test_dijkstra->hide();
        ui->lineEdit_teste_was->hide();
        ui->label_eingabe->hide();
    }
    else
    {
        ui->pushButton_test_was->show();
        ui->pushButton_test_street->show();
        ui->pushButton_draw_city->show();
        ui->pushButton_draw_map->show();
        ui->pushButton_test_abstract_map->show();
        ui->pushButton_test_dijkstra->show();
        ui->lineEdit_teste_was->show();
        ui->label_eingabe->show();
    }
}


void MainWindow::on_pushButton_stadt_hinzufuegen_clicked() // Opens a dialog to allow the user to add a city to the map, and draws the map on the scene.
{
    bool korrekteEingabe = false;
    do
    {
        Dialog d;
        bool eingegeben = d.exec();
        if (eingegeben)
        {
            if (d.stadtErstellen())
            {
                City* stadt = d.getStadt();
                karte.addCity(stadt);
                karte.draw(scene);
                korrekteEingabe = true;
            }
        }
        else
        {
            korrekteEingabe = true;
        }
    }while(!korrekteEingabe);
}


void MainWindow::on_pushButton_fill_map_clicked() // Fills the map using the MapIo object, and draws the map on the scene.
{
    karteIo->fillMap(karte);
    karte.draw(scene);
}

void MainWindow::on_pushButton_test_abstract_map_clicked() // Conducts a series of tests on a test map and shows the results in a message box.
{
    bool test = true;
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            test = false;
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            test = false;
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
        {
            test = false;
            qDebug() << "-Error: City a could not be found.";
        }

        city = testMap.findCity("b");
        if (city != b)
        {
            test = false;
            qDebug() << "-Error: City b could not be found.";
        }

        city = testMap.findCity("c");
        if (city != nullptr)
        {
            test = false;
            qDebug() << "-Error: If city could not be found 0 should be returned.";
        }
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
        {
            test = false;
            qDebug() << "-Error: Opposite city should be b.";
        }

        city = testMap.getOppositeCity(s, c);
        if (city != nullptr)
        {
            test = false;
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
        }
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
        {
            test = false;
            qDebug() << "-Error: Street Length is not equal to the expected.";
        }

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1)
        {
            test = false;
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s)
        {
            test = false;
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
        {
            test = false;
            qDebug() << "-Error: Two streets should be found for city b.";
        }
    }

    qDebug() << "MapTest: End Test of the Map.";
    if (test)
    {
        QMessageBox::information(0, "Map Test", "Sucess");
    }
    else
    {
        QMessageBox::critical(0, "Map Test", "Error");
    }
}


void MainWindow::on_pushButton_test_dijkstra_clicked()
{
    QVector<Street*> strecke = Dijkstra::search(karte, "Düsseldorf", "Aachen");
    if (strecke.size() != 0)
    {
        qDebug() << "Die kuerzeste Strecke enthaelt die Straße(n):";
        for (QVector<Street*>::Iterator it = strecke.begin(); it != strecke.end(); it++)
        {
            qDebug() << "Von" << (*it)->getStadt1()->getName() << "nach" << (*it)->getStadt2()->getName();
            (*it)->drawRed(scene);
        }
    }
    else
    {
        qDebug() << "Zwischen den Staedten gibt es keine Verbindung.";
    }
}


void MainWindow::on_pushButton_search_route_clicked()
{
    Route r;
    bool eingegeben = r.exec();
    if (eingegeben)
    {
        r.setStart();
        r.setZiel();
        QVector<Street*> strecke = Dijkstra::search(karte, r.getStart(), r.getZiel());
            if (strecke.size() != 0)
        {
            qDebug() << "Die kuerzeste Strecke enthaelt die Straße(n):";
                for (QVector<Street*>::Iterator it = strecke.begin(); it != strecke.end(); it++)
            {
                qDebug() << "Von" << (*it)->getStadt1()->getName() << "nach" << (*it)->getStadt2()->getName();
                (*it)->drawRed(scene);
            }
        }
        else
        {
            QMessageBox::critical(0, "Error", "Städte/Verbindung nicht gefunden");
        }
    }
}


void MainWindow::on_pushButton_add_street_clicked() // Opens a dialog to allow the user to add a street to the map, and if successful, draws it on the scene.
{
    DialogStreet dstreet;
    bool eingegeben = dstreet.exec();
    if (eingegeben)
    {
        dstreet.strasseErstellen();
        qDebug () << dstreet.getStrasseStadt1() << dstreet.getStrasseStadt2();
        QString strasseStadt1 = dstreet.getStrasseStadt1();
        QString strasseStadt2 = dstreet.getStrasseStadt2();
        City* stadt1 = karte.findCity(strasseStadt1);
        City* stadt2 = karte.findCity(strasseStadt2);

        if(stadt1 != nullptr && stadt2 != nullptr)
        {
            Street* strasse = new Street(stadt1, stadt2);
            strasse->draw(scene);
            karte.addStreet(strasse);
        }
        else
        {
            QMessageBox::critical(0, "Error", "Mindestens eine der beiden Städte wurde nicht gefunden");
        }
    }
}

