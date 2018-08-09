

#include <iostream>
#include <string>
#include "anExit.h"
#include "anItem.h"
#include "anExitList.h"
#include "anItemList.h"

using namespace std;

#ifndef aRoom_h
#define aRoom_h

class aRoom{ 
public:
    aRoom();
    void set_short_desc(string formal_short_desc);
    string get_short_desc();
    void set_long_desc(string formal_long_desc);
    string get_long_desc();
    void addExit(string direction, int toRoom);
    int findExit(string direction);
    void addItem(string name, string description, bool canTake);
    int findItem(string name);
    anItem removeItem(int index);
    void displayItems();
    void displayExits();
    //ROOM COMMAND METHODS BELOW
    void enter();
    void look();
    void examine(string name, anItemList & inventory);
    void take(string name, anItemList & inventory);
    void drop (string name, anItemList & inventory);
    void print();
private:
    string short_desc;
    string long_desc;
    anItemList item; //DONT NEED BRACKETS, anITEMLIST already contains a list as a private member
    anExitList exit;
};

#endif /* aRoom_hpp */
