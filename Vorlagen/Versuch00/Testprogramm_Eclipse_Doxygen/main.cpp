/// @file main.cpp
/// @mainpage
/// Praktikum Informatik 1 SS2023\n
/// Testprogramm_Eclipse_Doxygen\n
/// Versuch00: Vorbereitung auf das Praktikum
//
// Datei: main.cpp
// Inhalt: Hauptprogramm
//

#include <iostream>
#include "Complex.h"


/** 
 *  @brief Hier ist die main-Funktion
 *
 *  Zwei komplexe Zahlen werden addiert.
 *  Das Ergebnis wird in der dritten
 *  komplexen Zahl speichert bzw. ausgegeben.
 */
int main()
{
    //Erstelle zwei komplexe Zahlen ueber Konstruktor 2
    Complex c1(2.0, 4.0);
    Complex c2(6.0, 8.0);

    //Erstelle dritte komplexe Zahl ueber Konstruktor 1
    Complex c3;

    //Addition zwei komplexer Zahlen
    c3=c1+c2;

    //dritte komplexe Zahl ausgeben.
    std::cout << "Addition zweier komplexer Zahlen:" << std::endl;
    std::cout << "c3 = " << c3 << std::endl;

    return 0;
}
