#include "BinarySearchTree.h"
#include "Student.h"
#include "Faculty.h"

#include <iostream>

using namespace std;

int main(int argc, char **argv) {

    BinarySearchTree<Person> *myBST = new BinarySearchTree<Person>();

    vector<int>* adviseeList = new vector<int>();
    adviseeList->push_back(5);
    adviseeList->push_back(1);
    adviseeList->push_back(9);

    Student *myPerson1 = new Student(4, "John Smith", "Sophomore", "Computer Science", 4.0, 23);
    Faculty* myPerson2 = new Faculty(5, "Jane Doe", "Professor", "Engineering", adviseeList);
    Person *myPerson3 = new Person(1, "ABC", "Freshman");
    Person *myPerson4 = new Person(6, "DEF", "Senior");
    Person *myPerson5 = new Person(2, "GHI", "Graduate");
    Faculty *myPerson6 = new Faculty(*myPerson2);

    myBST->insertNode(myPerson1);
    myBST->insertNode(myPerson2);
    myBST->insertNode(myPerson3);

    myBST->printEntireTree();
    cout << "size: " << myBST->getSize() << endl;
    cout << "max: " << *myBST->getMax() << endl;
    cout << "min: " << *myBST->getMin() << endl;

    myBST->insertNode(myPerson4);
    myBST->insertNode(myPerson5);
    myBST->insertNode(myPerson6);

    myBST->printEntireTree();
    cout << "size: " << myBST->getSize() << endl;
    cout << "max: " << *myBST->getMax() << endl;
    cout << "min: " << *myBST->getMin() << endl;

    delete myBST;

    return 0;
}
