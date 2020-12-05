// Faculty header file

#ifndef FACULTY
#define FACULTY

#include "Person.h"
#include <vector>

class Faculty : public Person {
    public:
        Faculty(); // default constructor
        Faculty(int id, string name, string level, string department, vector<int>* advisees); // overloaded constructor
        Faculty(const Faculty& other); // copy constructor
        virtual ~Faculty(); // destructor

        string toString() const override;

        string department;
        vector<int>* advisees;
};

#endif
