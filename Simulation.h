#include "Student.h"
#include "Faculty.h"
#include "BinarySearchTree.h"
#include "GenStack.h"
#include <iostream>

using namespace std;


class Simulation
{
  public:
    Simulation();
    ~Simulation();

    void printStudentAscending();
    void printFacultyAscending();
    void displayStudent(); //display this students info
    void displayFaculty(); //displays this facultys info
    void getAdvisor(); //gets this students advisor
    void getStudents(); //gets this facultys students
    void addStudent();
    void addFaculty();
    void deleteStudent();
    void deleteFaculty();
    void changeStudentAdvisor();
    void removeAdvisee();
    void rollback();
    void exitSim();



    BinarySearchTree<Student> *studentImage;
    BinarySearchTree<Faculty> *facultyImage;
    GenStack<BinarySearchTree<Student>> *studentTreeImages;
    GenStack<BinarySearchTree<Faculty>> *facultyTreeImages;

  private:

    void initializeData(); //if files exist, load, if not, create
};
