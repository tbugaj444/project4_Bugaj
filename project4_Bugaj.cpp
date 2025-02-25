#pragma once
// project4_Bugaj.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "hashtable.h"
#include "student.h"
#include "Slot.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>


using namespace std;


int main()
{

	hashtable<student> table;
	//random comment
	//random comment2
	string choice = "";
	
	//menu options loop
	while (choice != "Q") {
		cout << "Options" << "\n"<<
			"(I)nsert \n"<<
			"(D)elete \n"<<
			"(S)earch \n"<<
			"(Q)uit \n";
		getline(cin, choice);
		if (choice == "I") {
			//generates random uid's
			int uidGen = (rand() * 503);
			string f, l, m, g;

			cout << "First Name: \n";
			getline(cin, f);
			cout << "Last Name: \n";
			getline(cin, l);
			cout << "Major:(i.e. CS, CEG, EE) \n";
			getline(cin, m);
			cout << "Grade:(F)resh, (S)oph, (J)unior, (Se)nior \n";
			getline(cin, g);
			//converts to year to pass to student constructor
			year y;
			if (g == "F") {
				 y = freshman;
			}
			else if (g == "S") {
				 y = sophmore;
			}
			else if (g == "J") {
				 y = junior;
			}
			else if (g == "Se") {
				y = senior;
			}
			else {
				cout << "Grade invalid" << endl;
			}
			student temp(uidGen, f, l, m, y);
			bool ins = table.insert(uidGen, temp, 0);
			if (ins) {
				cout << "Inserted" << endl;
			}
			else {
				cout << "Insertion incomplete" << endl;
			}

		}
		else if (choice == "D") {
			cout << "Enter Key to be Removed:" << endl;
			string key;
			getline(cin,key);
			//to int conversion
			int val = atoi(key.c_str());
			bool del = table.remove(val);
			if (val) {
				cout << "Deleted" << endl;
			}
			else {
				cout << "item not found" << endl;
			}
		}
		else if (choice == "S") {
			student f;

			cout << "Enter key:" << endl;
			string key;
			getline(cin, key);

			int val = atoi(key.c_str());
			bool found = table.find(val, f);
			if (found) {
				cout << "Student Found:" << endl;
				cout << f << endl;
			}
			else {
				cout << "Student not Found" << endl;
			}

		}
		else if(choice == "Q") {
			cout << "Exiting";
		
		}
		else {
			cout << "Invalid request \n";
			cout << "Please enter 'I', 'D', 'S', or 'Q' \n";
		}
	}

    return 0;
}

