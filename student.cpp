#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;


student::student(){};
student::student(string studentID,string firstName,string lastName,string emailAddress,int age,int daysLeft_in_CourseCompletion[0], DegreePrograms degreeType)
{
    for (int e=0;e<3;e++) this->daysLeft_in_CourseCompletion[e] = daysLeft_in_CourseCompletion[e];
    this->firstName=firstName;
    this->lastName=lastName;
    this->studentID=studentID;
    this->emailAddress=emailAddress;
    this->age=age;
    this->degreeType=degreeType;


     /*   cout << "From student constructor " << "Student ID: " << studentID << " | First name: " << firstName
             << " | Last Name: " << lastName << " | Email Address :" << emailAddress << " | age: " << age
             << " | Classes left: " << daysLeft_in_CourseCompletion[0] << "," << daysLeft_in_CourseCompletion[1] << "," << daysLeft_in_CourseCompletion[2] << " " << degreeType << endl;*/
    };
//<--------------------------------SETTERS/MUTATORS---------------------------------------------------------->>
void student::setStudentID(string a)
{
    studentID = a;
}
//<-------------------------------------->>for(int t=0;t<3;){int daysLeft_in_CourseCompletion[t]}
void student::setFirstName(string b)
{
    firstName = b;
}
//<-------------------------------------->>
void student::setlastName(string c)
{
    lastName = c;
}
//<-------------------------------------->>
void student::setEmailAddress(string d)
{
    emailAddress = d;
}
//<-------------------------------------->>
void student::setAge(int e)
{
    age = e;
}
//<-------------------------------------->>
void student::setDaysLeft_in_CourseCompletion(int* daysLeft_in_CourseCompletion){
    for( int x=0;x<3;x++)
    {
        this->daysLeft_in_CourseCompletion[x] =daysLeft_in_CourseCompletion[x];
    }
}
//<-------------------------------------->>
void student::setDegree(DegreePrograms   dt)
{
    degreeType=dt;
}
//<-------------------------------------->>

//<----------------------------GETTERS/ACCESSORS-------------------------------------------------------------->>
string student::getStudentID()
{
  //  cout <<studentID<<'\t'<<'\t'<<'\t';
    return studentID;
}
//<-------------------------------------->>
string student::getFirstName()
{
  //  cout<<firstName<<'\t'<<'\t'<<'\t';
    return firstName;
}
//<-------------------------------------->>
string student::getlastName()
{
  //  cout<<lastName<<'\t'<<'\t'<<'\t';
    return lastName;
}
//<-------------------------------------->>
string student::getEmailAddress()
{
  //  cout <<emailAddress<<'\t'<<'\t'<<'\t';
    return emailAddress;
}
//<-------------------------------------->>
int student::getAge(){
  //  cout << age<<'\t'<<'\t'<<'\t';
    return age;
}
//<-------------------------------------->>
int  student::getDaysLeft_in_CourseCompletion(){
        daysLeft_in_CourseCompletion[2] = daysLeft_in_CourseCompletion[2];
        cout <<daysLeft_in_CourseCompletion[0]<<","<<daysLeft_in_CourseCompletion[1]<<","<<daysLeft_in_CourseCompletion[2]/10;
           return 0;
}
//<-------------------------------------->>
DegreePrograms student::getDegreeProgram()
{

    if(degreeType == SECURITY)
    {
        degreePicked = "SECURITY";

        cout<<"SECURITY";
        return this->degreeType;
    }
    else if(degreeType == NETWORK)
    {
        degreePicked = "NETWORK";
        cout<<"NETWORK";
        return this->degreeType;
    }
    else if(degreeType == SOFTWARE)
    {
        degreePicked = "SOFTWARE";
       cout<<"SOFTWARE";
        return this->degreeType;

    }

}
//<-------------------------------------->>
 void student::print(){

    cout << getStudentID() << "\t "<< "\t ";
    cout << getFirstName() << "\t "<< "\t "<< right << setw(10) ;
    cout << getlastName() << right << setw(10) ;
    cout << getAge() << "\t ";
    cout << getDaysLeft_in_CourseCompletion() << "\t "<< "\t ";
    cout << getEmailAddress() << "\t ";
    if(getDegreeProgram() == 0){}


}


//<-------------------------------------->>
student::student(student *pStudent) {
};
//<------------------------------------------------------------------------------------------>>



