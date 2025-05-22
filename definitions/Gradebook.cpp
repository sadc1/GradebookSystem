#include "Gradebook.h"
#include "Address.h"
#include "Assignment.h"
#include "CourseBase.h"
#include "CourseSection.h"
#include "Date.h"
#include "Grade.h"
#include "Student.h"
#include <fstream>
#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <filesystem>
using namespace std;

//Current path is GradebookSystem/build as the exe is in there
void Gradebook::StudentInit() {
    filesystem::path filePath = filesystem::current_path() / ".." / "test" / "students.txt"; //Works
    ifstream file(filePath);
    //ifstream file("..test/students.txt");
    //std::filesystem::path currentPath = std::filesystem::current_path(); Current directory printed is the build folder
    //std::cout << "Current directory: " << currentPath.string() << std::endl; 
    if (!file) {
        throw runtime_error("Student text file failed to open.");
    }
    cout << "Successfully found student file" << endl;
    file >> studentAmount;
    students = new Student[studentAmount];
    for (int i = 0; i < studentAmount; i++) {
        string first, last;
        string street, city, state, zip;

        file >> first >> last >> street >> city >> state >> zip;
        cout << first << last << street << city << state << zip << endl;
        students[i] = Student(first, last, i, Address(street, city, state, stoi(zip)));
        cout << students[i].fullName() << endl;
    }
    cout << "Closing student file" << endl;
    file.close();
}

void Gradebook::CourseInit() {
    filesystem::path filePath = filesystem::current_path() / ".." / "test" / "courses.txt";
    ifstream file(filePath);
    cout << "Looking for course file" << endl;
    if (!file) {
        throw runtime_error("Courses text file failed to open.");
    }
    cout << "Opened course file" << endl;
    file >> courseAmount;
    for (int i = 0; i < courseAmount; i++) {
        string deptAndId;
        string dept;
        string id;
        string name;
        file >> deptAndId >> name;
        dept = deptAndId.substr(0, 4);
        id = deptAndId.substr(4);
        addCourse(new CourseBase(dept, stoi(id), name));
        ifstream sectionFile(filePath.parent_path() / "sections" / (dept + id + ".txt"));
        if (!sectionFile) {
            throw runtime_error("Section file not found");
        }
        string line;
        string currentSection;
        while (getline(sectionFile, line)) {
            if (!line.empty() && line[0] == '#') { //Add course section to a course
                currentSection = line.substr(1);
                courseBaseList.back() -> addSection(new CourseSection(currentSection, courseBaseList.back()));
            } else { //Add a student to the course, and course to the student's profile
                istringstream iss(line);
                string first;
                string last;
                iss >> first >> last;
                Student* s = getStudent(first, last);
                courseBaseList.back() -> getSectionList().back() -> addStudent(s);
                s -> addCourse(courseBaseList.back() -> getSectionList().back());
            }
        }
        sectionFile.close();
    }
    file.close();
}

Student* Gradebook::getStudent(string first, string last) {
    for (Student* sptr = students; sptr < students + studentAmount; sptr++) {
        if (sptr -> getFirst() == first && sptr -> getLast() == last) { //worry about duplicates later
            return sptr;
        }
    }
    return nullptr;
}

Student* Gradebook::getStudent(int id) {
    return &students[id];
}

Gradebook::Gradebook() {
    cout << "Running StudentInit" << endl;
    StudentInit();
    cout << "Running CourseInit" << endl;
    CourseInit();
    cout << "Done initializing Gradebook" << endl;
}

Gradebook::Gradebook(const Gradebook& other) {
    students = new Student[other.studentAmount];
    for (int i = 0; i < other.studentAmount; i++) {
        students[i] = other.students[i];
    }
}

Gradebook::~Gradebook() {
    delete[] students;
    students = nullptr;
}

Gradebook& Gradebook::operator=(const Gradebook& other) {
    if (other.students == students) {
        return *this;
    }
    delete[] students;
    students = new Student[other.studentAmount];
    for (int i = 0; i < other.studentAmount; i++) {
        students[i] = other.students[i];
    }
    return *this;
}