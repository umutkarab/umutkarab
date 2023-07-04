#ifndef CITY_H
#define CITY_H

#include <QString>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QDebug>

class City
{
public:
    City(QString name, int x, int y);

    ~City();

    void draw(QGraphicsScene& scene);

    int getX() const;
    int getY() const;
    QString getName() const;

    bool operator == (const City& stadt) const;

protected:
    QString name;
    int x;
    int y;
};

#endif // CITY_H
