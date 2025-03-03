#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "student.h"

using namespace std;

class Roster {
public:

	// Constructors and Destructors
	Roster(const string studentData[], int numStudents, int maxClassSize);
	~Roster();

	// Functions
	void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void Remove(string studentID);
	
	// Print Functions
	void PrintAll();
	void PrintAverageDaysInCourse(string studentID);
	void PrintInvalidEmails();
	void PrintByDegreeProgram(DegreeProgram degreeProgram);

	// Getters
	int GetNumStudents() const;
	string GetStudentIDFromIndex(int studentIndex);
private:

	// Pointer to an array of pointers
	Student** classRosterArray;
	
	int numStudents;
	int maxClassSize;

};