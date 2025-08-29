# Grading Book Project (C++)
Made as an honors project. Intended to be used for future grading for when I become a teacher. For now, all data is stored locally and any data made is just test cases.

HOW TO USE:
CMAKE Version 4.0.2 for Windows.
MSYS2 MINGW64/32
Build/recompile in PowerShell: 
    if not in build folder do ->     cd --build
    cmake --build .
Run executable in PowerShell (ends up in build folder named GradebookSystem.exe):
    .\GradebookSystem.exe

Explanation:
The Gradebook class handles everything, made in the main file. The Gradebook consists of
-A dynamic array of Student objects
-A vector containing pointers to CourseBase objects

The Student consists of
-First name, last name, id from the order they are in within test/students.txt, an Address object
-A vector containing pointers to CourseSection objections

The CourseBase object consists of
-The department name, the (4-digit) ID number of the course, and the title of the course
-A vector containing pointers to CourseSection objects

The CourseSection consists of
-The section ID, e.g. MW11
-A pointer to the CourseBase object that it is a section of
-A vector containing pointers to Student objects that are in that section
-A vector containing pointers to Assignment objects (not implemented as of v0.0.3).

students.txt:
    # of students
    FirstName LastName BlockNumberStreet City StateAcronym Zipcode
    etc.

courses.txt:
    # of courses
    DepartmentCOURSEID (together) CourseTitle
    etc.

sections .txt files:
    #SectionID (# is a delimiter to separate the sections)
    FirstName LastName
    FirstName LastName
    etc.

To Finish/Implement:
    Spreadsheet capability
    JSON parsing?
    Assignment class
    Assignment grading