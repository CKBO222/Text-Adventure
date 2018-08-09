

#include "anExit.h"

anExit::anExit(){ // simple definitions 
    toRoom = -1;
    direction = "";
}

void anExit::set_toRoom(int room_num) {
    toRoom = room_num;
}

int anExit::get_toRoom(){
    return toRoom;
}

void anExit::setDirection(string name) {
    direction = name;
}

string anExit::getDirection() {
    return direction;
}

void anExit::print() {
    cout << "EXIT:  toRoom=" << toRoom << " direction=" << direction;
}
