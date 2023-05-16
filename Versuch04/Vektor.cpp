//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

/**
 * @brief Function calculating the length of a vector
 * @return length of the vector
 */
double Vektor::laenge() const
{
	double laengeVektor = 0;
	laengeVektor = sqrt(x*x + y*y + z*z);
	return laengeVektor;
}

/**
 * @brief Function subracting one vector from another
 * Initialisiert resultierenden Vektor, wobei "this" die Koordinaten des Minuends referenziert.
 * Von diesem werden dann die Koordinaten des Subtrahenden abgezogen.
 * @param Vektor ist der resultierende Vektor
 * @param input dieser Vektor wird vom anderem abgezogen
 * @return Subtraction
 */
Vektor Vektor::sub(const Vektor& input) const
{
	double newX, newY, newZ = 0;

	newX = this->x - input.x;
	newY = this->y - input.y;
	newZ = this->z - input.z;
	return Vektor(newX, newY, newZ);
}

/**
 * @brief Function calculating the scalarproduct of two vectors
 * Diese Funtktionen multipliziert erst die einzelnen Koordinaten miteinander
 * und addiert diese Werte dann
 * @return Skalarprodukt
 */
double Vektor::skalarProd(const Vektor& input) const  /// skalarprodukt = Mit dem Skalarprodukt kannst du zwei Vektoren miteinander multiplizieren, die gleich gross sind.
{
	double skalarP = 0;
	skalarP = this->x * input.x + this->y * input.y + this->z * input.z;
	return skalarP;
}

/**
 * @brief Function calculating the angle between two vectors
 * berechnet das Skalarprodukt der beiden Vektoren mit bekannter Formel
 * @return Angle
 */
double Vektor::winkel(const Vektor& input) const
{
	double vektorP, laengeV1, laengeV2 , div, winkelV = 0;
    vektorP = this->skalarProd(input); ///vektorP = this->x * input.x + this->y * input.y + this->z * input.z;
    laengeV1 = this->laenge(); ///laengeV1 = sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    laengeV2 = input.laenge(); ///laengeV2 = sqrt(input.x * input.x + input.y * input.y + input.z * input.z);
    div = vektorP / (laengeV1 * laengeV2);
    winkelV = acos(div); /// arcccos returns the inverse cosine of a number (argument) in radians.
    return winkelV;
}

/**
 * @brief Function that rotates a vector around the z-axis
 * ersetzt die alten Koordinaten durch neue entsprechend der gegebenen Formel zur rotierung um die z-Achse
 * @param rad winkel, um den der Vektor rotiert werden soll.
 */
void Vektor::rotiereUmZ(double rad)
{
	double preX, preY = 0;
	preX = this->x;
	preY = this->y;
	this->x = cos(rad) * preX - sin(rad) * preY;      ///  ( cos(a) - sin(a) ) == x
	this->y = sin(rad) * preX + cos(rad) * preY;      ///  ( sin(a)   cos(a) ) == y
}

