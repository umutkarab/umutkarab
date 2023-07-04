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

void City::draw(QGraphicsScene& scene) // // draws a city on a given QGraphicsScene
{
    scene.addRect(x, y, 1, 1);
    QGraphicsTextItem* text = new QGraphicsTextItem; // Then it creates a QGraphicsTextItem
    text->setPos(x, y);                              // sets its position to the city's coordinates
    text->setPlainText(name);                        // and sets its text to the city's name
    scene.addItem(text);                             // added to the scene
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

bool City::operator==(const City& stadt) const // to compare two City objects
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
