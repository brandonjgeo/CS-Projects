/*
    textAdv.cpp
    Brandon George, CISP360
    12/15/18
 */

//  Themes expressed are inspired by the Fallout franchise produced by Bethesda Softworks LLC

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

class room {
private:
    string room_name, room_description, room_id, occupied_code, exits[4][4], visited;
public:
    room();
    room(string name, string description, string id, string north, string south, string east, string west, string northRoom, string southRoom, string eastRoom, string westRoom);
    void displayRoom(), setExits(string north, string south, string east, string west, string northRoom, string southRoom, string eastRoom, string westRoom), setVisited(), look(), displayExits(), displayName();
    string getVisited(), getName(), getExit(string), getOccupied();
};

room::room() {}
room::room(string name, string description, string id, string north, string south, string east, string west, string northRoom, string southRoom, string eastRoom, string westRoom) {
    room_name = name;
    room_description = description;
    room_id = id;
    setExits(north, south, east, west, northRoom, southRoom, eastRoom, westRoom);
    
    //  Specification B1 - Room Occupied
    //  Determines if room will be occupied by enemy
    int randNum = rand() % (3 - 1 + 1) + 1;
    if (randNum == 1 || randNum == 3) {
        occupied_code = "yes";
    } else if (randNum == 2) {
        occupied_code = "no";
    }
    visited = "no";
}

string room::getName() {
    return room_name;
}

void room::displayName() {
    cout << "NAME: " << room_name << endl << endl;
}

//  Specification C5 - Detailed Look
//  Shows the room title and description everytime the player enters "L" for look.
void room::look() {
    cout << "NAME: " << room_name << endl;
    cout << "DESCRIPTION: " << room_description << endl << endl;
    displayExits();
}

string room::getOccupied() {
    return occupied_code;
}
void room::displayExits() {
    cout << "EXITS: " << endl;
    for (int i = 0; i < 4; i++) {
        if (exits[1][i] == "yes") {
            cout << exits[0][i] << ": " << exits[3][i] << endl;
        }
    }
    cout << endl;
}
string room::getExit(string move) {
    if (move == "N") {
        return exits[3][0];
    } else if (move == "S") {
        return exits[3][1];
    } else if (move == "E") {
        return exits[3][2];
    } else if (move == "W") {
        return exits[3][3];
    }
    return "error";
}
void room::displayRoom() {
    cout << "NAME: " << room_name << endl;
    cout << "DESCRIPTION: " << room_description << endl;
    cout << "ID: " << room_id << endl;
    cout << "OCCUPIED: " << occupied_code << endl;
    cout << "EXITS: ";
    for (int i = 0; i < 4; i++) {
        if (exits[1][i] == "yes") {
            cout << exits[0][i] << ": " << exits[3][i] << ", ";
        }
    }
    cout << endl;
}

//  Sets exits for all rooms.
void room::setExits(string north, string south, string east, string west, string northRoom, string southRoom, string eastRoom, string westRoom) {
    exits[0][0] = "North";
    exits[0][1] = "South";
    exits[0][2] = "East";
    exits[0][3] = "West";
    exits[1][0] = north;
    exits[1][1] = south;
    exits[1][2] = east;
    exits[1][3] = west;
    exits[2][0] = northRoom;
    exits[2][1] = southRoom;
    exits[2][2] = eastRoom;
    exits[2][3] = westRoom;
    for (int i = 0; i < 4; i++) {
        if (exits[1][i] == "yes") {
            if (exits[2][i] == "1") {
                exits[3][i] = "classroom";
            } else if (exits[2][i] == "2") {
                exits[3][i] = "power-room";
            } else if (exits[2][i] == "3") {
                exits[3][i] = "living quarters";
            } else if (exits[2][i] == "4") {
                exits[3][i] = "armory";
            } else if (exits[2][i] == "5") {
                exits[3][i] = "cafeteria";
            } else if (exits[2][i] == "6") {
                exits[3][i] = "commons";
            } else if (exits[2][i] == "exit") {
                exits[3][i] = "exit";
            }
        }
    }
}

void room::setVisited() {
    visited = "yes";
}

string room::getVisited() {
    return visited;
}

//  Specification B10 - Monster Class
//  Creates a class for different level enemies.
class enemy {
private:
    string name;
    int health;
    
public:
    enemy();
    int fight();
    int easyDiceRoll();
    int hardDiceRoll();
};

enemy::enemy() {
    
    //  Specification A1 - Add a enemy
    //  adds additional enemies to defeat.
    int randNum = rand() % (5 - 1 + 1) + 1;
    if (randNum == 1) {
        name = "mutated insect";
        health = 1;
    } else if (randNum == 2) {
        name = "feral ghoul";
        health = 2;
    } else if (randNum == 3) {
        name = "glowing ghoul";
        health = 3;
    } else if (randNum == 4) {
        name = "legendary glowing ghoul";
        health = 4;
    } else if (randNum == 5) {
        name = "super mutant";
        health = 5;
    }
    cout << "An enemy has been spotted! It is a " << name << " with a health of " << health << endl << endl;
}

