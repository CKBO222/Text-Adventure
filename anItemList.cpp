

#include "anItemList.h"

anItemList::anItemList(){
    num_items = 0;
}

void anItemList::addItem(anItem item_object){
    
    if(num_items < MAX_ITEMS) {
        object_arrays[num_items] = item_object;         //append to the array and then add 1.
        num_items += 1;
    }
    
    else {
        cout << "The list was full, error";            //if num_items is not less than max_items
    }
}

void anItemList::addItem(string name, string formal_description, bool canTake){
    anItem new_obj;
    
    new_obj.setName(name);                            // set the new values
    new_obj.setDescription(formal_description);
    new_obj.set_canTake(canTake);
    addItem(new_obj);
}

anItem anItemList::getItem(int index) {
    if((index < 0) || (index > num_items)) {
        cout << "Error, out of range";
        return anItem();
    }
    else {
        return object_arrays[index];
    }
}

anItem anItemList::removeItem(int index) {          // to remove an item from a list and create a blank space at the end
    anItem rem;
    if((index >= 0) && (index < num_items)) {
        rem = object_arrays[index];                 // copy of the removed item;
        num_items--;
        for(int i = index; i < num_items; i++) {
            object_arrays[index] = object_arrays[i + 1];
        }
        return rem;
    }
    else{
        cout << "Error, could not remove item from the list";
        return anItem();
    }
}

int anItemList::findItem(string search_name){
    for(int i = 0; i < num_items; i++){
        if(search_name == object_arrays[i].getName()){
            return i;                               // if the search name is found, immediately return the index value.
        }
    }
    return -1;                                      // will only execute if the if statement above is never true.
}

int anItemList::getNumItems() {
    return num_items;
}

void anItemList::print() {
    cout << "ITEMLIST: numItems=" << num_items << endl;     //print an itemlist
    for (int i = 0; i < num_items; i++) {
        object_arrays[i].print();
    }
}

void anItemList::displayItems(string message) {
    if(num_items == 0 && message == "") {                   // if numitems is 0 and given empty string
        cout << "\n"; 
    }
    
    else if(num_items == 0 && message != ""){
        cout << message << endl;
    }
    
    else if(num_items > 0) {
        cout << message << "";
        for(int i = 0; i < num_items; i++) {
            cout << object_arrays[i].getName();
            if(i < num_items - 1) {                 // the purpose of if and else if is when to use the commas and period.
                cout << ", ";
            }                                       // end of if
            else if(i == num_items - 1){
                cout << ".";
            }                                       // end of else if
        }                                           // end of for
}
}



