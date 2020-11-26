// Student header file

#ifndef STUDENT
#define STUDENT

#include "Person.h"

class Student : public Person {
    public:
        Student(); // default constructor
        Student(int id, string name, string level, string major, double gpa, int advisor); // overloaded constructor
        Student(const Student& other); // copy constructor
        ~Student(); // destructor

        string toString() const override;

        string major;
        double gpa;
        int advisor;
};

#endif
