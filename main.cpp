/*
CS303 Data Structures
Project 1
Due July 1, 2014
Team members: Jordan Larson, Evan Bell, Brenton Klassen
*/

#include "AssignmentHandler.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
void menu(AssignmentHandler);

void main()
{
	/* examples of how to use classes below */

	AssignmentHandler Assignments;

	Assignments.importAssignmentsFromFile("Assignments.txt");
    Assignments.displayAllAssignments(cout);
    



	system("pause");
}

void menu(AssignmentHandler asgmntHndlr)
{
	string commands[] = {
		"Add a New Assignment",
		"Completed an Assignment",
		"Edit an Assignment",
		"Print List of Assignments",
		"Save List of Assignments",
		"Exit" };
	const size_t NUM_COMMANDS = 9;
	size_t choice = NUM_COMMANDS - 1;
	do {
		for (size_t i = 0; i < NUM_COMMANDS; i++) {
			cout << "Select: " << i << " " << commands[i] << "\n";
		}
		cin >> choice;
		cin.ignore(numeric_limits<int>::max(), '\n');
		switch (choice) {
		case 0: asgmntHndlr.addAssignment(); break;
		//case 1: do_change_entry(the_directory); break;
			//case 2: do_lookup_entry(the_directory); break;
			//case 3: do_remove_entry(the_directory); break;
			//case 4: do_save(the_directory); break;
			//case 5: do_save(the_directory); break;
		}
	} while (choice < NUM_COMMANDS - 1);
}
