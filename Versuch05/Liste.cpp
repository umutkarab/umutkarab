//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);

    if (front == nullptr)            /// Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
    	neuesElement->setPrevious(back); /// added
        back->setNext(neuesElement);
        back = neuesElement;
    }
}

/**
 * @brief Funktion fuegt ein Element vorne ein
 *
 * @param pData
 * @return void
 */
void Liste::pushFront(Student pData) /// added function
{
	ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);
	if(front == nullptr)
	{
		front = neuesElement;
	    back = neuesElement;
	}
	else
	{
		neuesElement->setNext(front);
		front->setPrevious(neuesElement);
		front = neuesElement;
	}
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement* cursor = front; /// front is set to a temporary object that points to the first element of the list

    if (front == back)                                       /// Liste enthält nur ein Listenelement
    {
        delete front;                                        /// Listenelement löschen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        front->setPrevious(nullptr); /// added
        delete cursor;
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}

/**
 * @brief Ausgabe der Liste vom letzten bis zum ersten Element.
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const /// added function
{
	ListenElement* cursor = back;

	while (cursor != nullptr)
	{
		cursor->getData().ausgabe();
		cursor = cursor->getPrevious();
	}
}

/**
 * @brief Die Funktion sucht, ob die zuloeschende MatrikelNummer in der Liste ist und loescht dann den Eintrag dieser Person
 *
 * @param zuloeschendeMatrikelNummer Matrikelnummer des zuloeschenden Studenten
 * @return void
 */
void Liste::loeschen(unsigned int zuloeschendeMatrikelNummer) /// added function
{
	ListenElement* cursor = front;
	bool gefunden = false;

	while(cursor != nullptr)
	{
		if(cursor->getData().getMatNr() == zuloeschendeMatrikelNummer) /// zeile 182
		{
			if(cursor == front)
			{
				std::cout << "gefunden" << std::endl;
		        cursor->getNext()->setPrevious(nullptr);
		        front = cursor->getNext();
		        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
		        cursor->getData().ausgabe();
		        delete cursor; /// means cursor = nullptr
		        gefunden = true;
			}
			else if(cursor == back)
			{
				std::cout << "gefunden" << std::endl;
				cursor->getPrevious()->setNext(nullptr);
				back = cursor->getPrevious();
				std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
				cursor->getData().ausgabe();
				delete cursor;
				gefunden = true;

			}
			else

			{
			std::cout << "gefunden" << std::endl;
		    cursor->getPrevious()->setNext(cursor->getNext());
			cursor->getNext()->setPrevious(cursor->getPrevious());
			std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
			cursor->getData().ausgabe();
			delete cursor;
			gefunden = true;
			}
		}
		else
		{
			cursor = cursor->getNext();
		}
	}
	if(gefunden == false)
		{
			std::cout << "Nicht gefunden!\n\n" << std::endl;
		}
}


