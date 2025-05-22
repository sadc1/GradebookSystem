#include "Gradebook.h"
#include "Address.h"
#include "Assignment.h"
#include "CourseBase.h"
#include "CourseSection.h"
#include "Date.h"
#include "Grade.h"
#include "GradebookLibrary.h"
#include "Student.h"
#include <fstream>
#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>
using namespace std;

void Gradebook::StudentInit() {
    ifstream file("students.txt");
    if (!file) {
        throw runtime_error("Student text file failed to open.");
    }
    file >> studentAmount;
    students = new Student[studentAmount];
    for (int i = 1; i <= studentAmount; i++) {
        string first;
        string last;
        string add;
        file >> first;
        file >> last;
        getline(file, add);
        students[i] = Student(first, last, i, Address(add));
    }
    file.close();
}

void Gradebook::CourseInit() {
    ifstream file("courses.txt");
    if (!file) {
        throw runtime_error("Courses text file failed to open.");
    }
    file >> courseAmount;
    for (int i = 1; i <= courseAmount; i++) {
        string deptAndId;
        string dept;
        string id;
        string name;
        file >> deptAndId >> name;
        dept = deptAndId.substr(0, 4);
        id = deptAndId.substr(4);
        addCourse(new CourseBase(dept, stoi(id), name));
        ifstream sectionFile(dept + id);
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

Gradebook::Gradebook(vector<CourseBase*> courseList) {
    StudentInit();
    CourseInit();
    // try {
    //     init();
    // } catch (const runtime_error& error){
        
    // }
}