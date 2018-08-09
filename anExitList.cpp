
#include <iostream>
#include <string>
#include "anExitList.h"
#include "anExit.h"

using namespace std;

anExitList::anExitList() {
    numExits = 0;
}

void anExitList::addExit(anExit exit_obj) {
    
    if(numExits < MAX_EXITS) {
        exit_array[numExits] = exit_obj;                //Append an exit and then add one
        numExits += 1;
    }
    else {
        cout << "Error, the list is full\n";            // if an exit cannot be added
    }
}

void anExitList::addExit(string formal_direction, int toRoom) {
    anExit exit_obj;
    
    exit_obj.setDirection(formal_direction);            //give the direction and room number
    exit_obj.set_toRoom(toRoom);
    addExit(exit_obj);
}

string anExitList::getExit(int index){
    if((index < 0) || (index > numExits)) {            // if not in range
        cout << "Error, out of range\n";
        return "";
    }
    else {
        return exit_array[index].getDirection();       // if in range
    }
}

int anExitList::findExit(string formal_direction) {
    for(int i = 0; i < numExits; i++){
        if(formal_direction == exit_array[i].getDirection()) {
            return exit_array[i].get_toRoom();        // return the array value not the index
        }
    }
    cout << "There was an error.\n";
    return -1;
}

int anExitList::getNumExits() {
    return numExits;
}

void anExitList::displayExits() {
    if(numExits == 0) {                              // if the num of exits is 0
        cout << "There are no exits\n";
    }
    
    else if(numExits > 0) {                          // if the num of exits is greater than 0
        cout << "EXITS: ";
        for(int i = 0; i < numExits; i++) {
			cout << exit_array[i].getDirection();
			if (i < numExits - 1) {
				cout << ", ";
			}

			else if(i == numExits - 1) {
				cout << ".\n";
			}
        }
    }
}

void anExitList::print() {
    cout << "\nEXITLIST: numExits=" << numExits << endl;
    for (int i = 0; i < numExits; i++) {           // print the array of exits.
        exit_array[i].print();
        }
}



