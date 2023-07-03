//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Student.h"

/**
 * @brief Konstruktor, der einen neuen Studenten mit allen Werten erstellt
 *
 * @param matNr Matrikelnummer
 * @param name Name
 * @param geburtstag Geburtstag
 * @param adresse Adresse
 */
Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse) :
matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{ }

/**
 * @brief Standardkonstruktor, der einen leeren Studenten erstellt
 */
Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{ }

/**
 * @brief Gibt die Matrikelnummer des Studenten zurueck
 *
 * @return Matrikelnummer
 */
unsigned int Student::getMatNr() const
{
    return matNr;
}

/**
 * @brief Gibt den Namen des Studenten zurueck
 *
 * @return Name
 */
std::string Student::getName() const
{
    return name;
}

/**
 * @brief Gibt den Geburtstag des Studenten zurueck
 *
 * @return Geburtstag
 */
std::string Student::getGeburtstag() const
{
    return geburtstag;
}

/**
 * @brief Gibt die Adresse des Studenten zurueck
 *
 * @return Adresse
 */
std::string Student::getAdresse() const
{
    return adresse;
}

/**
 * @brief Gibt alle Daten des Studenten in einer Zeile aus
 */
void Student::ausgabe(std::ostream& out)
{
    /*std::cout << name << ", MatNr. " << matNr << ", geb. am "
              << geburtstag << ", wohnhaft in " << adresse
              << std::endl; */
	out << name << ", MatNr: " << matNr << ", geb. am" << geburtstag << ", wohnhaft in " << adresse << std::endl;
}

bool Student::operator == (const Student& student)
{
	 return this->getMatNr() == student.getMatNr();
}

/** You can also do something like, which is totally unnecessary, the one in the up is better for encapsulation
 *
 * bool Student::operator == (const Student& student)
{
	 if ( matNR == student.matNr)
	 {
	   return true;
	 }
	 else                 This can be also written without return true, false statements cuz its already a bool
	 {
	   return false;
	 }
}
 */


std::ostream& operator << (std::ostream& out, Student& student)
{
	student.ausgabe(out);
	return out;
}

bool Student::operator < (const Student& student)
{
	return this->getMatNr() < student.getMatNr();
}

bool Student::operator > (const Student& student)
{
	return this->getMatNr() > student.getMatNr();
}
