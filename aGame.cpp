

#include <iostream>
#include <sstream>
#include <fstream>
#include "aGame.h"
#include "anItem.h"
#include "anExit.h"
#include "anItemList.h"
#include "aRoom.h"

aGame::aGame() { // this
    num_rooms = 0;
    win_room = 0;
    current_room = 0;
    win_text = "";
}

void aGame::print() {
    cout << "GAME: currRoom=" << current_room << " winRoom=" << win_room << " winText=" << win_text << endl;
    cout << "GAME WIN INVENTORY: \n";
    win_inven.print();
    cout << "GAME PLAYER INVENTORY: \n";
    player_inven.print();
    cout << "GAME: numRooms = " << num_rooms << endl;
    for (int i = 0; i < num_rooms; i++)
        rooms[i].print();
} // print()

int aGame::splitFirst(string aline, string & first, string & rest) {
    first = rest = "";                // init results to empty string
    if (aline == "") return 0;        // if nothing to split, we're done
    string next;                     // next word in aline
    istringstream iss(aline);        // converts aline into a input string stream
    iss >> first;                   // extract the first word, if any
    iss >> rest;                    // extract the second word, if any
    if (rest == "") return 1;       // if the second word is empty, only 1 word in aline
    iss >> next;                    // extract the third word, if any
    while (iss && next != "") {     // while there are more words in the stream
        rest = rest + " " + next;   //       stick it on the end of rest
        iss >> next;                //       get the next word, if any
    }
    return 2;                       // aline was split into two parts.
} // splitFirst()
void aGame::logo() {					
    
    cout << "+--------------------------------------------------------+\n";
    cout << "|                      SimpleQuest						  |\n";
    cout << "|                  by Christopher Bond                   |\n";
    cout << "+--------------------------------------------------------+\n";
}

void aGame::help_message() {
    cout << "Discover a task to complete.  Complete it by finding/taking\n";
    cout << "items from places throughout the world, then dropping the items";
    cout << " in the place instructed.  Good Luck!\n";
    cout << "Commands;\n";
    cout << "- look:          see the room description, objects, and exits.\n";
    cout << "- exa <object>:  Examine an object in the room or inventory.\n";
    cout << "- inv:           See a list of your inventory.\n";
    cout << "- drop <object>: Drop inventory object in the room.\n";
    cout << "- take <object>: Take object from room into your inventory.\n";
    cout << "- help:          Display this menu again.\n";
    cout << "- quit:          Exit the game.\n";
    cout << "- print:         For debugging: Print internal data structures.\n";
    cout << "ALSO: All exits are commands to take the exit.\n";
}

void aGame::read_file() {
    ifstream infile;
    string user_file, aline, first, rest, rest2, direction;
    int split_value, new_num, i = 0;
    bool bool_value;
    
    cout << "Enter game data file name: "; 
    cin >> user_file;
    
    infile.open(user_file);
    
    first = "a";                                      // to get the loop started
    while (first != "END:") {                         // .good() until the end of the file is reached
        getline(infile, aline);                       // read in a line
        split_value = splitFirst(aline, first, rest); // split the line, assign the return value to split value
                                                      // assign the first word to first, and the rest to rest.
        if(split_value == 2) {
            if(first == "WIN_ROOM:"){
                win_room = stoi(rest);                //stoi to convert string to integer
            }
            
            else if(first == "WIN_ITEM:"){
                win_inven.addItem(rest, "", true);   //May be worth asking about. Could only add the win item to the list
            }                                        // by using the 3 argument additem.  It has no desc yet, and can take
            else if(first == "WIN_TEXT:"){
                win_text = rest;
            }
            while(first == "ROOM:") {
                rooms[i].set_short_desc(rest);      //Add the name of the room to the list
                getline(infile, aline);
                rooms[i].set_long_desc(aline);      // Set the description of the room
                getline(infile, aline);
                splitFirst(aline, first, rest);
                while(first == "ROOM_ITEM:") {
                    splitFirst(rest, first, rest2);
                    if(first == "false"){           //if the bool value is false
                        bool_value = false;
                    }
                    else {
                        bool_value = true;
                    }
                    getline(infile, aline);         // get the description of the item
                    rooms[i].addItem(rest2, aline, bool_value);
                    getline(infile, aline);         //move on to the next line after the Room item description
                    splitFirst(aline, first, rest);
                }
                while(first == "EXIT:") {
                    splitFirst(rest, first, rest2);
                    new_num = stoi(first);
                    direction = rest2;
                    rooms[i].addExit(direction, new_num);
                    getline(infile, aline);         // get a new line after the first exit is complete
                    splitFirst(aline, first, rest); // split that new line again
                }
                i += 1;
                num_rooms += 1;
            }                                       // end of first == Room while
        }                                           // end of split_value if
    }                                               // end of split value while
    infile.close();                                 // close the file
}

