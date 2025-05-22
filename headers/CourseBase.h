#ifndef COURSEBASE_H
#define COURSEBASE_H
#include <string>
#include <vector>
#include "CourseSection.h"
using namespace std;

class CourseBase {
    private:
        string name;
        string dept;
        int courseId;
        vector<CourseSection*> sectionList;
    public:
        CourseBase(string dept, int id, string name) : dept(dept), courseId(id), name(name) {};
        vector<CourseSection*>& getSectionList() {return sectionList;}
        void addSection(CourseSection* sec) {sectionList.push_back(sec);}
};

#endif