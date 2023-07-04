#include "city.h"

City::City(QString name, int x, int y):name(name), x(x), y(y)
{
}

City::~City()
{
}

/**
 * @brief Funktion, die eine Stadt zeichnet
 *
 * Diese Funktion erstellt, indem sie einen Punkt an einer bestimmten Stelle zeichnet
 * und mit einem Stadtnamen darunter versieht, eine Stadt
 *
 */

void City::draw(QGraphicsScene& scene)
{
    scene.addRect(x, y, 1, 1);
    QGraphicsTextItem* text = new QGraphicsTextItem;
    text->setPos(x, y);
    text->setPlainText(name);
    scene.addItem(text);
    qDebug() << "Die Stadt" << name << "wurde an den Koordinaten" << x << ", " << y << " eingezeichnet.";
}

int City::getX() const
{
    return x;
}

int City::getY() const
{
    return y;
}

QString City::getName() const
{
    return name;
}

bool City::operator==(const City& stadt) const
{
    if(this->name == stadt.name && this->x == stadt.getX() && this->y == stadt.getY())
    {
        return true;
    }
    else
    {
        return false;
    }
}
