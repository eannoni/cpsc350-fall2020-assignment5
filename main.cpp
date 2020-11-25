#include "BinarySearchTree.h"
#include "Person.h"

#include <iostream>

using namespace std;

int main(int argc, char **argv) {

    BinarySearchTree<Person> *myBST = new BinarySearchTree<Person>();

    Person *myPerson1 = new Person(4, "John Smith", "Sophomore");
    Person* myPerson2 = new Person(5, "Jane Doe", "Junior");
    Person *myPerson3 = new Person(1, "ABC", "Freshman");
    Person *myPerson4 = new Person(6, "DEF", "Senior");
    Person *myPerson5 = new Person(2, "GHI", "Graduate");
    Person *myPerson6 = new Person(3, "JKL", "Prospective");

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
