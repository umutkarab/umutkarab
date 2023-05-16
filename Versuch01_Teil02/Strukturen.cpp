/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
	//////////////////////////////////////////////////////////////////////////////

	struct Person
	{
		std::string sNachname;
		std::string sVorname;
		int iGeburtsjahr;
		int iAlter;
	};

	Person nBenutzer;
	std::cout << "Vorname: ";
	std::cin >> nBenutzer.sVorname;

	std::cout << "Nachname: ";
	std::cin >> nBenutzer.sNachname;

	std::cout << "Geburtsjahr: ";
	std::cin >> nBenutzer.iGeburtsjahr;

	std::cout << "Alter: ";
	std::cin >> nBenutzer.iAlter;

	std::cout << "Name des Benutzers ist " << nBenutzer.sVorname + " " + nBenutzer.sNachname << "." << " Er/Sie war im " << nBenutzer.iGeburtsjahr << " geboren. " << "Er/Sie ist "
			  << nBenutzer.iAlter << " Jahre alt." << "\n" ;

	//////////////////////////////////////////////////////////////////////////////

	Person nKopieEinzeln;
	nKopieEinzeln.sVorname = nBenutzer.sVorname;
	nKopieEinzeln.sNachname = nBenutzer.sNachname;
	nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
	nKopieEinzeln.iAlter = nBenutzer.iAlter;

	Person nKopieGesamt;
	nKopieGesamt = nBenutzer;

	std::cout << "Name des nKopieEinzelns ist " << nKopieEinzeln.sVorname + " " + nKopieEinzeln.sNachname << "." << " Er/Sie war im " << nKopieEinzeln.iGeburtsjahr << " geboren. " << "Er/Sie ist "
				  << nKopieEinzeln.iAlter << " Jahre alt." << "\n" ;

	std::cout << "Name des nKopieGesamts ist " << nKopieGesamt.sVorname + " " + nKopieGesamt.sNachname << "." << " Er/Sie war im " << nKopieGesamt.iGeburtsjahr << " geboren. " << "Er/Sie ist "
					  << nKopieGesamt.iAlter << " Jahre alt." << "\n" ;


    return 0;
    
}
