//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{

    int iErste = 0;
    int iZweite = 0;
    
    std::cout << "Geben Sie zwei ganze Zahlen ein" << "\n";
    std::cout << "Erste Zahl: ";
    std::cin >> iErste;
    std::cout << "Zweite Zahl: ";
    std::cin >> iZweite;

    int iSumme = iErste + iZweite;
    int iQuotient = iErste / iZweite;
    std::cout << "Die Summe ist: " << iSumme << "\n";                                           /// 1
    std::cout << "Der Division von erste durch zweite Zahl ist: " << iQuotient << "\n";

    double dSumme = iErste + iZweite;
    double dQuotient = iErste / iZweite;
    std::cout << "Die Summe ist: " << dSumme << "\n";                                           /// 2
    std::cout << "Der Division von erste durch zweite Zahl ist: " << dQuotient << "\n";

    double dErste = (double)iErste;
    double dZweite = (double)iZweite;
    double dSummeCast = dErste + dZweite;
    double dQuotientCast = dErste / dZweite;                                                    /// 3
    std::cout << "Die SummeCast ist: " << dSummeCast << "\n";
    std::cout << "Die QuotientCast ist: " << dQuotientCast << "\n";

    //////////////////////////////////////////////////////////////////////////////
    std::string sVorname;
    std::string sNachname;
    std::cout << "Bitte geben sie ihre Vorname ein: ";
    std::cin >> sVorname;
    std::cout << "Bitte geben sie ihre Nachname ein: ";
    std::cin >> sNachname;                                                                   /// 4

    std::string sVornameName = sVorname + " " + sNachname;
    std::string sNameVorname = sNachname + ", " + sVorname;

    std::cout << sVornameName << "\n";
    std::cout << sNameVorname << "\n";

    //////////////////////////////////////////////////////////////////////////////

	{
		int iFeld[2] = {1, 2};                                                             /// 5a
		std::cout << iFeld[0] << " ";
		std::cout << iFeld[1] << "\n";

		int spielfeld[2][3] = { {1, 2, 3}, {4, 5, 6} };
		std::cout << spielfeld[0][0] << " " << spielfeld[0][1] << " " << spielfeld[0][2] << "\n";          /// 5b
		std::cout << spielfeld[1][0] << " " << spielfeld[1][1] << " " << spielfeld[1][2] << "\n";

		const int iZweite = 1;
		std::cout << "Konstante iZweite im Block ist: " << iZweite << "\n";                                    /// 5c
	}
	    /* std::cout << "Konstante iZweite aus Block ist: " << iZweite */

	//////////////////////////////////////////////////////////////////////////////

	/** A char is actually already a number. It doesn't require any conversion since the ASCII is just a mapping from numbers to character representation.*/
	int iName1 = sVorname[0];
	int iName2 = sVorname[1];
	std::cout << "Anfangsbuchstabe des Vornamens des Benutzers umgewandelt in Zahl mit ASCII-Tabelle ist: " << iName1 << "\n";
	std::cout << "Zweitebuchstabe des Vornamens des Benutzers umgewandelt in Zahl mit ASCII-Tabelle ist: " << iName2 << "\n";   /// 6

	//////////////////////////////////////////////////////////////////////////////

	int Buchstabe1_position = iName1%32;
	int Buchstabe2_position = iName2%32;                                                                  /// 7
	std::cout << "Position der Buchstabe 1 im deutschen Alphabet: " << Buchstabe1_position << "\n";
	std::cout << "Position der Buchstabe 2 im deutschen Alphabet: " << Buchstabe2_position;

	//////////////////////////////////////////////////////////////////////////////

    return 0;
    
}
