#ifndef ASSIGNMENTSUBMISSION_H
#define ASSIGNMENTSUBMISSION_H
#include <string>
#include <iostream>
#include <fstream>
#include "Grade.h"
#include "Date.h"
using namespace std;

class AssignmentSubmission {
    private:
        int studentId;
        Grade grade;
        Date dateSubmitted;
        ofstream attachment; //write to this to save attachment
    public:
        AssignmentSubmission(int studentI, Date submissionTime, string attachmentDirectory);
        Grade getGrade() {return grade;}
};

#endif