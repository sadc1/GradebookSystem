#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>
#include "Address.h"
//#include "CourseSection.h"
class CourseSection;
using namespace std;

class Student {
    private:
        string first;
        string last;
        int id;
        Address address;
        vector<CourseSection*> courseList;
    public:
        Student() {first = "default"; last = "default"; id = -1; address = Address();}
        Student(string first, string last, int id, Address address) : first(first), last(last), id(id), address(address) {}
        vector<CourseSection*>& getCourseList() {return courseList;}
        string getFirst() {return first;}
        string getLast() {return last;}
        Address& getAddress() {return address;}
        string fullName() {return first + " " + last;}
        void addCourse(CourseSection* course) {courseList.push_back(course);}
        friend ostream& operator<<(ostream& os, const Student& obj) {
            os << obj.first << " " << obj.last << " " << obj.id;
            return os;
        }
        //Student& operator=(const Student& other); Doesn't seem necessary, same for CourseSection, CourseBase, Address, etc. Just watch out for shared pointers and don't delete them from multiple places.
};

#endif