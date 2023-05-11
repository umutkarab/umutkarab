/**
 * Praktikum Informatik 1 MMXXIII
 *
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Reversi
 */

/**
* @mainpage Reversi
*
* Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
*
*/

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "reversiKI.h"


/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    for (int j = 0; j < GROESSE_Y; j++)
        {
            for(int i = 0; i < GROESSE_X; i++)
            {                                                // filled everyfield with 0
                spielfeld[j][i] = 0;
            }
        }
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;           // made the starting position
}



/**
* @brief Ausgabe des Spielfelds auf der Konsole
*
* Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
* Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
*
*  @param spielfeld  Spielfeld, das ausgeben wird
*/
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    std::cout << "   | ";

    //Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i)
        std::cout << ((char) i) << " | " ;                   // Made the ABCDEFGH lines

    std::cout << std::endl;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for(int i = 0; i < GROESSE_X; ++i)
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;           // Made the lines for the squares

        std::cout << " " << j + 1 << " |";          // Made the lines for the squares from left to right
        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
                case 0:
                    std::cout << "   " ;
                    break;
                case 1:
                    std::cout << " X ";
                    break;
                case 2:
                    std::cout << " O ";
                    break;
                default:
                    std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                    std::cout << "Abbruch .... " << std::endl;
                    exit(0);
                    break;
            }
            std::cout << "|";
        };  //for i
        std::cout <<  std::endl;
    }  //for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }

        }
    }

    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
* @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
*
* @param posX Index fuer die Spalte
* @param posY Index fuer die Zeile
* @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
*/
bool aufSpielfeld(const int posX, const int posY)
{
    // Hier erfolgt jetzt Ihre Implementierung ...
	if((posX < GROESSE_X && posY < GROESSE_Y ) && (posX >= 0 && posY >= 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}


/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
                                       //               if aktuellerSpieler == 2 -> gegner = 1

    if (spielfeld[posY][posX] != 0) // ist das Feld leer?
    {
        return false;
    }

    // Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // Hier erfolgt jetzt Ihre Implementierung ...
        	if(spielfeld[posY+j][posX+i] == gegner && aufSpielfeld(posX, posY)) // checks if there is opponent and if we are still in the field
        	{
        		for(int k=2; k < 8; k++)  // K=1 == gegner, so we are starting from k=2 and we are doing loop till 7, because at 8 we are getting out
        		{
        			if(spielfeld[posY + (j*k)][posX + (i*k)] == 0) // if empty leave for-loop
        			{
        				break;
        			}
        			else if(aufSpielfeld(posY+(j*k), posX+(i*k)) == false) // if out of border leave the for loop
					{
        				break;
					}
        			else if(spielfeld[posY+(j*k)][posX+(i*k)] == aktuellerSpieler)
        			{
        				return true;
        			}
        		}
        	}


        }
    }
    return false;
}







/**
 * @brief Funktion, die einen Zug ausfuehrt
 * sehr aehnliche Funktion wie zugGueltig, jedoch darum erweitert,
 * dass die Steine auch jeweils ausgetauscht werden und in alle Richtungen geprueft wird
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler;

    //Alle Richtungen bearbeiten
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // aehnlich wie die Funktion zugGueltig(), aber stellen Sie sicher, das alle gegnerischen Steine in
            // allen Richtungen in Ihre eigenen Steine umgewandelt werden
            //
            // Hier erfolgt jetzt Ihre Implementierung ...
        	if(spielfeld[posY+j][posX+i] == gegner && aufSpielfeld(posX, posY))
        	{
        		for(int k=2; k < 8; k++) // K=1 == gegner, so we are starting from k=2 and we are doing loop till 7, because at 8 we are getting out
        		{
        			if(spielfeld[posY + (j*k)][posX + (i*k)] == 0)  // if empty leave for-loop
        			{
        				break;
        			}
        			else if(aufSpielfeld(posY + (j*k), posX + (i*k)) == false) // if out of border leave for-loop)
        			{
        				break;
        			}
        			else if(spielfeld[posY + (j*k)][posX + (i*k)] == aktuellerSpieler)
        			{
        				while(k > 0) // it means it will get discriment till k=1, and in k=1 we have our oppoent"s stone which we will turn it to our"s
        				{
        					k--;
        					spielfeld[posY+ (j*k)][posX+ (i*k)] = aktuellerSpieler; // umwandeln
        				}
        				break;
        			}
        		}
        	}

      }

    }
    spielfeld[posY][posX] = aktuellerSpieler; // neu stein position
}

/**
 * @brief Funktion, counts the possible moves
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */

int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    // Hier erfolgt jetzt Ihre Implementierung ...
	int moeglicheZuegeZahl = 0;
	for(int posX = 0; posX < GROESSE_X; posX++ )
	{
		for(int posY = 0; posY < GROESSE_Y; posY++)
		{
			if(zugGueltig(spielfeld, aktuellerSpieler, posX, posY) == true)
			{
				moeglicheZuegeZahl++;
			}
		}
	}
    
    return moeglicheZuegeZahl;
}

/**
 * @brief Funktion, die menschliche Züge ermöglicht
 *
 * @param spielfeld Der aktuelle Spieler
 * @param aktuellerSpieler Der aktuelle Spieler
 * @return
 */
bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX;
    int posY;
    std::string symbolSpieler;
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    while (true)
    {
        std::string eingabe;
        std::cout << std::endl << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): " ;
        std::cin >> eingabe;
        posX = (int) eingabe[0] % 32 -1;
        posY = (int) eingabe[1] - 49;

        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            //accept turn;
            break;
        }
        else
        {
            std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
        }
    }

    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf " << (char) (posX + 65) << (posY + 1) << std::endl;

    return true;
}

/**
 * @brief Funktion, die das Spielen des gesamten Spiels ermoeglicht
 *
 * Solange es noch moegliche Zuege gibt, wird das die Schleife durchlaufen
 * Zunaechst wird geschaut, ob es sich um einen mensclichen Spieler oder
 * Computer handelt und der passende Zug wird auchgeführt.
 * Nach dem Zug wird dann das Spielfeld gezeigt und der Spieler gewechselt.
 * Zuletzt wird geschaut, wer ist der Gewinner
 *
 *@param spielerTyp gibt an, ob der Spieler Mensch oder Computer ist
 */
void spielen(const int spielerTyp[2])
{
    int spielfeld[GROESSE_Y][GROESSE_X];

    //Erzeuge Startaufstellung
    initialisiereSpielfeld(spielfeld);

    int aktuellerSpieler = 1;
    int runden = 1;
    zeigeSpielfeld(spielfeld);

    // solange noch Zuege bei einem der beiden Spieler moeglich sind
    //
    // Hier erfolgt jetzt Ihre Implementierung ...
    while(moeglicheZuege(spielfeld, aktuellerSpieler) > 0 || moeglicheZuege(spielfeld, 3 - aktuellerSpieler) > 0)
    {
        bool Zug = false;
        //std::cout << aktuellerSpieler << "\n";
        //std::cout << moeglicheZuege(spielfeld, aktuellerSpieler) << "\n";
        //std::cout << spielerTyp[aktuellerSpieler-1] << "\n";

        if(spielerTyp[aktuellerSpieler-1] == COMPUTER)
        {
        	Zug = computerZug(spielfeld, aktuellerSpieler);
        }
        else
        {                                                                    // else if(spielerTyp[aktuelerspieller] == MENSCH )
        	Zug = menschlicherZug(spielfeld, aktuellerSpieler );
        }

        if(Zug == true)
        {
        	zeigeSpielfeld(spielfeld);
            std::cout << "Runden: " << runden << "\n";
            runden++;
        }

        aktuellerSpieler = 3 - aktuellerSpieler;
    }

    std::cout << "Es gibt keinen moeglichen Zug fuer beide Spieler, Spiel beendet." << std::endl;
    
    switch (gewinner(spielfeld))
    {
        // Hier erfolgt jetzt Ihre Implementierung ...
    case 0:
    	std::cout << "Unentschieden" << "\n";
    	break;
    case 1:
    	std::cout << spielerTyp[0] << "hat gewonnen!" << "\n";
    	break;
    case 2:
    	std::cout << spielerTyp[1] << " hat gewonnen!" << std::endl;
    	break;
    default:
    	std::cout << "Error in gewinner(spielfeld) " << std::endl;
    	break;
    }
}

int main()
{
	if (TEST == 1)
	    {
	        bool gesamtErgebnis = ganzenTestAusfuehren();
	        if (gesamtErgebnis == true)
	        {
	            std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
	        }
	        else
	        {
	            std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
	            exit(1);
	        }
	        std::cout << std::endl << std::endl;
	    }
    
    // Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
    // implementiert haben (waeren sonst doppelt)
    //int spielfeld[GROESSE_Y][GROESSE_X];

    //initialisiereSpielfeld(spielfeld);

    //zeigeSpielfeld(spielfeld);
	// Hier erfolgt jetzt Ihre Implementierung ...
    bool isRunning = true;
    bool isChoosing = true;
    bool isDeciding = true;
    char choose1, choose2, choose3;
    int spielerTyp[2] = {0,0}; // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
    while(isRunning)
    {
    	while(isChoosing)
    	{
    	    std::cout << "Ist Spieler 1 ein Computer ? (j/n)";
    	    std::cin >> choose1;
    	    switch (choose1)
    	    {
    	        case 'j' :
    	        	spielerTyp[0] = COMPUTER;
		        	break;
    	        case 'n' :
    	        	spielerTyp[0] = MENSCH;
    	        	break;
    	        default:
    	        	std::cout << "Wrong Input" << "\n";
    	        	break;
    	    }
    		std::cout << "Ist Spieler 2 ein Computer ? (j/n)";
    		std::cin >> choose2;

    	    switch (choose2)
    	    {
    	        case 'j' :
    	        	spielerTyp[1] = COMPUTER;
    	        	break;
    	        case 'n' :
    	        	spielerTyp[1] = MENSCH;
    	        	break;
    	        default:
    	        	 std::cout << "Wrong Input" << "\n";
    	        	 break;
    	    }
    	    if(spielerTyp[0] != 0 && spielerTyp[1] != 0)
    	    {
       	    	isChoosing = false;
    	    }

    	    spielen(spielerTyp);
    	    while(isDeciding)
    	    {
    	        std::cout << "Neues Spiel? (j/n)";
    	        std::cin >> choose3;
    	        switch (choose3)
    	        {
    	            case 'j' :
                        isChoosing = true;
    	            	isRunning = true;
    	            	isDeciding = false;
    	                break;
    	            case 'n' :
    	            	isRunning = false;
    	            	isDeciding = false;
    	            	break;
    	            default:
    	                std::cout << "Wrong Input" << "\n";
    	                break;
    	        }

    	    }
        }
    }

    
    return 0;
}
