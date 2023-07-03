/*
 * Buch.h
 *
 *  Created on: 03.07.2023
 *      Author: umutk
 */

#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h"

class Buch : public Medium
{
public:
    Buch(std::string initTitel, std::string initAutor);
    virtual void ausgabe(std::ostream& out) const;
private:
    std::string autor;

};


#endif /* BUCH_H_ */
