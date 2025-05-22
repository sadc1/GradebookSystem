#include "Address.h"
#include "Assignment.h"
#include "CourseBase.h"
#include "CourseSection.h"
#include "Date.h"
#include "Grade.h"
#include "Gradebook.h"
#include "Student.h"
using namespace std;

int main() {
    cout << "Testing" << endl;
    Gradebook* gradebook = new Gradebook();
    cout << "Printing all students and addresses" << endl; 
    for (Student* sptr = gradebook-> getStudentList(); sptr < gradebook -> getStudentList() + gradebook-> getStudentAmount(); sptr++) {
        cout << sptr -> fullName() << " " << sptr -> getAddress().formattedAddress() << endl;
    }
    cout << "Printing all courses" << endl;
    for (auto it = gradebook->getCourseList().begin(); it < gradebook -> getCourseList().end(); it++) {
        cout << **it << endl; //Print CourseBase
        for (CourseSection* sectionPtr : (*it) -> getSectionList()) {
            cout << *sectionPtr << ": "; //Print CourseSection
            for (Student* studentPtr : sectionPtr -> getStudentList()) {
                cout << *studentPtr << endl; //Print every student in the section
            }
        }
    }
    
    return 0;
}