#ifndef STUDENTROSTER_STUDENT_H
#define STUDENTROSTER_STUDENT_H
#pragma once
#include <string>
#include "degree.h"
#include <string>
#include <ios>
#include <iomanip>
using std::cout;
using std::setw;
#include "degree.h"


class student  {
//int age,  int daysLeft_in_CourseCompletion[],
public:
    student();

    student(string studentID,string firstName,string lastName,string emailAddress,int age, int daysLeft_in_CourseCompletion[0], DegreePrograms degreeType);
    student(student *pStudent);

//<--------------------------SETTERS/MUTATORS---------------------------------------------------------------->>
    void setStudentID(string r);
    void setFirstName(string b);
    void setlastName(string c);
    void setEmailAddress(string d);
    void setAge(int e);
    void setDaysLeft_in_CourseCompletion(int* daysLeft_in_CourseCompletion);
    void setDegree(DegreePrograms degreeType);
//<----------------------------GETTERS/ACCESSORS-------------------------------------------------------------->>
    string getStudentID();
    string getFirstName();
    string getlastName();
    string getEmailAddress();
    int getAge();
    int  getDaysLeft_in_CourseCompletion();
    DegreePrograms getDegreeProgram();
//<------------------------------------------------------------------------------------------>>
    public:
    static const int arraySizeDegree = 3;
    DegreePrograms degreeType;
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age=0;
    int daysLeft_in_CourseCompletion[arraySizeDegree];
    static const int e;
    string degreePicked;
    string degreeToPrint;
/*Additional Functions -------------------> */
    void print();


};
#endif //STUDENTROSTER_STUDENT_H
