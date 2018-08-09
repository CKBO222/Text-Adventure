

#include <iostream>
#include <string>
#include "aRoom.h"
#include "anExitList.h"
#include "anItemList.h"

using namespace std;

aRoom::aRoom() {
    short_desc = "";
    long_desc = "";
}

void aRoom::set_short_desc(string formal_short_desc) {
    short_desc = formal_short_desc;
}

string aRoom::get_short_desc() {
    return short_desc;
}

void aRoom::set_long_desc(string formal_long_desc) {
    long_desc = formal_long_desc;
}

string aRoom::get_long_desc() {
    return long_desc;
}

void aRoom::addExit(string direction, int toRoom) {
    return exit.addExit(direction, toRoom); // DONT NEED BRACKETS
}

int aRoom::findExit(string direction) {
    return exit.findExit(direction);
}

void aRoom::addItem(string name, string description, bool canTake) {
    return item.addItem(name, description, canTake);
}

int aRoom::findItem(string name) {
    return item.findItem(name);
}

anItem aRoom::removeItem(int index) {
    return item.removeItem(index);
}

void aRoom::displayItems() {
    item.displayItems("");
}

void aRoom::displayExits() {
    exit.displayExits();
}

void aRoom::enter() {
    cout << get_short_desc() << endl;
    displayExits();
}

void aRoom::look() {
    cout << get_long_desc();                // display the long description, the cout is added, and then display items
	if(item.getNumItems() != 0) {
		cout << "You notice the following: ";
		displayItems();
	}
}

void aRoom::examine(string name, anItemList & inventory) {
    if(name == "") {                        // if given an empty string for a name
        cout << "Examine what?";
    }
    
    else if(inventory.findItem(name) != -1) {           // if the item can be found in the inventory
        int index;
        anItem item_name;
        
        index = inventory.findItem(name);
        item_name = inventory.getItem(index);
        cout << item_name.getDescription();
    }
    
    else if(item.findItem(name) != -1){                 //if the item can be found in the item list
        int index;
        anItem item_name;
        
        index = item.findItem(name);
        item_name = item.getItem(index);
        cout << item_name.getDescription();
    }
    else {
        cout << "There is no " << name;                 // if the item can't be found
    }
}
    
void aRoom::take(string name, anItemList & inventory) {
        
    anItem item_name;
    anItem removed_item;
        
    if(name == "") {                                    // if the string name is empty
        cout << "Take what?\n";
    }
        
    else if(item.findItem(name) == -1) {                // if the item can't be found in the room inventory.
        cout << "There is no " << name << endl;
    }
        
    else if(item.findItem(name) != -1) {                // if the item can be found
        int index;
            
        index = item.findItem(name);
        item_name = item.getItem(index);
            
        if(item_name.get_canTake() == false) {          // but can't be taken
            cout << "That cannot be taken\n";
        }
        else if(item_name.get_canTake() == true) {      // but can be taken
            cout << "You take the " << name << endl;
            removed_item = item.removeItem(index);
            inventory.addItem(removed_item);
        }
            
    }                                                   // end of else if
}                                                       // end of take()

void aRoom::drop(string name, anItemList & inventory) {
    anItem removed_item;
    int index;
    
    if(name == "") {
        cout << "Drop what?\n";
    }
    
    else if(inventory.findItem(name) == -1) {
        cout << "You don't have a " << name << endl;
    }
    
    else if(inventory.findItem(name) != -1) {
        index = inventory.findItem(name);             //find the index of the item you want to remove.
        inventory.removeItem(index);                  // remove it.
        cout << "You drop the " << name << endl;
    }
}

void aRoom::print() {
    cout << "ROOM: short = " << short_desc << endl;
    cout << long_desc << endl;
    item.print();                                       // print for anItemList and anExitList data members
    exit.print();
    cout << endl;
}
   










