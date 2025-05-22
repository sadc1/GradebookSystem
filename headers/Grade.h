#ifndef GRADE_H
#define GRADE_H
#include <string>
#include <vector>
using namespace std;

class Grade {
    private:
        double grade;
    public:
        Grade(double grade) : grade(grade) {}
        double getGrade() {return grade;}
        Grade& operator+=(double amount) {
            grade += amount;
        }
};

#endif