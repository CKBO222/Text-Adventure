

#include "anItem.h"

anItem::anItem(){ // Create the definitions 
    name = "";
    canTake = false;
}

void anItem::setName(string new_name) {
    name = new_name;
}

string anItem::getName(){
    return name;
}

void anItem::setDescription(string new_description) {
    description = new_description;
}

string anItem::getDescription(){
    return description;
}

void anItem::set_canTake(bool t_or_f){
    canTake = t_or_f;
}

bool anItem::get_canTake(){
    return canTake;
}

void anItem::print() {
    cout << "ITEM: name=" << name << " canTake=" << canTake << " desc=" << description;
}
