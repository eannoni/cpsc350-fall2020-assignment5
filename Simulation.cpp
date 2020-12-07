#include "Simulation.h"

using namespace std;

// default constructor
Simulation::Simulation()
{
    studentBST = new BinarySearchTree<Student>();
    facultyBST = new BinarySearchTree<Faculty>();
    studentBSTImages = new GenStack<BinarySearchTree<Student>>(5);
    facultyBSTImages = new GenStack<BinarySearchTree<Faculty>>(5);
}

// destructor
Simulation::~Simulation()
{
    delete studentBST;
    delete facultyBST;
    delete studentBSTImages;
    delete facultyBSTImages;
}

/* Used by FileManager */

// adds Student from file to the BST
void Simulation::addStudentFromFile(Student* student) {
    studentBST->insertNode(student);
}

// adds Faculty from file to the BST
void Simulation::addFacultyFromFile(Faculty* faculty) {
    facultyBST->insertNode(faculty);
}

// print all students and their information (sorted by ascending id #)
void Simulation::printStudentAscending() {
    cout << "    --- Student List ---" << endl;
    studentBST->printEntireTree();
}

// print all faculty and their information (sorted by ascending id #)
void Simulation::printFacultyAscending() {
    cout << "    --- Faculty List ---" << endl;
    facultyBST->printEntireTree();
}

// find and display student information given a student id
void Simulation::displayStudent() {

    int id = getInputID("Student");
    Student* s = getStudentByID(id);
    cout << *s << endl;
}

// find and display faculty information given a student id
void Simulation::displayFaculty() {

    int id = getInputID("Faculty");
    Faculty* f = getFacultyByID(id);
    cout << *f << endl;
}

// given a student id, print the name and info of their faculty advisor
void Simulation::getStudentAdvisor() {

    int id = getInputID("Student");
    Student* s = getStudentByID(id);
    Faculty* f = getFacultyByID(s->advisor);
    cout << *f << endl;
}

// given a faculty id, print ALL names and info of his/her advisees
void Simulation::getAdvisorStudents() {

    int id = getInputID("Faculty");
    Faculty* f = getFacultyByID(id);
    Student* s;
    for (int i = 0; i < f->advisees->size(); ++i) {
        s = getStudentByID(f->advisees->at(i));
        cout << *s << endl;
    }
}

// add a new student
void Simulation::addStudent() {

    int id = getInputID("Student"); /* TODO: make sure id is unique */

    string name;
    cout << "Enter Student's Name: " << endl;
    cin >> name;
    cin.clear();

    string level;
    cout << "Enter Student's Level: " << endl;
    cin >> level;
    cin.clear();

    string major;
    cout << "Enter Student's Major: " << endl;
    cin >> major;
    cin.clear();

    string gpaStr;
    cout << "Enter Student's GPA: " << endl;
    cin >> gpaStr;
    cin.clear();
    double gpa = stod(gpaStr); /* TODO: add error checking */

    int fID = getInputID("Faculty");
    Faculty* advisor = getFacultyByID(fID);

    while(advisor->advisees->size() > 0) { /* TODO: clean up for better error checking */
        if (facultyBST->searchNode(advisor)) {
            break;
        } else {
            cout << "There is no faculty with this ID number; try again. " << endl;
        }
    }
    Student* newStudent = new Student(id, name, level, major, gpa, fID); /* TODO: add error checking */
    studentBST->insertNode(newStudent);
    //add student to advisor list
    advisor->advisees->push_back(id);

    saveCurrentTrees();
}

// delete a student given the id
void Simulation::deleteStudent() {

    int id = getInputID("Student");
    Student* s = getStudentByID(id);
    int advisor = s->advisor; // save for later
    bool success = studentBST->deleteNode(s);
    if(success) {
        cout << "Student successfully deleted." << endl;
    } else {
        cout << "Student could not be deleted." << endl;
        return;
    }

    // delete student id from any faculty advisees
    Faculty* f = getFacultyByID(advisor);
    for(int i = 0; i < f->advisees->size(); ++i) {
        if(id == f->advisees->at(i)) {
          f->advisees->erase(f->advisees->begin() + i);
            break;
        }
    }

    saveCurrentTrees();
}

// add a new faculty
void Simulation::addFaculty()
{
    int id = getInputID("Faculty"); /* TODO: make sure id is unique */

    string name;
    cout << "Enter Faculty's Name: " << endl;
    cin >> name;
    cin.clear();

    string level;
    cout << "Enter Faculty's Level: " << endl;
    cin >> level;
    cin.clear();

    string department;
    cout << "Enter Faculty's Department: " << endl;
    cin >> department;
    cin.clear();

    Faculty* f = new Faculty(id, name, level, department);
    facultyBST->insertNode(f);

    saveCurrentTrees();
}

// delete a faculty given the id
void Simulation::deleteFaculty()
{
    int id = getInputID("Faculty");
    Faculty* f = getFacultyByID(id);

    if (f->advisees->size() > 0)
    {
      for (int i = 0; i < f->advisees->size(); ++i)
      {
        f->advisees->at(i)->changeStudentAdvisor(); //FIXME
      }
      f->advisees->clear();
    }

    bool success = facultyBST->deleteNode(f);
    if (success)
    {
        cout << "Faculty successfully deleted." << endl;
    }
    else
    {
        cout << "Faculty could not be deleted." << endl;
        return;
    }

    saveCurrentTrees();
}

// change a student's advisor given the student id and the new faculty id
void Simulation::changeStudentAdvisor()
{
    int sID = getInputID("Student");
    Student* s = getStudentByID(sID);

    int fID = getInputID("Faculty");

    if (s->advisor == fID)
    {
      s->advisor = getInputID("Faculty"); //TODO: Make sure thi faculty exists
    }
    saveCurrentTrees();
}

// remove an advisee from a faculty member given the ids
void Simulation::removeAdvisee()
{
  int fID = getInputID("Faculty");
  Faculty* f = getFacultyByID(fID);

  int sID = getInputID("Student");
  Student* s = getStudentByID(sID);

  for (int i = 0; i < f->advisees->size(); ++i)
  {
    if (f->advisees->at(i) == sID)
    {
      f->advisees->erase(f->advisees->begin() + i);
    }
  }
  saveCurrentTrees();
}

// undo previous insertion/removal
void Simulation::rollback()
{
    //rollback
}

// exit simulation
void Simulation::exitSim()
{
  //maybe implement in main by breaking the loop and returning 0?
}

/* Private Functions */

Student* Simulation::getStudentByID(int id) {

    Student* ret;

    Student* temp = new Student(id);

    if (studentBST->searchNode(temp)) {
        ret = studentBST->getNode(temp);
    } else {
        cout << "There is no student with this ID." << endl;
    }
    delete temp;
    return ret;
}

Faculty* Simulation::getFacultyByID(int id) {

    Faculty* ret;

    Faculty* temp = new Faculty(id);

    if (facultyBST->searchNode(temp)) {
        ret = facultyBST->getNode(temp);
    } else {
        cout << "There is no faculty with this ID." << endl;
    }
    delete temp;
    return ret;
}

int Simulation::getInputID(string type) {

    string input;
    int id;
    cout << "Enter " << type << "\'s ID: " << endl;
    cin >> input;
    id = stoi(input); /* TODO: add error checking */

    return id;
}

// saves current tree data into the stacks
void Simulation::saveCurrentTrees()
{

    if(studentBSTImages->isFull()) {
        studentBSTImages->
    }
    studentBSTImages->push(*studentBST);
    facultyBSTImages->push(*facultyBST);
}
