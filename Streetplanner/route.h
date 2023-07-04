#ifndef ROUTE_H
#define ROUTE_H

#include <QDialog>

namespace Ui {
class Route;
}

class Route : public QDialog
{
    Q_OBJECT

public:
    explicit Route(QWidget *parent = nullptr);
    ~Route();

    QString getStart();
    QString getZiel();

    void setStart();
    void setZiel();

private:
    Ui::Route *ui;
    QString start;
    QString ziel;
};

#endif // ROUTE_H
