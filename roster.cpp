#pragma once
#include <iostream>
#include "roster.h"
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

roster::roster(){};

student myStudent;

student *classRosterArray[5];
student *tempHolder[5];

void roster::add()
{
    /////////////////////////////////////////////////BEGINNING  OF ADD STUDENT SECTION///////////////////////////////////////////////
    cout << "|--------------------------------------------------------------------------------------------------|"   << endl ;
    cout << "|Scripting and Programming - Applications   C867                                                   "  << endl;
    cout << "|Robert Bradbury  rbradb5@my.wgu.edu " << " C++ Course  Student ID 001467937                       "  << endl ;
    cout << "|--------------------------------------------------------------------------------------------------|"  << endl ;
    /////////////////////////////////////////////////DATA PARSING SECTION START/////////////////////////////////////////////////////
    istringstream SS;                    // Input stream
    string studentInfo;                 // first Holds line of text
    string studentID;                  // ID name
    string firstName;                 // First name
    string lastName;                 // Last name
    string emailAddress;            // email
    string string_Age;            // Age
    string string_firstClass;    // firstClass
    string string_secondClass;   // secondClass
    string string_thirdClass;  // thirdClass
    string degree;             // degree

    const string studentData[5] =
            {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
             "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
             "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
             "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
             "A5,Robert,Bradbury,rbradb5@my.wgu.edu,39,10,20,30,SOFTWARE"
            };
    cout << setfill('*') << setw(150) << ""
         << endl;///////////HEADER SECTION///////////////////////////////////////////////////////////
    cout << setfill(' ') << endl;
    cout << "STUDENTID"  << "\t "<< "FIRSTNAME"  << "\t "<< right << setw(10) << "LASTNAME"  << right << setw(10)<< "AGE"
    << "\t "<< "TIME_IN_CLASSES"  << "\t " << "EMAIL" << "\t "  << "\t "<< "\t "<<"DEGREE" << endl;

    for (int r = 0; r < 5; r++) {

        studentInfo = studentData[r];
        SS.clear();
        string token;
        SS.str(studentInfo);

        getline(SS, studentID, ',');
        getline(SS, firstName, ',');
        getline(SS, lastName, ',');
        getline(SS, emailAddress, ',');
        getline(SS, string_Age, ',');
        getline(SS, string_firstClass, ',');
        getline(SS, string_secondClass, ',');
        getline(SS, string_thirdClass, ',');
        getline(SS, degree, ',');
        //getline(SS,firstName, ',');
        // Entire line into lineString
        // Copies to SS's string buffer
        //////////////////////////////////PARSING THE STRING AND EXTRACTING INTEGERS FOR AGE AND THE CLASSES TIMES////////////////
        SS >> studentID;
        SS >> firstName;
        SS >> lastName;
        SS >> emailAddress;
        SS >> string_Age;
        SS >> string_firstClass;
        SS >> string_secondClass;
        SS >> string_thirdClass;
        SS >> degree;

        stringstream seek(string_Age);
        int Age;
        seek >> Age;
        stringstream seek1(string_firstClass);
        int firstClass;
        seek1 >> firstClass;
        stringstream seek2(string_secondClass);
        int secondClass;
        seek2 >> secondClass;
        stringstream seek3(string_thirdClass);
        int thirdClass;
        seek3 >> thirdClass;

        int daysLeft[3] = {firstClass, secondClass, thirdClass};
        //////////////////////////////////////////////DATA PARSING SECTION END/////////////////////////////////////////////////////

        ///////////////////////////////////////////////SETTER/MUTATOR SECTION//////////////////////////////////////////////////////
        myStudent.setStudentID(studentID);
        myStudent.setFirstName(firstName);
        myStudent.setlastName(lastName);
        myStudent.setEmailAddress(emailAddress);
        myStudent.setAge(Age);
        myStudent.setDaysLeft_in_CourseCompletion(daysLeft);
        if (degree == "SECURITY") {
            myStudent.setDegree(SECURITY);
        } else if (degree == "NETWORK") {
            myStudent.setDegree(NETWORK);
        } else if (degree == "SOFTWARE") {
            myStudent.setDegree(SOFTWARE);
        }

        ///////////////CREATING OBJECTS AND STORING THEM IN ARRAY SECTION, ALSO SETTING THE RIGHT DEGREE PER STUDENT ////////////////

        if (degree == "SECURITY") {
            classRosterArray[r] = student(studentID, firstName, lastName, emailAddress, Age, daysLeft, SECURITY);
        } else if (degree == "NETWORK") {
            classRosterArray[r] = student(studentID, firstName, lastName, emailAddress, Age, daysLeft,  NETWORK);
        } else if (degree == "SOFTWARE") {
            classRosterArray[r] = student(studentID, firstName, lastName, emailAddress, Age, daysLeft,  SOFTWARE);
        }

    }
        /////////////////////////////////////////////////END OF ADD STUDENT SECTION/////////////////////////////////////////////////////

}
///////////////////////COURSE FUNCTIONS BELOW: //////////////////////////////////////


