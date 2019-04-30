/*
    ttt.cpp
    Brandon George, CISP360
    11/11/18
*/

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <vector>
using namespace std;

const int arraySize = 10;
typedef string arr[arraySize];

void menu(int & , int & ), rules(), updateBoard(arr nums, int, string), displayBoard(arr nums), showWinner(int, string, int & , int & ), trackMoves(const vector < int > );
int first(), hpc(arr nums), npc(arr nums), checkWin(arr nums), updateScore(), displayScore();

int main() {
    // Greeting
    cout << "Tic Tac Toe: The Game" << endl;
    cout << "=====================" << endl << endl;
    
    char again = 'Y'; //
    int npcScore = 0, hpcScore = 0;
    
    //  Specification A1 - Main Game Loop
    do {
        string priorPlay = "";
        int winner = -1;
        vector < int > npcs;
        vector < int > hpcs;
        arr board = {"0", "1", "2", "3", "4", "5", "6", "7", "8"};
        menu(npcScore, hpcScore);
        displayBoard(board);
        
        //  Specification C1 - Random Start
        int player = first();
        
        if (player == 1) {
            npcs.push_back(npc(board));
            priorPlay = "computer";
            winner = checkWin(board);
        } else if (player == 2) {
            hpcs.push_back(hpc(board));
            priorPlay = "human";
            winner = checkWin(board);
        }
        while (winner == -1) {
            if (priorPlay == "human") {
                npcs.push_back(npc(board));
                priorPlay = "computer";
                winner = checkWin(board);
            }
            else if (priorPlay == "computer") {
                hpcs.push_back(hpc(board));
                priorPlay = "human";
                winner = checkWin(board);
            }
        }
        
        //  Specification A4 - Play by Play
        showWinner(winner, priorPlay, npcScore, hpcScore);
        cout << endl << "Computer Moves: ";
        trackMoves(npcs);
        cout << endl;
        cout << "Your Moves: ";
        trackMoves(hpcs);
        cout << endl << endl;
        
        //  Specification A2 - Single Prompt
        cout << "Would you like to play again? (Y/N): ";
        cin >> again;
        again = toupper(again);
        cout << endl;
        while (again != 'Y' && again != 'N') {
            cout << "Enter Y to continue or N to end game (Y/N): ";
            cin >> again;
            again = toupper(again);
            cout << endl;
        }
    }
    while (again == 'Y');
    return 0;
}

//  Specification B1 - Start Menu
void menu(int & cScore, int & hScore) {
    cout << "START MENU:" << endl;
    cout << "-----------" << endl;
    cout << "1) Rules" << endl;
    cout << "2) Play" << endl;
    cout << "3) Quit" << endl << endl;
    cout << "What would you like to do? (1, 2, or 3): ";
    int userInput = 0;
    cin >> userInput;
    cout << endl;
    
    //  Specification B2 - Valid Menu Choices
    while (userInput != 1 && userInput != 2 && userInput != 3) {
        cout << "Error: Please enter 1, 2, or 3: ";
        cin >> userInput;
        cout << endl;
    }
    if (userInput == 1) {
        rules();
        menu(cScore, hScore);
    } else if (userInput == 2) {
        cout << "The game will start now." << endl << endl;
    } else if (userInput == 3) {
        cout << "You have quit the game." << endl << "YOUR SCORE: " << hScore << endl << "COMPUTER SCORE: " << cScore << endl;
        exit(0);
    }
}
//  Rules for Tic Tac Toe
void rules() {
    cout << "The goal to win: get three X's in a row, column, or diagonally." << endl << endl;
}

//  Specification C1 - Random Start
int first() {
    int randomNum = rand() % (2 - 1 + 1) + 1;
    if (randomNum == 1) {
        cout << "Computer goes first." << endl;
    } else if (randomNum == 2) {
        cout << "You go first." << endl << endl;
    }
    return randomNum;
}

//  Specifcation C2 - Simple Display
//  Specification B3 - Pretty Display
void displayBoard(arr nums) {
    cout << "  " << nums[0] << " | " << nums[1] << " | " << nums[2] << endl << " ___|___|___" << endl << "  " << nums[3] << " | " << nums[4] << " | " << nums[5] << endl << " ___|___|___" << endl << "  " << nums[6] << " | " << nums[7] << " | " << nums[8] << endl << "    |   |   " << endl << endl;
}
void updateBoard(arr nums, int space, string letter) {
    nums[space] = letter;
}
//  Asking for move
int hpc(arr nums) {
    cout << "What's your move? ";
    int choice = 0;
    cin >> choice;
    cout << endl;
    
    //  Specification B4 - Valid Move
    while (nums[choice].compare("X") == 0 || nums[choice].compare("O") == 0) {
        cout << "That space is already taken. Where would you like to move? ";
        cin >> choice;
        cout << endl;
    }
    updateBoard(nums, choice, "X");
    displayBoard(nums);
    return choice;
}

//  Specification C3 - AI
int npc(arr nums) {
    int randomNum = rand() % (9 - 1 + 1) + 1;
    while (nums[randomNum].compare("X") == 0 || nums[randomNum].compare("O") == 0) {
        randomNum = rand() % (9 - 1 + 1) + 1;
    }
    cout << "Computer moved to space " << randomNum << endl << endl;
    updateBoard(nums, randomNum, "O");
    displayBoard(nums);
    return randomNum;
}

//  Specification C4 - Decide Winner
int checkWin(arr nums) {
    if (nums[0] == nums[1] && nums[1] == nums[2])
        return 1;
    else if (nums[3] == nums[4] && nums[4] == nums[7])
        return 1;
    else if (nums[6] == nums[7] && nums[7] == nums[8])
        return 1;
    else if (nums[0] == nums[3] && nums[3] == nums[6])
        return 1;
    else if (nums[1] == nums[4] && nums[4] == nums[7])
        return 1;
    else if (nums[2] == nums[4] && nums[4] == nums[8])
        return 1;
    else if (nums[0] == nums[4] && nums[4] == nums[8])
        return 1;
    else if (nums[2] == nums[4] && nums[4] == nums[6])
        return 1;
    else if (nums[0].compare("0") != 0 && nums[1].compare("1") != 0 && nums[2].compare("2") != 0 && nums[3].compare("3") != 0 && nums[4].compare("4") != 0 && nums[5].compare("5") != 0 && nums[6].compare("6") != 0 && nums[7].compare("7") != 0 && nums[8].compare("8") != 0)
        return 0;
    else
        return -1;
}

void trackMoves(const vector < int > plays) {
    for (int i = 0; i < plays.size(); i++) {
        cout << plays[i] << " ";
    }
}

//  Specification A3 - Keep Score
void showWinner(int result, string played, int & cScore, int & hScore) {
    if (result == 0) {
        cout << "It's a draw." << endl << "YOUR SCORE: " << hScore << endl << "COMPUTER SCORE: " << cScore << endl;
    } else if (played.compare("computer") == 0) {
        cout << "Computer wins." << endl << endl;
        cScore++;
        cout << "YOUR SCORE: " << hScore << endl << "COMPUTER SCORE: " << cScore << endl;
    } else if (played.compare("human") == 0) {
        cout << "You win!" << endl << endl;
        hScore++;
        cout << "YOUR SCORE: " << hScore << endl << "COMPUTER SCORE: " << cScore << endl;
    }
}
