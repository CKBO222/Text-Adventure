

#include <iostream>
#include <string>
#include <sstream>

#include "anItemList.h"
#include "aRoom.h"

using namespace std;

#ifndef aGame_hpp
#define aGame_hpp

const int MAX_ROOMS = 20;  // Initialize everything

class aGame{ // this
public:
    aGame();
    void print();
    void play();
private:
    anItemList player_inven;
    anItemList win_inven;
    aRoom rooms[MAX_ROOMS];
    int num_rooms;
    int win_room;
    int current_room;
    string win_text;
    int splitFirst(string aline, string & first, string & rest);
    //BELOW are the sub-methods for play
    void logo();
    void help_message();
    void read_file();
    void gameplay();
};

#endif /* aGame_hpp */