void aGame::gameplay() {
    string user_input, first, rest, temp, new_room;
    bool winning_cond = false, sentinal = false;
    int win_inven_num, win_inven_num2 = 10000000;
    anItemList item_name;
    
    cout << "==> ";
    getline(cin, temp);
    getline(cin, user_input);
    splitFirst(user_input, first, rest);
	if (first == "quit") {
		cout << "Good bye!\n";
		sentinal = true; 
		system("pause");
	}
    while(sentinal != true && winning_cond != true) {
        if(first == "look"){
            rooms[current_room].look();
			cout << endl;
            rooms[current_room].displayExits();
            }                                                 // end of above if
        else if(first == "exa") {
            rooms[current_room].examine(rest, player_inven); // search for and get desc of that item
			cout << endl;
        } // end of if
        
        else if(first == "take") {
            rooms[current_room].take(rest, player_inven);    // take the item from the room
        }
        
        else if(first == "drop") {
            
			rooms[current_room].drop(rest, player_inven);   // drop it from the player inven
			rooms[current_room].addItem(rest, "" , true);
	
            win_inven_num = win_inven.getNumItems();	    // Only sets variable through the first drop iteration
			if (win_inven_num2 > win_inven_num) {
				win_inven_num2 = win_inven_num;
			}
            if(current_room == win_room && (win_inven.findItem(rest) != -1)) { // if the item is in the win inventory and   the player is in the win room when the item is dropped
				win_inven_num2 -= 1;										   // subtract 1 from the win_inven_num2                        variable.  When that is 0, you win.
                if(win_inven_num2 == 0) {
                    winning_cond = true;
                    cout << win_text << endl;
					system("pause");
					return;
                }                                          // end of nested if
            }                                              //end of parent if
            
        }                                                  // end of else if
        
        else if(first == "inv") {
            if(player_inven.getNumItems() == 0) {
                player_inven.displayItems("You are holding nothing ");
            }
            
            else if(player_inven.getNumItems() > 0) {
                player_inven.displayItems("You are holding ");
                cout << endl;
            }
        }                                                 // end of else if for inv
        else if(first == "help") {
            help_message();
        }
        
        else if(first == "quit") {
            cout << "Good bye!\n";
			sentinal = true;
			system("pause");
			return;
        }
        
        else if(first == "print") {
            rooms[current_room].print();
        }
        
        else{
            if(rooms[current_room].findExit(first) != -1) { // CHANGED IT FROM REST TO FIRST
                current_room = rooms[current_room].findExit(first);
                rooms[current_room].enter();
            }                                               // end of if
        }                                                   // end of else
       
        cout << "==> ";
        getline(cin, user_input);
        splitFirst(user_input, first, rest);
    }                                                       // end of while
}                                                           // end of gameplay

void aGame::play(){
    
    logo();                                                 // display the logo
    read_file();                                            // display the file
    help_message();                                         //display the help message
    system("pause"); 
    system("cls");
    cout << "You fall asleep and enter the world of dream...\n";
    rooms[current_room].enter();
    gameplay();
    
}


