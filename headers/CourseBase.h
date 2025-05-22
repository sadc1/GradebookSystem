#ifndef COURSEBASE_H
#define COURSEBASE_H
#include <string>
#include <vector>
//#include "CourseSection.h"
class CourseSection;
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
        friend ostream& operator<<(ostream& os, const CourseBase& obj) {
            os << obj.dept << obj.courseId << " " << obj.name;
            return os;
        }
};

#endif