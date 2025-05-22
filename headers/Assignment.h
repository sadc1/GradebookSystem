#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include <string>
#include <iostream>
#include <fstream>
#include "Grade.h"
#include "Date.h"
#include "AssignmentSubmission.h"
using namespace std;

class Assignment {
    private:
        string name;
        string instructions;
        int assignmentId;
        int courseId;
        Date dueDate;
        bool autograde;
        vector<AssignmentSubmission> submissionList;
    public:
        Assignment(string name, string instr, int aId, int cId, Date due, bool autograde = false);
};

#endif