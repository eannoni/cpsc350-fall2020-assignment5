#include "BinarySearchTree.h"

#include <iostream>

using namespace std;

int main(int argc, char **argv) {

    BinarySearchTree<int> *myBST = new BinarySearchTree<int>();

    myBST->insertNode(myInt1);
    myBST->insertNode(myInt2);
    myBST->insertNode(myInt3);

    myBST->printEntireTree();
    cout << "size: " << myBST->getSize() << endl;
    cout << "max: " << myBST->getMax() << endl;
    cout << "min: " << myBST->getMin() << endl;

    myBST->insertNode(myInt4);
    myBST->insertNode(myInt5);
    myBST->insertNode(myInt6);

    myBST->printEntireTree();
    cout << "size: " << myBST->getSize() << endl;
    cout << "max: " << myBST->getMax() << endl;
    cout << "min: " << myBST->getMin() << endl;



    delete myBST;

    return 0;
}
