#ifndef STUDENTROSTER_ROSTER_H
#define STUDENTROSTER_ROSTER_H
#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;

class roster
{
public:

            roster();
            ~roster();            
            istringstream SS;
            void printAll();
            void  printByDegreeProgram(DegreePrograms SOFTWARE);
            void  add();
            void  printAverageDaysInCourse(string studentID);
            void  printInvalidEmails();
            void remove(string studentID);
            int daysLeft[3];
            int ArraySize = sizeof(classRosterArray) / sizeof (classRosterArray[0]);




            string studentID;                  // ID name
            student classRosterArray[5];
            student tempHolder[5];
            int lastIndex=5;

            ///////////////////////////////////////////////


}
;
#endif //STUDENTROSTER_ROSTER_H