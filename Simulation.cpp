#include "Simulation.h"

using namespace std;


Simulation::Simulation()
{
  studentImage = new BinarySearchTree<Student>();
  facultyImage - new BinarySearchTree<Faculty>();
  studentTreeImages = new GenStack<BinarySearchTree<Student>>(5);
  facultyTreeImages = new GenStack<BinarySearchTree<Faculty>>(5);
  studentTreeImages->push(*studentImage);
  facultyTreeImages->push(*facultyImage);
}

Simulation::~Simulation();
{

}

void Simulation::printStudentAscending()
{
  studentImage->printEntireTree();
}

void Simulation::printFacultyAscending()
{
  facultyImage->printEntireTree();
}

void Simulation::displayStudent()
{
  string studentID;
  cout << "Enter Student ID Number: " << endl;
  cin >> studentID;

  Student instance(stoi(studentID)); //FIXME
  if (studentImage->searchNode(instance))
  {
    //cout << studentImage->recPrint(instance) << endl;
  }
  else
  {
    cout << "There is no student with this ID number." << endl;
  }
}

void Simulation::displayFaculty()
{
  string facultyID;
  cout << "Enter Faculty ID Number: " << endl;
  cin >> facultyID;

  Faculty instance(stoi(facultyID));
  if (facultyImage->searchNode(instance))
  {
    //cout << facultyImage->find(instance) << endl;
  }
  else
  {
    cout << "There is no faculty with this ID number." << endl;
  }
}

void Simulation::getAdvisor()
{
  string studentID;
  cout << "Enter Student ID Number: " << endl;
  cin >> studentID;
  Student instance(stoi(studentID));
  if (studentImage->searchNode(instance))
  {
    //Student currStudent = studentImage->find(instance);
    //cout << facultyImage->find(currStudent.advisor);
  }
  else
  {
    cout << "There is no student with this ID number." << endl;
  }
}

void Simulation::getStudents()
{
  string facultyID;
  cout << "Enter Faculty ID Number: " << endl;
  cin >> facultyID;
  Faculty instance(stoi(facultyID));
  if (facultyImage->searchNode(instance))
  {
    //Faculty currFaculty = facultyImage->find(instance);
    /*for (int i = 0; i < currFaculty.advisees.size(); ++i)
    {
      //get each advisee out of the vector
    }*/
  }
  else
  {
    cout << "There is no faculty with this ID number." << endl;
  }
}

void Simulation::addStudent()
{
  string studentID;
  cout << "Enter Student's ID: " << endl;
  cin >> studentID;
  cin.clear();

  string studentName;
  cout << "Enter Student's Name: " << endl;
  cin >> studentName;
  cin.clear();

  string studentLevel;
  cout << "Enter Student's Level: " << endl;
  cin >> studentLevel;
  cin.clear();

  string studentMajor;
  cout << "Enter Student's Major: " << endl;
  cin >> studentMajor;
  cin.clear();

  string studentGPA;
  cout << "Enter Student's GPA: " << endl;
  cin >> studentGPA;
  cin.clear();
}

  string studentAdvisor;
  cout << "Enter Student's Advisor ID: " << endl;
  cin >> studentAdvisor;
  cin.clear();
  if (facultyImage->searchNode(stoi(studentAdvisor)))
  {
    Student currStudent = Student(stoi(studentID), studentName, studentLevel, studentMajor, stud(studentGPA), stoi(studentAdvisor));
    studentImage->insertNode(currStudent);
    //add student to advisor list
    //facultyImage->find(stoi(studentAdvisor)).advisees.insert(advisees.end(),stoi(studentID)));
    studentTreeImages->push(*studentImage);
    facultyTreeImages->push(*facultyImage);
  }
  else
  {
    cout << "There is no faculty with this ID number. " << endl;
  }
}

void Simulation::deleteStudent()
{
  string studentID;
  cout << "Enter Student ID: " << endl;
  cin >> studentID;

  int studentAdvisor;

  Student instance(stoi(studentID));
  if (studentImage->searchNode(instance))
  {
    //studentAdvisor = studentImage->find(instance).advisor;
    studentImage->recDelete(instance);
    //delete student from advisors list
    studentTreeImages->push(*studentImage);
    facultyTreeImages->push(*facultyImage);
  }
  else
  {
    cout << "There is no student with this ID number. " << endl;
  }
}

void Simulation::addFaculty()
{
  string facultyName;
  cout << "Enter Faculty's Name: " << endl;
  cin >> facultyName;
  cin.clear();

  string facultytLevel;
  cout << "Enter Faculty's Level: " << endl;
  cin >> facultyLevel;
  cin.clear();

  string facultyDepartment;
  cout << "Enter Faculty's Department: " << endl;
  cin >> facultyDepartment;
  cin.clear();

  Faculty instance = Faculty(facultyName, facultyLevel, facultyDepartment);
  facultyImage->insertNode(instance);
  studentTreeImages->push(*studentImage);
  facultyTreeImages->(*facultyImage);
}

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

  /*if (facultyImage->searchNode(transferFaculty) && facultyImage->searchNode(facToDelete))
  {
    GenList<int> *rem = facultyImage->find(currFaculty).advisees;
    while (rem->getSize() != 0)
    {
      int oldID = rem->removeFront();
      Student facultyStudent = Student(oldID);
      studentImage->find(facultyStudent).setAdvisor(stoi(facToTransfer));
      facultyImage->find(transferFaculty).advisees->insertFront(oldID);
    }
    facultyImage->recDelete(currFaculty);
    studentTreeImages->push(*studentImage);
    facultyTreeImages->push(*facultyImage);
  }
  else
  {
    cout << "There is no faculty with this ID number. " << endl;
  } */
}

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
	if (studentImage->searchNode(currStudent) && facultyImage->searchNode(newAdvisor))
	{
		studentImage->find(currStudent).setAdvisor(stoi(newAdvisorID)); // finds the student and gives them a new advisor
		facultyImage->find(newAdvisor).addAdvisor(stoi(studentID)); // vice versa
		facultyImage->find(studentImage->find(currStudent).newAdvisorID).deleteAdvisor(stoi(studentID)); // deletes this student from its former advisor's list
		studentTreeImages->push(*studentImage);
		facultyTreeImages->push(*facultyImage);
	}
	else
		cout << "There is no faculty with this ID number. " << endl; */
}

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

  if (studentImage->searchNode(studentToDelete) && facultyImage->searchNode(currFaculty))
  {
    //studentImage->find(studentToDelete).setAdvisor(0);
    //facultyImage->find(studentImage->find(studentToDelete).advisorID).deleteFaculty(stoi(studentID));
    studentTreeImages->push(*studentImage);
    facultyTreeImages->push(*facultyImage);
  }
  else
  {
    cout << "There is no student with that ID number. " << endl;
  }
}

void Simulation::rollback()
{
  //rollback
}
