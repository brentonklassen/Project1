/*
Assignment handler class
*/

#ifndef __ASSIGNMENTHANDLER_H__
#define __ASSIGNMENTHANDLER_H__
#include "OrderedAssignmentList.h"

class AssignmentHandler {
public:
	AssignmentHandler() : assignedAssignments(), completeAssignments() {} // default constructor
	void addAssignment();
	void completeAssignment(const Assignment&);
	void editAssignment();
	void displayAssignments();
	int getLateAssignments();
	void readAssignmentsFromFile(const string& sourceName);
	string trim(const string&);
private:
	OrderedAssignmentList assignedAssignments;
	OrderedAssignmentList completeAssignments;
	string fileName;
	int getNumber(int, int, std::string = "");
};

#endif
