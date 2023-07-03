//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

class Student
{
public:
    Student();
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string address);
    unsigned int getMatNr() const;
    std::string getName() const;
    std::string getGeburtstag() const;
    std::string getAdresse() const;
    void ausgabe(std::ostream& out);
    bool operator == (const Student& student);
    bool operator < (const Student& student);
    bool operator > (const Student& student);

private:
    unsigned int matNr;
    std::string name;
    std::string geburtstag;
    std::string adresse;
};

std::ostream& operator <<(std::ostream& out, Student& student); /// osteream& where the output will go
#endif                                                           /// Student& the object that will be outputted
                                                                 /// this has 2 parameters so its a non-member function, it can be added to public by using "friend"
