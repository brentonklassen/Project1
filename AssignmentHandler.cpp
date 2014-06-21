/*
Assignment handler implimentation
*/

#include "AssignmentHandler.h"
#include "StringTokenizer.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
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

void AssignmentHandler::completeAssignment(const Assignment& theAssignment)
{
	completeAssignments.insert(theAssignment);
	completeAssignments.remove(theAssignment);
}

void AssignmentHandler::editAssignment()
{
	
}

void AssignmentHandler::displayAssignments()
{

}

int AssignmentHandler::getLateAssignments()
{
	return 0; // temporary return
}

void AssignmentHandler::readAssignmentsFromFile(const string& fName)
{
	//fstream assignedList("assignedAssignments.txt", ios::app | ios::in | ios::out);
	//fstream completedList("completedAssignmnets.txt", ios::app | ios::in | ios::out);
	fileName = fName;
	ifstream in(fName.c_str(), ios::app);
	if (in)
	{
		Date assignedDate, dueDate;
		string aDate, dDate, desc, line;
		while (getline(in, line))
		{
			String_Tokenizer stLine(line, ",");
			aDate = trim(stLine.next_token());
			String_Tokenizer stDate(aDate, "/");
			assignedDate.setMonth(stoi(trim(stDate.next_token())));
			assignedDate.setDay(stoi(trim(stDate.next_token())));
			assignedDate.setYear(stoi(trim(stDate.next_token())));
			
		}
	}
	else
		cout << "File Doesn't Exist" << endl;
	/*
	void Phone_Directory::load_data(const string& source_name)
	{
		// Remember the source name for use by save.
		this->source_name = source_name;
		// Create an input stream for this file.
		ifstream in(source_name.c_str());
		if (in) { // Stream exists.
			string line;
			string the_name;
			string the_job_description;
			string the_phone_number;
			string the_room_number;
			while (getline(in, line)) {
				String_Tokenizer st(line, ",");
				string last_name = trim(st.next_token());
				string first_name = trim(st.next_token());
				the_name = first_name + " " + last_name;
				the_job_description = trim(st.next_token());
				the_phone_number = trim(st.next_token());
				the_room_number = trim(st.next_token());
				add_entry(Employee(the_name, the_job_description, the_phone_number,
					the_room_number));
			}
		}
		// Close the file.
		in.close();
		*/
}

string AssignmentHandler::trim(const string& the_string)
{
	size_t p = the_string.find_first_not_of(" ");
	if (p == string::npos) return "";
	size_t q = the_string.find_last_not_of(" ");
	return the_string.substr(p, q - p + 1);
}