/** @mainpage
 *
 * Praktikum Informatik 1 MMXXIII <BR>
 * Versuch 6: Dynamische Datenstrukturen
 *
 */

#include <vector>
#include <iostream>
#include <string>
#include <fstream>

#include "Student.h"

using namespace std;

int main()
{
    Student student;
    vector <Student> studentenListe;
    vector <Student>::const_iterator it;
    vector <Student>::const_reverse_iterator revIt;

    char abfrage;
    std::cout << "Wollen Sie die Liste selbst fuellen, wenn nicht, können Sie aus einer Datei einlesen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement hinten entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
				  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
                  << "(5): Datenelement loeschen" << std::endl
				  << "(6): Datenelement hinzufuegen" << std::endl
				  << "(7): Datenelement vorne loeschen" << std::endl
				  << "(8): Daten aus einer Datei einlesen" << std::endl
				  << "(9): Daten in einer Datei speichern" << std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            /// Datenelement hinten hinzufuegen
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
                    getline(std::cin, name);

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    Student studentN(matNr, name, geburtstag, adresse);

                    studentenListe.push_back(studentN);
                }
                break;

            /// Datenelement hinten entfernen
            case '2':
                {
                    if(!studentenListe.empty())
                    {
                        studentenListe.pop_back();
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            /// Datenbank vorwaerts ausgeben
            case '3':
                {
                    if(!studentenListe.empty())
                    {
                        std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                        for(it = studentenListe.begin(); it != studentenListe.end(); it++)
                        {
                        	it->ausgabe();
                        }
                     }
                     else
                     {
                    	 std::cout << "Die Liste ist leer!\n\n";
                     }
                 }
                 break;

            ///Datenbank in umgekehrter Reihenfolge ausgeben
            case '4':
                {
            	    if(!studentenListe.empty())
            	    {
            		    std::cout << "Inhalt der Liste in umgekehrter Reihenfolge:" << std::endl;
            		    for(revIt = studentenListe.rbegin(); revIt != studentenListe.rend(); revIt++)
            		    {
            		        revIt->ausgabe();
            		    }
            	     }
            	     else
            	     {
            		     std::cout << "Die Liste ist leer!\n\n";
            	     }
                 }
            	 break;

            ///Datenelement loeschen
            case '5':
                {
                	int eraseNummer = 0;
                	if(!studentenListe.empty())
                	{
                		std::cout << "Geben Sie die nummer, die Sie loeschen moechten:" << std::endl;
                		std::cin >> eraseNummer;
                		eraseNummer = eraseNummer - 1;
                		studentenListe.erase(studentenListe.begin() + eraseNummer);
                	}
                	else
                	{
                		std::cout << "Die Liste ist leer!\n\n";
                	}
                }
                break;

            ///Datenelement hinzufuegen
            case '6':
              {
            	  int insertNummer = 0;
            	  if(!studentenListe.empty())
            	  {
            		  std::cout << "Geben Sie die nummer, vor welches Element Sie neues Element hinzufuegen moechten:" << std::endl;
            		  std::cin >> insertNummer;
            		  std::cin.ignore(10, '\n');
            		  insertNummer = insertNummer - 1;

                      unsigned int matNr = 0;
                      std::string name = "";
                      std::string geburtstag = "";
                      std::string adresse = "";

                      std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
                      getline(std::cin, name);

                      std::cout << "Geburtsdatum: ";
                      getline(std::cin, geburtstag);

                      std::cout << "Adresse: ";
                      getline(std::cin, adresse);

                      std::cout << "Matrikelnummer: ";
                      std::cin >> matNr;
                      std::cin.ignore(10, '\n');

                      Student studentN(matNr, name, geburtstag, adresse);

            		  studentenListe.insert(studentenListe.begin() + insertNummer, studentN);
            	  }
            	  else
            	  {
            		  std::cout << "Die Liste ist Leer!\n\n";
            	  }
              }
              break;

            ///Datenelement vorne loeschen
            case '7':
			  {
            	  if(!studentenListe.empty())
            	  {
            		  studentenListe.erase(studentenListe.begin());
            	  }
            	  else
            	  {
            		  std::cout << "Die Liste ist leer!" << std::endl;
            	  }
			  }
              break;

            ///Daten aus einer Datei einlesen
            case '8':
              {
            	  unsigned int matNr = 0;
                  std::string name = "";
                  std::string Geburtsdatum = "";
                  std::string Adresse = "";
                  std::string dateiName = "";

                  std::cout << "Geben Sie den Namen der Datei ein: ";
                  std::cin >> dateiName;
                  cin.ignore(10, '\n');
                  std::ifstream eingabe(dateiName);
                  eingabe >> matNr;
                  eingabe.ignore(10, '\n');

                  while(eingabe)
                  {
                	  std::getline(eingabe, name);
                	  std::getline(eingabe, Geburtsdatum);
                	  std::getline(eingabe, Adresse);
                	  Student studentN(matNr, name, Geburtsdatum, Adresse);
                	  studentenListe.push_back(studentN);
                	  eingabe >> matNr;
                	  eingabe.ignore(10, '\n');
                  }
              }
              break;

            ///Daten in einer Datei speichern
            case '9':
              {
            	  string dateiName = "";
            	  std::cout << "Geben Sie den Namen ein: ";
            	  std::cin >> dateiName;
            	  cin.ignore(10, '\n');

            	  std::ofstream ausgabe(dateiName);


            	  for(it = studentenListe.begin(); it != studentenListe.end(); it++)
            	  {
            		  ausgabe << it->getMatNr() << std::endl;
            		  ausgabe << it->getName() << std::endl;
            		  ausgabe << it->getGeburtstag() << std::endl;
            		  ausgabe << it->getAdresse() << std::endl << std::endl;
            	  }
            	  ausgabe.close();
              }
              break;

            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;

        }
    }
    while (abfrage != '0');

    return 0;
}
