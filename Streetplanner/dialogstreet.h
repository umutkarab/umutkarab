#ifndef DIALOGSTREET_H
#define DIALOGSTREET_H

#include <QDialog>

namespace Ui {
class DialogStreet;
}

class DialogStreet : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStreet(QWidget *parent = nullptr);
    ~DialogStreet();

    void strasseErstellen();
    QString getStrasseStadt1();
    QString getStrasseStadt2();

private:
    Ui::DialogStreet *ui;
    QString strasseStadt1;
    QString strasseStadt2;
};

#endif // DIALOGSTREET_H
