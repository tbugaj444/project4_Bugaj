#pragma once
#include <iostream>
#include "Slot.h"
#include "student.h"
#include <algorithm>

using namespace std;
#define MAXHASH 1000

template <class t> class hashtable
{
private:
	Slot<t> table[MAXHASH];
	int numtable[MAXHASH];
public:

	hashtable() {
	
		//creates random rehash array
		for (int i = 0;i < MAXHASH;i++) {
			numtable[i] = i;
		}
		random_shuffle(begin(numtable)+1, end(numtable));
	
	}
	Slot<t>* index(int val) {
	
		return &table[val];
	
	}
	//uid mod tablesize; simple hash function used
	int hashfunction(int value) {
		int t = (value % MAXHASH);
		return t;
	}
	//recursive insert function. passes number of collisions to find which index of random hash to insert into
	//inserts based on slot type
	//overwrites any values/keys placed in tombstone spot
	//ignores matching keys

	bool insert(int key, t value, int collisions) {
		int t = hashfunction(key + numtable[collisions++]);
		if (collisions >= MAXHASH||key==index(t)->getKey()) {
			return false;
		}
		if (index(t)->isEmpty()|| index(t)->isTombstone()) {
			table[t] = Slot<student>(key, value);
		}
		else if (index(t)->isNormal()) {
			insert(key, value, collisions);
		}
		return true;
	}
	//turns slot into a tombstone that matches passed key
	//doesnt remove value or key
	bool remove(int key) {
		for (int i = 0;i < MAXHASH;i++) {
			if (key == index(hashfunction(key+numtable[i]))->getKey()) {
				Slot<student>* g = &table[hashfunction(key + numtable[i])];
				g->kill();
				return true;
			}

		}
		return false;
	
	}
	//returns false if not found
	//if found, value is passed
	bool find(int key, t& value) {
		for (int i = 0;i < MAXHASH;i++) {
			if (key == index(hashfunction(key + numtable[i]))->getKey()) {
				Slot<student>* g= &table[hashfunction(key + numtable[i])];
				value = g->getValue();
				return true;

			}

		}
		return false;
	}
	// finds n/m; where m is table size and n is number of items in table
	float alpha() {
		float count = 0;
		for (int i = 0;i < MAXHASH;i++) {
			if (index(i)->isNormal()) {
				count++;
			}
		}
		return count / MAXHASH;
	}

	
	~hashtable() {
	
	}
};

