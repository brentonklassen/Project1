/*
Assignment class header
*/

#ifndef __ASSIGNMENT_H__
#define __ASSIGNMENT_H__
#include "Date.h"
#include <string>
#include <iostream>
using namespace std;

class Assignment {
public:
	enum
	{
		LATE = -1,
		ASSIGNED = 0,
		COMPLETED = 1,
	} Status;
	//enum getStatus() { return Status; }
	Assignment::Assignment() : assignedDate(), dueDate(), description("") {}
	Assignment::Assignment(Date anAssignedDate, Date aDueDate, std::string aDescription) : assignedDate(anAssignedDate), dueDate(aDueDate), description(aDescription)
	{
		Status = ASSIGNED;
	}
	//Assignment::~Assignment(); // this was causing a lnk error
	Date getAssignedDate() const { return assignedDate; }
	bool operator ==(Assignment other){
		return assignedDate == other.assignedDate &&
			dueDate == other.dueDate && description == other.description && Status == other.Status;
	}
	//not sure status needs to be checked here? Let's discuss - it's probably best to leave it as is, however

private:
	Date assignedDate;
	Date dueDate;
	std::string description;
};

#endif