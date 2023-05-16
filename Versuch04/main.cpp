//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include "math.h"
# define PI 3.141592653589793238462643383279502884197169399375105820974944
#define increment 0.00000001
#define hoeheMensch 1.7000
#define hoehePlattform 555.7
#define radiusErde 6371.0


int main()
{
    Vektor vector1(1, 0, 0);
    Vektor vector2(0, 1, 0);
    Vektor vector3(0, 0, 0);

    std::cout << "Die Komponente von Vector1 sind die Folgende: " << "\n";
    vector1.ausgabe();
    std::cout << "Die Komponente von Vector2 sind die Folgende: " << "\n";
    vector2.ausgabe();

    double laenge = 0;
    laenge = vector1.laenge();
    std::cout << "Die Laenge von Vector 1 ist: " << laenge << "\n";
    laenge = vector2.laenge();
    std::cout << "Die Laenge von Vector 2 ist: " << laenge << "\n" << "\n" ;

    vector3 = vector1.sub(vector2);
    std::cout << "Die Substraktion von Vector1 und Vector2 ist: " << "\n";
    vector3.ausgabe();

    double skalarP = 0;
    skalarP =  vector1.skalarProd(vector2);
    std::cout << "Skalarprodukt Vektor1 und Vektor2: " << skalarP << "\n" << "\n";

    double winkelV = 0;
    winkelV = vector1.winkel(vector2);
    std::cout << "Winkel zwischen Vektor1 und Vektor 2 im Rad: " << winkelV << "\n";
    std::cout << "Winkel zwischen Vektor1 und Vektor 2 im Grad: " << winkelV * (180/PI) << "\n";

    double radiantX = 0;
    double winkelX = 0;
    std::cout << "Um welchen Winkel(Grad) soll Vektor1 gedreht werden?" << "\n";
    std::cin >> winkelX;
    radiantX = winkelX * (180/PI);
    std::cout<< "Vektor1 rotiert um " << winkelX << " Grad:" << "\n";
    vector1.rotiereUmZ(radiantX);
    std::cout<< "Vektor2 rotiert um " << winkelX << " Grad:" << "\n";
    vector2.rotiereUmZ(radiantX);
    vector1.ausgabe();
    vector2.ausgabe();

    double Sichtweite = 0;
    int zaehler = 0;
    Vektor Erde(0, radiusErde, 0);
    Vektor Mensch(0, radiusErde + (hoehePlattform + hoeheMensch)/1000, 0);
    Vektor newSub(0, 0, 0);
    double newSkalar = 0;
    bool Senkrecht = false;

    while (Senkrecht == false)
    {
    	Erde.rotiereUmZ(increment);
    	zaehler++;
    	newSub = Mensch.sub(Erde);
    	newSkalar = Erde.skalarProd(newSub); /// skalarprodukt to check when they are senkrecht
    	if(newSkalar <= 0)             /// it is actually senkrecht when it is 0 but there may be so little mistake, like %0.00001 so we accept negative too
    	{
    		Senkrecht = true;
    		Sichtweite = newSub.laenge(); /// how much we see is, our last newSub value
       	}
    }

        double Grad = Mensch.winkel(Erde) * 180 /PI;
    	std::cout << "Sie koennen " << Sichtweite << std::setprecision(4) << " Km weit sehen." << std::endl;
    	std::cout << "Sie sind " << hoehePlattform + hoeheMensch << " Meter hoch." << std::endl;
    	std::cout << "Der Winkel betraegt " << Grad << std::setprecision(4) << " Grad." << std::endl;
    	std::cout << "Anzahl Schritte: " << zaehler << std::endl;

        return 0;

    }
