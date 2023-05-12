///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>

string verschluesseln(char schluessel[2][26], string wort)
{
	std::string STR1;
	int len = wort.length();
	for(int i = 0; i < len; i++)        // First for loop, starting from index 0 takes every letters of the string
	{
		for(int j = 0; j < 27; j++)     // Second for loop, finds the char ( wort[i] ) in alpabet with j looking from 0 to 26
		{
			if(wort[i] == schluessel[0][j])
			{
				STR1 = STR1 + schluessel[1][j];      // Here we make basically change the char [0][j] > [1][j]
			}
		}
	}

	return STR1;
}

string entschluesseln(char schluessel[2][26], string wort)
{
	std::string STR2;
	int len = wort.length();
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < 27; j++)
		{
			if(wort[i] == schluessel[1][j])
			{
				STR2 = STR2 + schluessel[0][j];
			}
		}
	}

	return STR2;
}

int main()
{
	char buchStabe [2][26] = { {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
			{'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'} };

	std::string wort;
	std::cout << "Wort: ";
	std::cin >> wort;

	int wortlength = wort.length();

	for(int k = 0; k < wortlength; k++)  // so if the word is written in lower case we can convert it to upper
	{
		wort[k] = toupper(wort[k]);
	}


	std::cout << "Das zuverschluesselnende Wort: " << wort << std::endl;
	std::string wort2 = verschluesseln(buchStabe, wort);
	std::cout << "Das verschluesselte Wort ist: " << wort2 << std::endl;

	std::string wort3 = entschluesseln(buchStabe, wort2);
	std::cout << "Das entschluesselte Wort ist: " << wort3 << std::endl;

	return 0;
}
