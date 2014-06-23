/*
Assignment handler implimentation
*/

#include "AssignmentHandler.h"
#include "StringTokenizer.h"
#include "Date.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <iterator>
using namespace std;

// default, no argument constructor

// function to get number from user and take care of incorrect input
int AssignmentHandler::getNumber(int low, int high, std::string message)
{
	int number;
	bool valid = false;
	if (message == "")
		message = "Enter a number between " + std::to_string(low) + " and " + std::to_string(high) + ": ";
	do
	{
		std::cout << message;
		std::cin >> number;
		while (std::cin.fail())
		{
			std::cout << "You must enter an integer: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			std::cin >> number;
		}
		if (number < low || number > high)
			std::cout << "The number must be between " << low << " and " << high << ".\n";
		else
			valid = true;
	} while (!valid);
	return number;
}

void AssignmentHandler::addAssignment()
{
	Date aDate, dDate;
	string assignedDate, dueDate, desc;

	cout << "Assigned Date: ";
	String_Tokenizer date(assignedDate, "/");

	//assignedAssignments.insert(Assignment(assignedDate, dueDate, desc));
}

void AssignmentHandler::editAssignment()
{

}

void AssignmentHandler::displayAssignment(ostream& out, const Assignment& assignment)
{
    out << "Assigned Date: " << assignment.getAssignedDate() << "\t" << 
        "Due Date: "      << assignment.getDueDate() << "\t" << endl
        << "Assignment Description: " << assignment.getDescription() 
        << "Assignment Status: " << "\t" << assignment.getCurrentStatus() << endl << endl;

}

int AssignmentHandler::getLateAssignments()
{
	return 0; // temporary return
}

void AssignmentHandler::completeAnAssignment(Assignment theAssignment)
{
    
    completeAssignments.insert(theAssignment);
	assignedAssignments.remove(theAssignment);
    theAssignment.completeAssignment();
}

void AssignmentHandler::overdueAnAssignment(Assignment& assignment)
{
    assignment.overdueAssignment();
}




void AssignmentHandler::displayOrderedAssignedAssignmentList(ostream& out)
    {
        OrderedAssignmentList::iterator iter;
        for (iter = assignedAssignments.begin(); iter != assignedAssignments.end(); iter++)
        {
            overdueAnAssignment(*iter);
            displayAssignment(cout, *iter);
        }
    }

void AssignmentHandler::displayOrderedCompletedAssignmentList(ostream& out)
{
    OrderedAssignmentList::const_iterator iter;
    for (iter = completeAssignments.begin(); iter != completeAssignments.end(); iter++)
    {
        displayAssignment(cout, *iter);
    }
}

void AssignmentHandler::displayAllAssignments(ostream& out)
{
    displayOrderedAssignedAssignmentList(out);
    displayOrderedCompletedAssignmentList(out);
}


//reads assignments from file and adds them to the assigned assignments list
void AssignmentHandler::importAssignmentsFromFile(const string& fName)
{
	fileName = fName;
	ifstream in(fName.c_str(), ios::app);
	if (in)
	{
        Assignment* temp_assignment;
		Date assignedDate, dueDate;
		string aDate, dDate, desc, line;
		while (getline(in, line))
		{
			String_Tokenizer stLine(line, ",");
			//read in assigned date
			aDate = trim(stLine.next_token());
			String_Tokenizer stADate(aDate, "/");
			assignedDate.setMonth(stoi(trim(stADate.next_token())));
			assignedDate.setDay(stoi(trim(stADate.next_token())));
			assignedDate.setYear(stoi(trim(stADate.next_token())));
			// read in due date
			dDate = trim(stLine.next_token());
			String_Tokenizer stDDate(dDate, "/");
			dueDate.setMonth(stoi(trim(stDDate.next_token())));
			dueDate.setDay(stoi(trim(stDDate.next_token())));
			dueDate.setYear(stoi(trim(stDDate.next_token())));
			// read in description
			desc = trim(stLine.next_token());
            temp_assignment = new Assignment(assignedDate, dueDate, desc);
            assignedAssignments.insert(*temp_assignment);
		}
	}
	else
		cout << "File Doesn't Exist" << endl;
}

string AssignmentHandler::trim(const string& the_string)
{
	size_t p = the_string.find_first_not_of(" ");
	if (p == string::npos) return "";
	size_t q = the_string.find_last_not_of(" ");
	return the_string.substr(p, q - p + 1);
}