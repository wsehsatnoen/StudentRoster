#include <iostream>
#include "student.h"

// CONSTRUCTOR:
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[3], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    if (daysInCourse != nullptr) { // Checking to see if the daysInCourse[] has data or not.
        for (int i = 0; i < 3; i++) { // If so, store the data.
            this->daysInCourse[i] = daysInCourse[i];
        }
    } else {
        for (int i = 0; i < 3; i++) { // If not, set the data to 0.
            this->daysInCourse[i] = 0;
        }
    }
    this->degreeProgram = degreeProgram;
}


// GETTERS:
string Student::GetStudentID() const {
	return studentID;
}

string Student::GetFirstName() const {
    return firstName;
}

string Student::GetLastName() const {
    return lastName;
}

string Student::GetEmailAddress() const {
    return emailAddress;
}

int Student::GetAge() const {
    return age;
}

const int* Student::GetDaysInCourse() const { // c++ does not allow for returning arrays in functions, but instead allows a pointer to be returned
    return daysInCourse;
}

DegreeProgram Student::GetDegreeProgram() const {
    return degreeProgram;
}


// SETTERS:
void Student::SetStudentID(string newStudentID) {
    this->studentID = newStudentID;
}

void Student::SetFirstName(string newStudentFirstName) {
    this->firstName = newStudentFirstName;
}

void Student::SetLastName(string newStudentLastName) {
    this->lastName = newStudentLastName;
}

void Student::SetEmailAddress(string newStudentEmail) {
    this->emailAddress = newStudentEmail;
}

void Student::SetAge(int newStudentAge) {
    this->age = newStudentAge;
}

void Student::SetDaysInCourse(int newDaysInCourse[3]) {
    for (int i = 0; i < 3; ++i) {
        this->daysInCourse[i] = newDaysInCourse[i]; 
    }
}

void Student::SetDegreeProgram(DegreeProgram newDegreeProgram) {
    this->degreeProgram = newDegreeProgram;
}


// PRINT FUNCTION:
void Student::Print() const {
    cout << this->studentID << "\tFirst Name: ";
    cout << this->firstName << "\tLast Name: ";
    cout << this->lastName << "\tAge: ";
    cout << this->age << "\t daysInCourse: ";
    cout << "{" << this->GetDaysInCourse()[0];
    cout << ", " << this->GetDaysInCourse()[1];
    cout << ", " << this->GetDaysInCourse()[2];
    cout << "}\tDegree Program: ";
    DegreeProgram dpHolder = this->GetDegreeProgram();
    if (dpHolder == SECURITY) {
        cout << "Security." << endl;
    }
    else if (dpHolder == NETWORK) {
        cout << "Network." << endl;
    }
    else {
        cout << "Software." << endl;
    }
}