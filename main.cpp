#include <iostream>
#include "roster.h"
#include "degree.h"
using namespace std;
using std::setw;

int main()
{

    roster classRoster;
    student newStudent;
    classRoster.add();


    classRoster.printAll();
    classRoster.printInvalidEmails();
    classRoster.printAverageDaysInCourse("A2");
    classRoster.printByDegreeProgram(SECURITY);
    classRoster.remove("A5");
    classRoster.printAll();
    classRoster.remove("A5");

}