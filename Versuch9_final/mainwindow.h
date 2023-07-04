#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "map.h"
#include "mapio.h"

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
    void on_pushButton_test_was_clicked();

    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_pushButton_draw_city_clicked();

    void on_pushButton_draw_map_clicked();

    void on_pushButton_test_street_clicked();

    void on_checkBox_hide_tests_clicked();

    void on_pushButton_stadt_hinzufuegen_clicked();

    void on_pushButton_fill_map_clicked();

    void on_pushButton_test_abstract_map_clicked();

    void on_pushButton_test_dijkstra_clicked();

    void on_pushButton_search_route_clicked();

    void on_pushButton_add_street_clicked();


private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    Map karte;
    MapIo* karteIo;

};
#endif // MAINWINDOW_H
