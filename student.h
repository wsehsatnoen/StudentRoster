#pragma once

#include <string>
#include "degree.h"

using namespace std;

class Student {
public:

    // Constructor:
    // Due to Dynamically Allocating these objects in the roster class, the student
    // object must have default parameters.
    Student(string studentId = "EX", string firstName = "Jane", string lastName = "Doe", string emailAddress = "Example@example.com", int age = 0, int daysInCourse[3] = nullptr, DegreeProgram degreeProgram = SOFTWARE);
    
    // Getters:
    string GetStudentID() const;
    string GetFirstName() const;
    string GetLastName() const;
    string GetEmailAddress() const;
    int GetAge() const;
    const int* GetDaysInCourse() const;
    DegreeProgram GetDegreeProgram() const;
    
    // Setters:
    void SetStudentID(string newStudentID);
    void SetFirstName(string newStudentFirstName);
    void SetLastName(string newStudentLastName);
    void SetEmailAddress(string newStudentEmail);
    void SetAge(int newStudentAge);
    void SetDaysInCourse(int newDaysInCourse[3]);
    void SetDegreeProgram(DegreeProgram newDegreeProgram);
    
    // Print Function:
    void Print() const;


private:

    // Variables:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;

};

