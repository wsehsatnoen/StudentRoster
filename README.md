# Student Roster
 
*A C++ course project (WGU C867 — Scripting and Programming: Applications) built to practice classes, dynamic memory management, and manual memory cleanup.*
 
## What It Does
 
- Builds a roster of students from a fixed set of input data
- Adds and removes students from the roster
- Validates email addresses and flags any that are invalid
- Calculates each student's average days spent across their courses
- Filters and prints students by degree program (Security, Network, or Software)
- Manages its own memory manually — the `Roster` class holds a dynamically allocated array of `Student` pointers and cleans it up in its destructor
## Tech
 
C++, no external libraries or smart pointers — memory is allocated and released by hand as part of the assignment's focus.
 
## Running It
 
Open `StudentRoster.sln` in Visual Studio and build/run, or compile `main.cpp`, `roster.cpp`, and `student.cpp` directly with a C++ compiler (e.g. `g++ main.cpp roster.cpp student.cpp -o roster && ./roster`).
 
## Note
 
This was an early exercise in core C++ concepts (classes, pointers, destructors) rather than a full application — no persistence, no external input, no tests. Kept here as a record of fundamentals, not a flagship project.
