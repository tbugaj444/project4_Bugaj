#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
enum year { freshman, sophmore, junior, senior, null };

class student
{
private:
	int uid;
	string fname;
	string lname;
	string major;
	year grade;
public:
	student() {
		uid = 0;
		fname = "";
		lname = "";
		major = "";
		grade = null;

	
	
	}
	student(int a, string b, string c, string d, year e) {
		uid = a;
		fname = b;
		lname = c;
		major = d;
		grade = e;
	
	}
	int getuid() {
		return this->uid;
	}
	friend ostream& operator<<(ostream& os, const student& me) {
	
		os << me.fname << endl;
		os << me.lname << endl;
		os << me.uid << endl;
		os << me.major << endl;
		os << me.grade << endl;
		return os;
	}

	~student() {

	}
};

