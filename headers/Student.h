#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "Address.h"
#include "CourseSection.h"
#include "vector"
using namespace std;

class Student {
    private:
        string first;
        string last;
        int id;
        Address address;
        vector<CourseSection*> courseList;
    public:
        Student() {first = "default"; last = "default"; id = 0; address = Address();}
        Student(string first, string last, int id, Address address) : first(first), last(last), id(id), address(address) {}
        vector<CourseSection*>& getCourseList() {return courseList;}
        void addCourse(CourseSection* course) {courseList.push_back(course);}
};

#endif