#ifndef STREET_H
#define STREET_H

#include "city.h"
#include <QGraphicsScene>

class Street
{
public:
    Street(City* stadt1, City* stadt2);

    ~Street();

    void draw(QGraphicsScene& scene); // draw a line between cities
    void drawRed(QGraphicsScene& scene); // for dijkstra

    City* getStadt1() const;
    City* getStadt2() const;

private:
    City* stadt1;
    City* stadt2;
};

#endif // STREET_H
