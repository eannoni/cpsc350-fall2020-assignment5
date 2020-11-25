// Person base class implementation

#include "Person.h"

Person::Person() {
    id = -1;
    name = "no name";
    level = "no level";
}

Person::Person(int id, string name, string level) {
    this->id = id;
    this->name = name;
    this->level = level;
}

Person::~Person() {}

bool Person::operator==(const Person& other) const {
    return (this->id == other.id);
}

bool Person::operator!=(const Person& other) const {
    return (this->id != other.id);
}

bool Person::operator>(const Person& other) const {
    return (this->id > other.id);
}

bool Person::operator<(const Person& other) const {
    return (this->id < other.id);
}

ostream& operator<<(ostream& os, const Person& other) {
    os << "Person: " << other.name << ", " << other.id << ", " << other.level;
    return os;
}
