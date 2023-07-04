#include "street.h"

Street::Street(City* stadt1, City* stadt2):stadt1(stadt1), stadt2(stadt2)
{
}

Street::~Street()
{
}

void Street::draw(QGraphicsScene& scene) // draw a line between cities
{
    int x1 = stadt1->getX();
    int y1 = stadt1->getY();
    int x2 = stadt2->getX();
    int y2 = stadt2->getY();
    scene.addLine(x1, y1, x2, y2);
    qDebug() << "Eine Strasse wurde zwischen " << stadt1->getName() << " und " << stadt2->getName() << " eingezeichnet.";
}

void Street::drawRed(QGraphicsScene& scene) // for dijkstra
{
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::red);
    int x1 = stadt1->getX();
    int y1 = stadt1->getY();
    int x2 = stadt2->getX();
    int y2 = stadt2->getY();
    scene.addLine(x1, y1, x2, y2, pen);
}

City* Street::getStadt1() const
{
    return stadt1;
}

City* Street::getStadt2() const
{
    return stadt2;
}
