#include "degree.h"
#include "roster.h"
#include "student.h"

int main() {
	
	// My Information:
	cout << "Course    : Scripting and Programming - Applications - C867\n";
	cout << "Language  : C++\n";
	cout << "StudentID : 012336566\n";
	cout << "Name      : Shane Darilek\n\n";
	
	// Building the Roster:
	const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Shane,Darilek,swdarilek@gmail.com,24,20,20,18,SOFTWARE" };
	Roster classRoster(studentData, 5, 20);

	// Lets print it:
	cout << "Students: \n";
	classRoster.PrintAll();

	// Now lets check for invalid emails:
	cout << "\n\nInvalid Emails: \n";
	classRoster.PrintInvalidEmails();

	// Parsing through the roster to get each student's average days in courses:
	cout << "\n\nStudent's Average Days in Course:\n";
	for (int i = 0; i < classRoster.GetNumStudents(); i++) {
		classRoster.PrintAverageDaysInCourse(classRoster.GetStudentIDFromIndex(i));
	}

	// Printing all the students in requested degree program:
	cout << "\n\nStudents in Software Program:\n";
	classRoster.PrintByDegreeProgram(SOFTWARE);

	// Removing a student:
	cout << endl << endl;
	classRoster.Remove("A3");

	// Printing the updated roster:
	cout << "\nUpdated Roster:\n";
	classRoster.PrintAll();

	// Verrifying that the student was removed by trying again:
	cout << "\nAttempting to remove student A3 again: \n";
	classRoster.Remove("A3");

	// Now that the program is about to terminate, the destructor for classRoster will
	// execute, releasing the allocated memory for each student first, then releasing the memory
	// allocated for the roster itself.

	return 0;

}