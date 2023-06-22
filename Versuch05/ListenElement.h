//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
//////////////////////////////////////////////////////////////////////////////

#ifndef _LISTENELEMENT_H_
#define _LISTENELEMENT_H_

#include "Student.h"

class ListenElement
{
private:
    Student data;
    ListenElement* next;
    ListenElement* previous; /// added

public:
    ListenElement(Student pData, ListenElement* pNext, ListenElement* pPrevious); /// added ListenElement* pPrevious

    void setData(Student pData);
    void setNext(ListenElement* pNext);
    void setPrevious(ListenElement* pPrevious); /// added

    Student getData() const;
    ListenElement* getNext() const;
    ListenElement* getPrevious() const;  /// added
};

#endif
