#include <sstream>
#include <string>

#include "roster.h"
#include "student.h"

using namespace std;

// CONSTRUCTOR AND DESTRUCTOR:
// Constructor with built in studentData Parser
Roster::Roster(const string studentData[], int numStudents, int maxClassSize) {
	this->maxClassSize = maxClassSize;
	this->numStudents = numStudents;
	this->classRosterArray = new Student*[maxClassSize]; // Dynamically allocates memory for an array of pointers;

	// studentDataParser that will itterate through the list and parse each string.
	for (int i = 0; i < numStudents; i++) {
		istringstream inSS(studentData[i]); // create the parser
		string data[9]; // creates an array to store data from string
		int age;
		int dic[3] = { 0, 0, 0 }; // daysInCourse (dic) holder for later
		DegreeProgram degreeProgram;


		// Data parser function reading the string up to the ',',
		// storing the data in data[], moving to the next itteration
		// untill there is no more string to parse.
		int x = 0;
		while (inSS.good()) {
			getline(inSS, data[x], ',');
			x += 1;
		}

		// Converts the age string to int data type
		age = stoi(data[4]);
		
		// Converts the three numbers after age into an array and stores in dic[]
		for (int i = 5; i < 8; i++) {
			dic[i-5] = stoi(data[i]);
		}

		// Converts the program string into the DegreeProgram enum data type
		if (data[8] == "SECURITY") {
			degreeProgram = SECURITY;
		}
		else if (data[8] == "NETWORK") {
			degreeProgram = NETWORK;
		}
		else {
			degreeProgram = SOFTWARE;
		}

		// Dynamically Allocates, then creates a new student, finally storing the created pointer from the new
		// function into the classRosterArray
		classRosterArray[i] = new Student(data[0], data[1], data[2], data[3], age, dic, degreeProgram);
		
	}
}

// Destructor that first parses through the classRosterArray, releasing the memory of each
// dynamically allocated student object, then releases the memory allocated from the pointer to the
// classRosterArray
Roster::~Roster() {
	// releases the student objects
	for (int i = 0; i < numStudents; i++) {
		delete this->classRosterArray[i];
		// sets the pointer to null to prevent dangling pointers
		this->classRosterArray[i] = nullptr;
	}

	// releases the classRosterArray
	delete[] this->classRosterArray;
	// sets the pointer to null to prevent dangling pointers
	this->classRosterArray = nullptr;

	cout << "\n\nSuccessfully cleared memory!" << endl;
}

//ROSTER FUNCTIONS:
// Add function
void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	
	int daysInCourse[3] = { 0, 0, 0 };
	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;

	if (this->numStudents == this->maxClassSize) {
		cout << "Class is full... Student was not added." << endl;
	} 
	else {
		classRosterArray[numStudents] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
		this->numStudents += 1;
	}
}

// Remove function
void Roster::Remove(string studentID) {
	bool found = false; // used to check if student exists
	for (int i = 0; i < this->numStudents; i++) {

		if (studentID == classRosterArray[i]->GetStudentID()) {
			cout << "Removing Student: " << classRosterArray[i]->GetStudentID() << endl;
			
			delete this->classRosterArray[i];
			this->classRosterArray[i] = nullptr;
			
			// because an array and not a vector was used, it was necessary for the location of the student pointers
			// to be shifted over so that the functionality of the numStudents variable worked across the program
			for (int j = i; j < numStudents; j++) {
				
				if (j == numStudents - 1) {
					this->classRosterArray[j] = nullptr; // if at the end of the list, it is important to set the pointer to null manually
				}
				
				this->classRosterArray[j] = this->classRosterArray[j + 1]; // takes the next item and moves it to the current location
			
			}
			
			this->numStudents -= 1;
			
			found = true; // 
			
			cout << "Success!" << endl;
			
			break;
		}
	}

	// if student was not found, print:
	if (!found) {
		cout << "Student not found..." << endl;
	}
}


// PRINT FUNCTIONS:
void Roster::PrintAll() {
	for (int i = 0; i < this->numStudents; i++) {
		classRosterArray[i]->Print();
	}
}


void Roster::PrintAverageDaysInCourse(string studentID) {
	
	bool found = false; // Checker variable
	
	for (int i = 0; i < this->numStudents; i++) {
		if (studentID == classRosterArray[i]->GetStudentID()) {
	
			int totalDaysInCourse = 0;
			int averageDaysInCourse;
			
			for (int j = 0; j < 3; j++) {
				totalDaysInCourse += classRosterArray[i]->GetDaysInCourse()[j];
			}
			
			averageDaysInCourse = totalDaysInCourse / 3;
			
			cout << studentID << "'s average Days in Course = ";
			cout << averageDaysInCourse << "." << endl;
			
			found = true;

		}
	}

	if (!found) {
		cout << "Student not found..." << endl;
	}
}

void Roster::PrintInvalidEmails() {
	
	for (int i = 0; i < numStudents; i++) {
		
		string emailHolder = this->classRosterArray[i]->GetEmailAddress();
		
		// Used to check if the character exists for later use in conditional statement:
		size_t foundAt = emailHolder.find("@");
		size_t foundPeriod = emailHolder.find(".");
		size_t foundSpace = emailHolder.find(" ");

		// Check if '@' or '.' are present, and ensure ' ' is not
		if (foundAt == string::npos || foundPeriod == string::npos || foundSpace != string::npos) {
			cout << emailHolder << endl;
		}
	}
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < this->numStudents; i++) {
		if (degreeProgram == classRosterArray[i]->GetDegreeProgram()) {
			this->classRosterArray[i]->Print();

		}
	}
}


// GETTER FUNCTIONS:
int Roster::GetNumStudents() const {
	return this->numStudents;
}

string Roster::GetStudentIDFromIndex(int studentIndex) {
	return this->classRosterArray[studentIndex]->GetStudentID();
}