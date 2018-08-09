

#include <iostream>
#include <string>

using namespace std;

#ifndef anExit_h
#define anExit_h

class anExit { //initialize everything 
public:
    anExit();
    void set_toRoom(int room_num);
    int get_toRoom();
    void setDirection(string name);
    string getDirection();
    void print();
    
private:
    int toRoom;
    string direction;
};

#endif /* anExit_hpp */
