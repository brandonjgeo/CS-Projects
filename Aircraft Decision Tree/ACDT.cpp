//  ACDT.cpp
//  Brandon George, CISP360
//  09/30/18

#include <cmath>
#include <iostream>
using namespace std;

int main ( ) {
    
    //  Variables for deicing and travel time
    double icing, mi, spd, min, hr;
    
    //  Variables for menu selection, user input, and to restart program
    char airProb, input, restart = 'Y';
    
    //  Greeting
    cout << "Program will troubleshoot common Aircraft problems." << endl;
    cout << "===================================================" << endl << endl;
    
    //  Specification A4 - Program loop to restart program at end of a sequence.
    while (restart == 'Y' || restart == 'y') {
    
    //  Specification C1 to C4
    cout << "MAIN MENU: " << endl;
    cout << "----------" << endl;
    
    //  Specification B1 - Main menu with characters only
    cout << "Communications Failure = C " << endl;
    cout << "Engine Failure = E " << endl;
    cout << "In-flight Icing = I " << endl;
        
    // Specification A3 - Time till arrival
    cout << "Travel Time = T" << endl;
    cout << "Quit = Q " << endl;
    
    //  Menu selection by user
    cout << "What would you like help with?" << endl;
    cin >> airProb;
    cout << endl;
    
    switch (airProb) {
        
        //  Specification A2 - Upper or Lower case
        case 'c':
        case 'C':
            //  Specification C1 - Coresponding Menu Option
            cout << "Communications Failure: " << endl;
            cout << "-----------------------" << endl;
            cout << "Switch to Alternate Radio." << endl << endl;
            break;
        
        //  Specification A2 - Upper or Lower case
        case 'e':
        case 'E':
            
        //  Specification C2 - Coresponding Menu Option
        cout << "Engine Failure: " << endl;
        cout << "---------------" << endl;
        cout << "Are you airborne? (Y/N)" << endl;
        cin >> input;

            if (input == 'Y' || input == 'y') {
                cout << "Is the electrical system working? (Y/N)" << endl;
                cin >> input;
            if (input == 'Y' || input == 'y') {
                cout << "Has the engine stopped running? (Y/N)" << endl;
                cin >> input;
            if (input == 'Y' || input == 'y') {
                cout << "Are you over the mountains? (Y/N)" << endl;
                cin >> input;
            if (input == 'Y' || input == 'y') {
                cout << "Are you flying at night? (Y/N)" << endl;
                cin >> input;
            if (input == 'Y' || input == 'y') {
                cout << "Turn on the landing light and look out the window." << endl;
                cout << "Do you like what you see? (Y/N)" << endl;
                cin >> input;
            if (input == 'Y' || input == 'y') {
                cout << "Make emergency landing." << endl << endl;
                } else {
                    cout << "Turn off the landing light." << endl << endl;
                }
                } else {
                    cout << "Make emergency landing." << endl << endl;
                }
                } else {
                    cout << "Are you over water?" << endl;
                    cin >> input;
            if (input == 'Y' || input == 'y') {
                cout << "Inflate your life vest, make emergency landing." << endl << endl;
                } else {
                    cout << "Make emergency landing on a road." << endl << endl;
                }
                }
                } else {
                    cout << "Is the outside air temperature < 32 degrees?" << endl;
                    cin >> input;
            if (input == 'Y' || input == 'y') {
                    cout << "Turn on Carburator Heat." << endl << endl;
                } else {
                    cout << "Switch to other fuel tank." << endl << endl;
                }
                }
                } else {
                    cout << "Turn on the Master Switch." << endl << endl;
                }
                } else {
                    cout << "Have a drink and call a mechanic." << endl << endl;
                }
        break;
            
        //  Specification A2 - Upper or Lower case
        case 'i':
        case 'I':
            
        //  Specification C3 - Coresponding Menu Option
        cout << "In-flight Icing:" << endl;
        cout << "----------------" << endl;
        cout << "What is the estimated amount of ice on the wings? (0 mm to 10 mm)" << endl;
        cin >> icing;
            
        //  Specification A1 - Deicing range check
        if (icing > 10) {
            cout << "Aircrafts will not fly with more than 10 mm of ice. Please restart the program to try again." << endl << endl;
            } else if (icing <= 0) {
                cout << "Please input values between 0 mm to 10 mm. Please restart the program to try again." << endl << endl;
            } else {
                if (icing < 1) {
                    cout << "Energize the decing boots on the wings to: 5%" << endl << endl;
                } else if (icing <= 5) {
                    cout << "Energize the decing boots on the wings to: 20%" << endl << endl;
                } else if (icing <= 9) {
                    cout << "Energize the decing boots on the wings to: 65%" << endl << endl;
                } else if (icing <= 10) {
                    cout << "Energize the decing boots on the wings to: 100%" << endl << endl;
                }
            }
        break;
            
        //  Specification A2 - Upper and Lower case
        case 't':
        case 'T':
            
            //  Specification C3 - Coresponding Menu Option
            //  Specification A3 - Time till arrival
        cout << "Travel Time:" << endl;
        cout << "------------" << endl;
        cout << "How many miles remain to your destination?" << endl;
        cin >> mi;
            while (mi < 0) {
                    cout << "How many miles remain to your destination?" << endl;
                    cout << "(Enter only positive numbers)" << endl;
                    cin >> mi;
                }
        cout << "Current speed in mph?" << endl;
        cin >> spd;
            while (spd < 0) {
                cout << "Current speed in mph?" << endl;
                cout << "(Enter only positive numbers)" << endl;
                cin >> spd;
            }
            
        hr = mi / spd;
        min = hr * 60;
        cout << "You'll arrive at your destination in: " << hr << " hours or " << min << " minutes." << endl << endl;
        break;

        //  Specification A2 - Upper or Lower case
        case 'q':
        case 'Q':
        
        //  Specification C4 - Coresponding Menu Option
        cout << "You've exited the program." << endl << endl;
        break;
            
        //  Specification B2 - Main Menu Data Entry Check
        default:
            cout << "Error: " << endl;
            cout << "Please restart the program." << endl << endl;
    }
        //  Specification A4 - Program loop to restart program at end of a sequence.
        cout << "Would you like to restart the program? (Y/N)" << endl;
        cin >> restart;
        cout << endl;
        while (!(restart == 'Y' || restart == 'y' || restart == 'N' || restart == 'n')) {
            cout << "An error occurred. Enter a valid input. Would you like to restart the program? (Y/N)" << endl;
            cin >> restart;
            cout << endl;
        }
    }
return 0;
}
