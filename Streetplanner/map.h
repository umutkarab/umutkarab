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

    void draw(QGraphicsScene& scene);
    void clear();

    void getCities();
    void getStreets();

    City* findCity(const QString cityName) const;
    QVector<Street*> getStreetList(const City* city) const;
    City* getOppositeCity(const Street* street, const City* city) const;
    double getLength(const Street* street) const;

private:
    QVector<City*> cities;
    QVector<Street*> streets;
};

#endif // MAP_H
