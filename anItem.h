

#include <iostream>
#include <string>

using namespace std;

#ifndef anItem_h
#define anItem_h

class anItem { //Initialize everything needed  
public:
    void setName(string new_name);
    string getName();
    void setDescription(string new_description);
    string getDescription();
    void set_canTake(bool t_or_f);
    bool get_canTake();
    anItem();
    void print();
private:
    string name;
    string description;
    bool canTake;
};
#endif /* anItem_h */
