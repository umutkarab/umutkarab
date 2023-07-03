/*
 * DVD.cpp
 *
 *  Created on: 03.07.2023
 *      Author: umutk
 */

#include "DVD.h"

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre) : Medium(initTitel), alter(initAltersfreigabe), genre(initGenre){}

//Überladung von ausgabe mit Mediumspezifischen Daten
void DVD::ausgabe(std::ostream& out) const
{
    this->Medium::ausgabe(std::cout);
    std::cout << "FSK: " << alter << std::endl;
    std::cout << "Genre: " << genre << std::endl;
}

//Überladung von ausleihen mit Beschränkungen
bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
    if(ausleihdatum-person.getGeburtsdatum()<=alter*12)
    {
        std::cout << "Altersbeschraenkung nicht erfuellt" << std::endl;
        return false;
    }
    else
    {
        return(this->Medium::ausleihen(person, ausleihdatum));
    }
}