void  roster::printAll()
{
    cout<<"<-------------------------------------------------PRINT ALL STUDENTS--------------------------------------------------->"<<endl;
    for (int r = 0; r <lastIndex; ++r)
    {
        classRosterArray[r].print();
        cout<<endl;

    }
    cout<<endl;
    cout<<"<---------------------------------------------------------------------------------------------------------------------->"<<endl;

};
/////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////


void  roster::printByDegreeProgram(DegreePrograms SOFTWARE)
{
    DegreePrograms  DegType = SOFTWARE;
    cout<<"<--------------------PRINT BY PROGRAM OUTPUT------------------------------------------>"<<endl;

    for (int r = 0; r < 5; ++r)
    {
        if(classRosterArray[r].degreeType == DegType)
        {
            cout <<endl;
            cout << classRosterArray[r].getStudentID() << "\t "<< "\t ";
            cout << classRosterArray[r].getFirstName() << "\t "<< "\t "<< right << setw(10) ;;
            cout << classRosterArray[r].getlastName()<< right << setw(10) ;
            cout << classRosterArray[r].getAge() << "\t ";
            cout << classRosterArray[r].getEmailAddress() << "\t ";

            cout << classRosterArray[r].getDaysLeft_in_CourseCompletion() << "\t ";
            if(classRosterArray[r].getDegreeProgram() == 0){}

        }

    }
    cout<<endl;
    cout<<"<---------------------------------------------------------------------------------------------------------------------->"<<endl;

};
/////////////////////////////////////////////////////////////////////////////////////

void  roster::printAverageDaysInCourse(string studentID)
{
    cout<<"<------------------------------PRINT BY AVERAGE DAYS IN COURSES--------------------------------->"<<endl;
    string thisID = studentID;

    for (int r = 0; r < 5; ++r)
    {
        // cout <<  classRosterArray[r].studentID<<endl;
        if(thisID == classRosterArray[r].studentID )
        {
            int sum= classRosterArray[r].daysLeft_in_CourseCompletion[0] + classRosterArray[r].daysLeft_in_CourseCompletion[1] + classRosterArray[r].daysLeft_in_CourseCompletion[2];
            int Average = sum/3;
            cout <<"Data for student with student  ID : "<<thisID<<endl;
            cout<<"Average time spent per course: "<<Average<<endl;

        }

    }

    cout<<endl;
    cout<<"<---------------------------------------------------------------------------------------------------------------------->"<<endl;

};
/////////////////////////////////////////////////////////////////////////////////////

void   roster::printInvalidEmails()
{
    cout<<"<------------------------------PRINT BY INVALID EMAIL ADDRESSES--------------------------------->"<<endl;

    for (int r = 0; r < 5; ++r)
    {
        string goodEmailsAddresses = classRosterArray[r].getEmailAddress();
        if((goodEmailsAddresses.find('@') == std::string::npos ) || (goodEmailsAddresses.find('.') == std::string::npos) ||(goodEmailsAddresses.find(' ') != std::string::npos))
        {
            cout <<"The following email address is invalid : " << classRosterArray[r].getEmailAddress()<<"   "<<goodEmailsAddresses<<endl;

        }
    }
    cout<<endl;
    cout<<"<---------------------------------------------------------------------------------------------------------------------->"<<endl;

};

/////////////////////////////////////////////////////////////////////////////////////

void roster::remove(string studentID)
{
    int totalStudents = 5;
    int r = 0;
    lastIndex=5;


    cout << "<------------------------------PRINT AFTER STUDENT ID HAS BEEN REMOVED -------------------------> ";

    for (r = 0; r <= lastIndex; r++)
    {
        cout<<endl;
        if (classRosterArray[r].getStudentID() == studentID)
        {
            if (r < totalStudents - 1)
            {
                *tempHolder = classRosterArray[r];
                classRosterArray[r] = classRosterArray[totalStudents - 1];
            }
            lastIndex--;
        }


    }
    ////////////////////////
    if (classRosterArray[r].getStudentID() != studentID)
    {
        cout << " student with ID " << studentID << "  was NOT found" << endl;
    }

}

//////////////////////////////////////////////////////////////////
roster::~roster() {

};
