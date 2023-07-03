/*
 * Magazin.cpp
 *
 *  Created on: 03.07.2023
 *      Author: umutk
 */

#include "Magazin.h"

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte) : Medium(initTitel), datum(initDatumAusgabe), sparte(initSparte){}

//Überladung von ausgabe mit Mediumspezifischen Daten
void Magazin::ausgabe(std::ostream& out) const
{
    this->Medium::ausgabe(out);
    out << "Ausgabe: ";
    datum.ausgabe(out);
    out << "\nSparte: " << sparte << std::endl;
}

//Überladung von ausleihen mit Beschränkungen
bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{
    if(ausleihdatum-datum==0)
    {
        std::cout << "Neuste Ausgaben duerfen nicht verliehen werden :(" << std::endl;
        return false;
    }
    else
    {
        return(this->Medium::ausleihen(person, ausleihdatum)); /// dont need to write return true, its already in medium::ausleihen function
    }
}

