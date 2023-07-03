/*
 * DVD.h
 *
 *  Created on: 03.07.2023
 *      Author: umutk
 */

#ifndef DVD_H_
#define DVD_H_

#include "Medium.h"

class DVD : public Medium
{
public:
    DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);
    virtual void ausgabe(std::ostream& out) const;
    bool ausleihen(Person person, Datum ausleihdatum);
private:
    int alter;
    std::string genre;
};




#endif /* DVD_H_ */
