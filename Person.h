// Person base class header
#ifndef PERSON
#define PERSON

#include <iostream>

using namespace std;

class Person {

    public:
        Person(); // constructor
        Person(int id, string name, string level); // overloaded constructor
        ~Person(); // destructor

        // overloaded operators
        bool operator==(const Person& other) const;
        bool operator!=(const Person& other) const;
        bool operator>(const Person& other) const;
        bool operator<(const Person& other) const;
        friend ostream& operator<<(ostream& os, const Person& other);

        int id;
        string name;
        string level;
};

#endif
