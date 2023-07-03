/*
 * Buch.cpp
 *
 *  Created on: 03.07.2023
 *      Author: umutk
 */

#include "Buch.h"

Buch::Buch(std::string initTitel, std::string initAutor) : Medium(initTitel), autor(initAutor){}

///Überladung von ausgabe mit Mediumspezifischen Daten

void Buch::ausgabe(std::ostream& out) const
{
    Medium::ausgabe(out);
    out << "Autor: " << autor << std::endl;
}



