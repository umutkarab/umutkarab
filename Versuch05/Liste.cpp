//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr) // die beiden zeiger "front" und "back" werden auf nullptr initalisert.
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData) // fügt ein Listenelement am Ende hinzu
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr); // added nullptr to make it doppelt verkette Liste
                                  // first nullptr is for ListenElement* pNext, second is for ListenElement* pPrevious
    if (front == nullptr) // if front zeiger shows nullptr, it means its empty     // Liste leer?
    {
        front = neuesElement; // if it is empty, both front and back will become our new element because there is no other element
        back = neuesElement;
    }
    else
    {
    	neuesElement->setPrevious(back); // previous-zeiger of the neuesElement will be replaced with aktuel back element
    	                                 // because now the back element is not at the end so it will be showing the old back element
        back->setNext(neuesElement); // next-zeiger of the back element will become neuesElement
                                     // because the next element now is neuesElement
        back = neuesElement; // at the end our back element will be actually neuesElement because it is at the end
    }
}

/**
 * @brief Funktion fuegt ein Element vorne ein
 *
 * @param pData
 * @return void
 */
void Liste::pushFront(Student pData) // added function
{
	ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr); // added nullptr to make it doppelt verkette Liste
                               // first nullptr is for ListenElement* pNext, second is for ListenElement* pPrevious
	if(front == nullptr) // if front zeiger shows nullptr, it means it is empty
	{
		front = neuesElement; // if it is empty, both front and back will become our new element because there is no other element
	    back = neuesElement;
	}
	else
	{
		neuesElement->setNext(front); // next-zeiger of the neuesEleement will be replaced with aktuel front element
		                              // because now the front element is not the first so it will be showing the old front element
		front->setPrevious(neuesElement); // previous-zeiger of the front element will become neuesElement
		                                  // because the previous element now is neuesEleemnt
		front = neuesElement; // at the end our front element will be actually neuesELement because it is at the front
	}
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement* cursor = front; // front is set to a temporary object that points to the first element of the list

    if (front == back)                                       // Liste enthält nur ein Listenelement
    {
        delete front;                                        // Listenelement löschen
        front = nullptr;           // the front(only element) will be deleted and front and back will be replaced with nullptr
        back = nullptr;
    }
    else
    {
        front = front->getNext();  // front will be aktualisiert with the next element of the list
                                   // it means now the front is actually the second element of the list
        front->setPrevious(nullptr); // new front element"s( 2nd element of the list) previous-zeiger will replaced with nullptr
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

    while (cursor != nullptr)          // getData function will be used for each element, to do that we will give the data of
    {                                  // the current element than cursor will become the next element, and it will continue
    	cursor->getData().ausgabe();   // like that till we reach nullptr
        cursor = cursor->getNext();
    }
}

/**
 * @brief Ausgabe der Liste vom letzten bis zum ersten Element.
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const // added function
{
	ListenElement* cursor = back;

	while (cursor != nullptr)
	{
		cursor->getData().ausgabe();          // same thing with up, but we start from back and always go to previous element
		cursor = cursor->getPrevious();
	}
}

/**
 * @brief Die Funktion sucht, ob die zuloeschende MatrikelNummer in der Liste ist und loescht dann den Eintrag dieser Person
 *
 * @param zuloeschendeMatrikelNummer Matrikelnummer des zuloeschenden Studenten
 * @return void
 */
void Liste::loeschen(unsigned int zuloeschendeMatrikelNummer) // added function
{
	ListenElement* cursor = front; // front will be replaced with a object called cursor
	bool gefunden = false;  // to check if we find it or not, at the beginning it is ofc false

	while(cursor != nullptr) // a while-schleife which will continue till cursor is nullptr
	{
		if(cursor->getData().getMatNr() == zuloeschendeMatrikelNummer)
 // it will continue till the cursor is the matrikelnummer that we are looking for ( check zeile 182 )
		{
			if(cursor == front) // first we will check if the element is at the front
			{
				std::cout << "gefunden" << std::endl;
		        cursor->getNext()->setPrevious(nullptr); // the next element"s previous-zeiger will be set nullptr
		                                                 // because we are going to delete front
		        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
		        cursor->getData().ausgabe();  // we are getting the data of the student that matches with the student
		        delete cursor; // ends the while schleife by making cursor = nullptr
		        gefunden = true;
			}
			else
// basically the same things like up but just this time we also take the previous element"s nextzeiger and set his next-zeiger
// to the next element of the cursor(which we will delete)
// than we make next element"s previous-zeiger, cursor"s previous element
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
