#ifndef GRADEBOOK_H
#define GRADEBOOK_H
#include <string>
#include <vector>
#include <Student.h>
#include "CourseBase.h"
#include "CourseSection.h"
using namespace std;

//For now as of v0.0.1, this is only a gradebook for one course section.
class Gradebook {
    private:
        Student* students;
        int studentAmount;
        int courseAmount;
        vector<CourseBase*> courseBaseList;
        void StudentInit();
        void CourseInit();
    public:
        Gradebook();
        vector<CourseBase*>& getCourseList() {return courseBaseList;}
        void addCourse(CourseBase* c) {courseBaseList.push_back(c);}
        Student* getStudent(string first, string last);
        Student* getStudent(int id);
};

#endif