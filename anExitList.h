

#include <iostream>
#include <string>
#include "anExit.h"

using namespace std;

#ifndef anExitList_h
#define anExitList_h

const int MAX_EXITS = 5;

class anExitList{ // initialize everything 
public:
    anExitList();
    void addExit(anExit exit_obj);
    void addExit(string formal_direction, int toRoom);
    string getExit(int index);
    int findExit(string formal_direction);
    int getNumExits();
    void displayExits();
    void print();
    
private:
    anExit exit_array[MAX_EXITS];
    int numExits;
};


#endif /* anExitList_hpp */