//  Specification A3 - Combat
//  Creates a combat mechanism related to either the hard or easy dice roll.
int enemy::fight() {
    if (health == 1 || health == 2) {
        return easyDiceRoll();
    } else if (health == 3 || health == 4 || health == 5) {
        return hardDiceRoll();
    }
    return -1;
}

//  Dice roll to defeat a lower level enemy.
int enemy::easyDiceRoll() {
    cout << "To defeat the enemy guess a number from 1 to 3. You need " << health << " point(s) to win. You have 3 chances." << endl;
    int points = 0;
    for (int i = 0; i < 3; i++) {
        int userGuess;
        cout << "Enter (1 to 3): ";
        cin >> userGuess;
        while (userGuess < 1 || userGuess > 3) {
            cout << "Enter a valid number (1 to 3): ";
            cin >> userGuess;
        }
        int randNum = rand() % (3 - 1 + 1) + 1;
        if (userGuess == randNum) {
            cout << "You got it!" << endl;
            points++;
        }
        cout << "You rolled a " << randNum << endl;
        cout << "You have " << points << " point(s)." << endl;
        if (points == health) {
            i = 3;
        }
    }
    if (points == health) {
        cout << "Congrats! You looted " << 10 * health << " supplies!" << endl;
        return 10 * health;
    } else {
        cout << "Try again next time." << endl;
        return 0;
    }
}

//  Dice roll to defeat a higher level enemy.
int enemy::hardDiceRoll() {
    cout << "To defeat the enemy guess a number from 1 to 6. You need " << health - 2 << " point(s) to win. You have 5 chances." << endl;
    int points = 0;
    for (int i = 0; i < 5; i++) {
        int userGuess;
        cout << "Enter (1 to 6): ";
        cin >> userGuess;
        while (userGuess < 1 || userGuess > 6) {
            cout << "Enter a valid number (1 to 6): ";
            cin >> userGuess;
        }
        int randNum = rand() % (6 - 1 + 1) + 1;
        if (userGuess == randNum) {
            cout << "You got it!" << endl;
            points++;
        }
        cout << "You rolled a " << randNum << endl;
        cout << "You have " << points << " point(s)." << endl;
        if (points == health - 2) {
            i = 5;
        }
    }
    if (points == health) {
        cout << "Congrats! You looted " << 10 * health << " supplies!" << endl;
        return 10 * health;
    } else {
        cout << "Try again next time." << endl;
        return 0;
    }
}
class Game {
private:
    room * currentRoom;
    int supplies = 0;
    string newestRoom;
public:
    Game(room * room);
    room & getCurrentRoom();
    void setCurrentRoom(room * ), displayCurrentRoom(), doCommand(string, room * room1, room * room2, room * room3, room * room4, room * room5, room * room6, room * exit), addsupplies(int), displayMap();
    bool checkRoom();
    int getsupplies();
    room * changeastRoom(string, room * , room * , room * , room * , room * , room * , room * );
};
Game::Game(room * room) {
    currentRoom = room;
}
room & Game::getCurrentRoom() {
    return *currentRoom;
}

void Game::displayCurrentRoom() {
    
    //  Specification C4 – Abbreviated Room Description
    //  Displays room title and description the first time a player enters the room.
    if (getCurrentRoom().getVisited() == "yes") {
        getCurrentRoom().displayName();
    } else if (getCurrentRoom().getVisited() == "no") {
        getCurrentRoom().look();
        getCurrentRoom().setVisited();
    }
}

//  If no enemys spawns, the player finds 15 supplies.
bool Game::checkRoom() {
    if (getCurrentRoom().getOccupied() == "yes") {
        return true;
    } else {
        cout << "You found 15 supplies!" << endl;
        addsupplies(15);
        return false;
    }
}
void Game::doCommand(string move, room * room1, room * room2, room * room3, room * room4, room * room5, room * room6, room * exit) {
    if (move == "L") {
        getCurrentRoom().look();
    } else if (move == "X") {
        getCurrentRoom().displayExits();
    } else if (move == "M") {
        displayMap();
    } else {
        newestRoom = getCurrentRoom().getExit(move);
        currentRoom = changeastRoom(newestRoom, room1, room2, room3, room4, room5, room6, exit);
    }
}
void Game::setCurrentRoom(room * room) {
    currentRoom = room;
}
room * Game::changeastRoom(string room, class room * room1, class room * room2, class room * room3, class room * room4, class room * room5, class room * room6, class room * exit) {
    if (room == "classroom") {
        return room1;
    } else if (room == "power-room") {
        return room2;
    } else if (room == "living quarters") {
        return room3;
    } else if (room == "armory") {
        return room4;
    } else if (room == "cafeteria") {
        return room5;
    } else if (room == "commons") {
        return room6;
    } else {
        return exit;
    }
}

