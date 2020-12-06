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
Simulation::~Simulation();
{
    delete studentBST;
    delete facultyBST;
    delete studentBSTImages;
    delete facultyBSTImages;
}

/* Used by FileManager */

// adds Student from file to the BST
void Simulation::addStudent(Student* student) {
    studentBST->insertNode(student);
}

// adds Faculty from file to the BST
void Simulation::addFaculty(Faculty* faculty) {
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


    while(true) { /* TODO: clean up for better error checking */
        string studentAdvisor;
        cout << "Enter Student's Advisor ID: " << endl;
        cin >> studentAdvisor;
        cin.clear();
        int advisor = stoi(studentAdvisor); /* TODO: add error checking */

        if (facultyBST->searchNode(advisor)) {
            break;
        } else {
            cout << "There is no faculty with this ID number; try again. " << endl;
        }
    }
    Student* newStudent = new Student(id, name, level, major, gpa, advisor); /* TODO: add error checking */
    studentBST->insertNode(newStudent);
    //add student to advisor list
    Faculty* f = getFacultyByID(advisor);
    f->advisees->push_back(id);

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
            f->advisees->erase(i);
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
    string facToDelete;
    string facToTransfer;
    int advisees;

    cout << "Enter Faculty ID to be deleted: " << endl;
    cin >> facToDelete;
    cout << "Enter Faculty ID to transfer advisees to: " << endl;
    cin >> facToTransfer;

    Faculty currFaculty(stoi(facToDelete));
    Faculty transferFaculty(stoi(facToTransfer));

    /*if (facultyBST->searchNode(transferFaculty) && facultyBST->searchNode(facToDelete))
    {
    GenList<int> *rem = facultyBST->find(currFaculty).advisees;
    while (rem->getSize() != 0)
    {
      int oldID = rem->removeFront();
      Student facultyStudent = Student(oldID);
      studentBST->find(facultyStudent).setAdvisor(stoi(facToTransfer));
      facultyBST->find(transferFaculty).advisees->insertFront(oldID);
    }
    facultyBST->recDelete(currFaculty);
    studentBSTImages->push(*studentBST);
    facultyBSTImages->push(*facultyBST);
    }
    else
    {
    cout << "There is no faculty with this ID number. " << endl;
    } */
}

// change a student's advisor given the student id and the new faculty id
void Simulation::changeStudentAdvisor()
{
    string studentID;
    string newAdvisorID;
    cout << "Enter Student ID:" << endl;
    cin >> studentID;
    cout << "Enter Advisor ID: " << endl;
    cin >> newAdvisorID;

    Student currStudent(stoi(studentID));
    Faculty newAdvisor(stoi(newAdvisorID));
    /*
    if (studentBST->searchNode(currStudent) && facultyBST->searchNode(newAdvisor))
    {
    	studentBST->find(currStudent).setAdvisor(stoi(newAdvisorID)); // finds the student and gives them a new advisor
    	facultyBST->find(newAdvisor).addAdvisor(stoi(studentID)); // vice versa
    	facultyBST->find(studentBST->find(currStudent).newAdvisorID).deleteAdvisor(stoi(studentID)); // deletes this student from its former advisor's list
    	studentBSTImages->push(*studentBST);
    	facultyBSTImages->push(*facultyBST);
    }
    else
    	cout << "There is no faculty with this ID number. " << endl; */
}

// remove an advisee from a faculty member given the ids
void Simulation::removeAdvisee()
{
    string advisorID;
    cout << "Enter Advisor ID: " << endl;
    cin >> advisorID;
    string studentID;
    cout << "Enter Student ID: " << endl;
    cin >> studentID;

    Student studentToDelete(stoi(studentID));
    Faculty currFaculty(stoi(advisorID));

    if (studentBST->searchNode(studentToDelete) && facultyBST->searchNode(currFaculty))
    {
    //studentBST->find(studentToDelete).setAdvisor(0);
    //facultyBST->find(studentBST->find(studentToDelete).advisorID).deleteFaculty(stoi(studentID));
    studentBSTImages->push(*studentBST);
    facultyBSTImages->push(*facultyBST);
    }
    else
    {
    cout << "There is no student with that ID number. " << endl;
    }
}

// undo previous insertion/removal
void Simulation::rollback()
{
    //rollback
}

// exit simulation
void Simulation::exitSim()
{

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
void Simulation::saveCurrentTrees() {

    if(studentBSTImages->isFull()) {
        studentBSTImages->
    }
    studentBSTImages->push(*studentBST);
    facultyBSTImages->push(*facultyBST);
}
