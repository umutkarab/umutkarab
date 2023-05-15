//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
//////////////////////////////////////////////////////////////////////////////

#ifndef LISTE_H_
#define LISTE_H_

#include <iostream>

#include "ListenElement.h"
#include "Student.h"

class Liste
{
private:
    ListenElement* front;                                         // Zeiger auf das erste Listenelement
    ListenElement* back;                                         // Zeiger auf das letzte Listenelement

public:
    Liste();                                                     // Konstruktor mit Zeigerinitialisierung
    void pushBack(Student pData);                                // fügt ein Listenelement am Ende hinzu
    void popFront();                                             // entfernt vorne ein Listenelement
    bool empty();                                                // prüft, ob die Liste leer ist
    Student dataFront();                                         // liest die Daten des ersten Studenten aus
    void ausgabeVorwaerts() const;                               // gibt die Liste von vorne nach hinten aus

    // new added
    void pushFront(Student pData);                               // fügt ein Listenelement am Anfang hinzu
    void ausgabeRueckwaerts() const;                             // gibt die Liste von hinten nach vorne aus
    void loeschen(unsigned int zuloeschendeMatrikelNummer);
};

#endif /*LISTE_H_*/
