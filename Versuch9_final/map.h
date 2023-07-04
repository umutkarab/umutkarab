#ifndef MAP_H
#define MAP_H

#include "abstractmap.h"
#include "city.h"
#include "street.h"
#include <vector>

class Map : public AbstractMap
{
public:
    Map();

    ~Map();

    void addCity(City* stadt);
    bool addStreet(Street* strasse);

    void draw(QGraphicsScene& scene);// to draw the cities and streets
    void clear();

    void getCities(); // to print the names of the cities and streets in the map
    void getStreets();

    City* findCity(const QString cityName) const;
    QVector<Street*> getStreetList(const City* city) const; // return a list of streets for a specified city.
    City* getOppositeCity(const Street* street, const City* city) const; // to find the city at the other end of a street from a specified city.
    double getLength(const Street* street) const; //  calculates and returns the distance of a street.

private:
    QVector<City*> cities;
    QVector<Street*> streets;
};

#endif // MAP_H
