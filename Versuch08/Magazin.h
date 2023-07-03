/*
 * Magazin.h
 *
 *  Created on: 03.07.2023
 *      Author: umutk
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Medium.h"
#include "Datum.h"

class Magazin : public Medium
{
public:
    Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);
    virtual void ausgabe(std::ostream& out) const;                                      /// Sparte means category!
    bool ausleihen(Person person, Datum ausleihdatum);
private:
    Datum datum;
    std::string sparte;
};




#endif /* MAGAZIN_H_ */
