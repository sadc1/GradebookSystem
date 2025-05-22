#ifndef COURSESECTION_H
#define COURSESECTION_H
#include <string>
#include <vector>
//#include "CourseBase.h"
class CourseBase;
//#include "Assignment.h"
class Assignment;
//#include "Student.h"
class Student;
using namespace std;

//Since only pointers are held to Student, Assignment, and CourseBase, only forward declaration is needed "class x." instead of includes.
//If there were data types of them, then that would require the include.
class CourseSection {
    private:
        string sectionId;
        CourseBase* course;
        vector<Student*> studentList;
        vector<Assignment*> assignmentList;
    public:
        CourseSection(string sectionId, CourseBase* course) : sectionId(sectionId), course(course) {};
        vector<Assignment*>& getAssignmentList() {return assignmentList;}
        vector<Student*>& getStudentList() {return studentList;}
        void addAssignment(Assignment* as) {assignmentList.push_back(as);}
        void addStudent(Student* s) {studentList.push_back(s);}
        friend ostream& operator<<(ostream& os, const CourseSection& obj) {
            os << obj.sectionId;
            return os;
        }
};

#endif