#include "FileManager.h"

#include <iostream>

using namespace std;

int main(int argc, char **argv) {

    Simulation* sim = new Simulation();
    FileManager* fm = new FileManager(sim);

    fm->loadData();

    sim->printStudentAscending();
    sim->printFacultyAscending();

    Student* s = new Student(5, "Bobby", "Freshman", "Theater", 3.25, 92);

    fm->saveData();

    delete sim;
    delete fm;

    return 0;
}
