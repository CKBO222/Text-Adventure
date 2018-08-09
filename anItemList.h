

#include <iostream>
#include <string>
#include "anItem.h"

using namespace std;

#ifndef anItemList_h
#define anItemList_h

const int MAX_ITEMS = 10;

class anItemList { //initialize everything
public:
    anItemList();
    void addItem(anItem item_object);
    void addItem(string name, string description, bool canTake);
    anItem getItem(int index);
    anItem removeItem(int index);
    int findItem(string search_name);
    int getNumItems();
    void print();
    void displayItems(string message);
private:
    anItem object_arrays[MAX_ITEMS];
    int num_items;
};

#endif /* anItemList_hpp */
