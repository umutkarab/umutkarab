#include "map.h"

Map::Map()
{
}

Map::~Map()
{
}

/**
 * @brief Funktion, die eine Stadt hinzufügt
 *
 */

void Map::addCity(City* stadt)
{
    cities.push_back(stadt);
    qDebug() << "Die Stadt " << stadt->getName() << " wurde hinzugefuegt";
}

/**
 * @brief Funktion, die eine Straße hinzufügt
 *
 */

bool Map::addStreet(Street* strasse) // it checks if both cities are present
{
    for(QVector<City*>::iterator it1 = cities.begin(); it1 != cities.end(); it1++)
    {
        if(*it1 == strasse->getStadt1())
        {
            break;
        }
        else
        {
            if (it1 == cities.end()-1)
            {
                qDebug() << "Die Strasse konnte nicht hinzugefuegt werden, da die 'stadt1' der Strasse sich nicht auf der Karte befindet.";
                return false;
            }
            else
            {
                continue;
            }
        }
    }

    for(QVector<City*>::iterator it2 = cities.begin(); it2 != cities.end(); it2++)
    {
        if(*it2 == strasse->getStadt2())
        {
            streets.push_back(strasse);
            qDebug() << "Die Strasse zwischen " << strasse->getStadt1()->getName() << " und " << strasse->getStadt2()->getName() << " wurde hinzugefuegt.";
            return true;
        }
    }
    qDebug() << "Die Strasse konnte nicht hinzugefuegt werden, da die 'stadt2' der Strasse sich nicht auf der Karte befindet.";
    return false;
}

void Map::draw(QGraphicsScene& scene) // draws all cities and streets onto a QGraphicsScene.
{
    for(QVector<City*>::iterator it1 = cities.begin(); it1 != cities.end(); it1++)
    {
        City stadt = *(*it1);
        stadt.draw(scene);
    }
    for(QVector<Street*>::iterator it2 = streets.begin(); it2 != streets.end(); it2++)
    {
        Street strasse = *(*it2);
        strasse.draw(scene);
    }
}

void Map::getCities() // print the names of the cities and streets
{
    for (QVector<City*>::iterator it = cities.begin(); it != cities.end(); it++)
    {
        qDebug() << (*it)->getName();
    }
}
void Map::getStreets()
{
    for (QVector<Street*>::iterator it = streets.begin(); it != streets.end(); it++)
    {
        qDebug() << (*it)->getStadt1()->getName() << (*it)->getStadt2()->getName();
    }
}

void Map::clear()
{
    cities.clear();
    streets.clear();
}

City* Map::findCity(const QString cityName) const // searches for a city in the cities vector by name and returns a pointer to it
{
    for(QVector<City*>::ConstIterator it = cities.begin(); it != cities.end(); it++)
    {
        if ((*it)->getName() == cityName)
        {
            return *it;
        }
    }
    return nullptr;
}

QVector<Street*> Map::getStreetList(const City* city) const // returns a vector of streets that are connected to a specified city.
{
    QVector<Street*> streetsCity;
    for (QVector<Street*>::ConstIterator it = streets.begin(); it != streets.end(); it++)
    {
        City stadt1 = *(*it)->getStadt1();
        City stadt2 = *(*it)->getStadt2();
        if (stadt1 == *city || stadt2 == *city)
        {
            streetsCity.push_back(*it);
        }
    }
    return streetsCity;
}

City* Map::getOppositeCity(const Street* street, const City* city) const
{
    if (street->getStadt1() == city) // checks if the first city (stadt1) of the street is the same as the city passed to the function
    {
        City* stadt = street->getStadt2();
        return stadt;
    }
    else if (street->getStadt2() == city)
    {
        City*stadt= street->getStadt1();
        return stadt;
    }
    else
    {
        return nullptr;
    }
}

double Map::getLength(const Street* street) const //  Pythagorean theorem
{
    double result;
    int distanzX = street->getStadt1()->getX() - street->getStadt2()->getX();
    int distanzY = street->getStadt1()->getY() - street->getStadt2()->getY();
    result = sqrt((((double) distanzX)*((double) distanzX) + ((double) distanzY)*((double) distanzY)));
    return result;
}
