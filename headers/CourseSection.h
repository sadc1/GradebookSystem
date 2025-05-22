#ifndef COURSESECTION_H
#define COURSESECTION_H
#include <string>
#include <vector>
#include "CourseBase.h"
#include "Assignment.h"
using namespace std;

class CourseSection {
    private:
        string sectionId;
        CourseBase* course;
        vector<Student*> studentList;
        vector<Assignment*> assignmentList;
    public:
        CourseSection(string sectionId, CourseBase* course) : sectionId(sectionId), course(course) {};
        vector<Assignment*>& getAssignmentList() {return assignmentList;}
        void addAssignment(Assignment* as) {assignmentList.push_back(as);}
        void addStudent(Student* s) {studentList.push_back(s);}
};

#endif