//  Specification A4 - Treasure (Supplies)
//  Players will find supplies after defeating an enemy or discovering a room is empty.
void Game::addsupplies(int num) {
    supplies += num;
    cout << num << " supplies were added for a new total of " << supplies << " supplies" << endl;
}

int Game::getsupplies() {
    return supplies;
}

//  Displays minimap of all rooms and exit.
void Game::displayMap() {
    cout << endl << "MAP" << endl;
    cout << left << "_________________________________" << endl;
    cout << left << "|         |           |         |" << endl;
    cout << left << "|         |   exit    |         |" << endl;
    cout << left << "|_________|___________|_________|" << endl;
    cout << left << "| living  |           |         |" << endl;
    cout << left << "| quarters|  commons  |  armory |" << endl;
    cout << left << "|_________|___________|_________|" << endl;
    cout << left << "| power   |           |         |" << endl;
    cout << left << "| room    | classroom |cafeteria|" << endl;
    cout << left << "|_________|___________|_________|" << endl;
    
    cout << "You are currently in the " << getCurrentRoom().getName() << endl << endl;
    
}
void promptPlayer();

int main() {
    srand(time(0));
    cout << fixed << showpoint << setprecision(1);
    
    //  Program Welcome
    // This will display the programs purpose and intent.
    cout << "VaultTec's Disaster Defense Simulation (DDS)" << endl;
    cout << "============================================" << endl;
    cout << "The vault has been compromised." << endl;
    cout << "Goal: get out of the vault alive." << endl << endl;
    
    room ROOM1("classroom", "to obtain knowledge that will help rebuild after nuclear fallout", "1", "yes", "no", "yes", "yes", "5", "", "3", "2");
    room ROOM2("power-room", "to maintain life support systems.", "2", "no", "no", "yes", "no", "", "", "1", "");
    room ROOM3("living quarters", "where the residents rest.", "3", "yes", "no", "no", "yes", "4", "", "", "1");
    room ROOM4("armory", "for protection.", "4", "no", "yes", "no", "yes", "", "3", "", "5");
    
    //  Specification C1 - Five Rooms
    //  Adds an additional room to the list of rooms.
    room ROOM5("cafeteria", "delicious food", "5", "yes", "yes", "yes", "no", "6", "1", "4", "");
    
    //  Specification B7 - Add Rooms
    //  Adds even more rooms to the list of rooms.
    room ROOM6("commons", "the lounge for residents.", "6", "yes", "yes", "no", "no", "exit", "5", "", "");
    room EXIT("exit", "You left the vault.", "no", "no", "no", "no", "no", "", "", "", "");
    
    //  Specification C2 - Player Name
    //  Allows to player to choose a name for themselves.
    string playerName;
    cout << "What is your name? (1 word): ";
    cin >> playerName;
    cout << endl;
    
    //  A mini story that incorporates the players name into the dialogue.
    cout << playerName << " the vault door has been breached and mutated creatures are flooding inside! " << playerName << " we must escape or risk being trapped with limited supplies." << endl;
    
    Game play( & ROOM1);
    play.displayMap();
    
    bool finished = false;
    string input;
    do {
        play.displayCurrentRoom();
        
        //  Check to see if room is occupied by enemy, if not awards 10 supplies.
        bool enemyCheck = play.checkRoom();
        if (enemyCheck == true) {
            enemy enemy;
            play.addsupplies(enemy.fight());
        }
        
        do {
            promptPlayer();
            cin >> input;
            input = toupper(input[0]);
            cout << endl;
            
            //  Specification C3 - Input Validation
            //  Performs input validation with command options
            while (input != "N" && input != "S" && input != "E" && input != "W" && input != "L" && input != "X" && input != "M") {
                cout << "Please a valid command (N, S, E, W, L, X, or M): ";
                cin >> input;
                input = toupper(input[0]);
                cout << endl;
            }
            play.doCommand(input, & ROOM1, & ROOM2, & ROOM3, & ROOM4, & ROOM5, & ROOM6, & EXIT);
            
        } while (input != "N" && input != "S" && input != "E" && input != "W");
        cout << "----------------------------" << endl;
        if (play.getCurrentRoom().getName() == "exit") {
            finished = true;
            cout << playerName << ", you have sucessfully escaped the vault with " << play.getsupplies() << " supplies!" << endl;
        }
    } while (!finished);
}

//  Specification A2 - Add More Commands
//  Displays additional commands to the player.
void promptPlayer() {
    cout << endl << "Where would you like to go?" << endl << "---------------------------" << endl << "To Move: (N, S, E, W)" << endl << "To Look: (L)" << endl << "To View Exits: (X)" << endl << "To View Map: (M)" << endl;
}
