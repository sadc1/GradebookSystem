#ifndef GRADEBOOK_H
#define GRADEBOOK_H
#include <string>
#include <vector>
//#include <Student.h>
class Student;
//#include "CourseBase.h"
class CourseBase;
//#include "CourseSection.h"
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
        Gradebook(const Gradebook& other);
        ~Gradebook();
        Gradebook& operator=(const Gradebook& other);
        Student* getStudent(string first, string last);
        Student* getStudent(int id);

        Student* getStudentList() {return students;}
        int getStudentAmount() {return studentAmount;}
        int getCourseAmount() {return courseAmount;}
        vector<CourseBase*>& getCourseList() {return courseBaseList;}
        void addCourse(CourseBase* c) {courseBaseList.push_back(c);}
};

#endif