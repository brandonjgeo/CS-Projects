//  CCCTC.cpp
//  Brandon George, CISP360
//  10/14/18

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cctype>

using namespace std;

int main() {
    
    //  Declared variables
    string object;
    
    //  Specification B1 - Floats for Temps
    //  Input for Fahrenheit
    double fahTemp;
    
    //  For conversion to Celsius
    bool celTemp = false,
    
    //  For conversion to Rankine
         ranTemp = false,
    
    // For conversion to Newton
         newtTemp = false,
    
    //  For conversion to Rømer
         romTemp = false;
    
    //  Variable for temp scale conversions
    char scale;
    
    //  Specification B3 - Fancy output (restriction to 3 significant digits)
    cout << fixed << showpoint << setprecision(3);
    
    //  Program Greeting
    cout << "Cat, Cot, Cap, Dog Temperature Calculator" << endl;
    cout << "=========================================" << endl;
    cout << "Program will calculate the temperatures of cats, cots, caps, and dogs." << endl << endl;
    
    //  Object Selection
    //  Specification A2 - Another Thing (Dog)
    cout << "Object Selection" << endl;
    cout << "----------------" << endl;
    cout << "Which object would you like to calulcate the temperature? (Cat, Cot, Cap, or Dog)" << endl;
    cin >> object;
    cout << endl;
    for (int i = 0; i < object.length(); i++) {
        object[i] = tolower(object[i]);
    }
    //  Specification C1 - Valid words only
    //  Specification A1 - Sophisticated Word Check
    while (!(object == "cat" || object == "cot" || object == "cap" || object == "dog")) {
        cout << "Choose a valid input (cat, cot, cap, or dog): " << endl;
        cin >> object;
        cout << endl;
        for (int i = 0; i < object.length(); i++) {
            object[i] = tolower(object[i]);
    }
    }
        //  Object temperature ranges
        cout << "Object Temperature" << endl;
        cout << "------------------" << endl;
        cout << "What is the temperature of the object in Fahrenheit? (degrees only)"<< endl;
        if (object == "cat") {
            cout << "Range for cat is 86 to 102 degrees Fahrenheit." << endl << endl;
        } else if (object == "cot") {
            cout << "Range for cot is 54 to 90 degrees Fahrenheit." << endl << endl;
        } else if (object == "cap") {
            cout << "Range for cap is 72 to 88 degrees Fahrenheit." << endl << endl;
        } else if (object == "dog") {
            cout << "Range for dog is 99 to 102 degrees Fahrenheit." << endl << endl;
        }
        cout << "Enter Temperature: " << endl;
        cin >> fahTemp;
        cout << endl;
    
        //  Specification B2 - Valid Temps Only
        if (object == "cat") {
            while (fahTemp < 86 - 0.20  || fahTemp > 102 + 0.20 ) {
                if (fahTemp < 86 - 0.20 ) {
                    cout << "Too low. ";
                } else {
                    cout << "Too high. ";
                }
                cout << "Enter a temperature between 86 to 102 degrees: " << endl;
                cin >> fahTemp;
                cout << endl;
                }
        } else if (object == "cot") {
            while (fahTemp < 54 - 0.20 || fahTemp > 80 + 0.20 ) {
                if (fahTemp < 54 - 0.20 ) {
                    cout << "Too low. ";
                } else {
                    cout << "Too high. ";
                }
                    cout << "Enter a temperature between 54 to 80 degrees: " << endl;
                    cin >> fahTemp;
                    cout << endl;
                }
        } else if (object == "cap") {
            while (fahTemp < 72 - 0.20  || fahTemp > 88 + 0.20 ) {
                if (fahTemp < 72 - 0.20 ) {
                    cout << "Too low. ";
                } else {
                    cout << "Too high. ";
                }
                    cout << "Enter a temperature between 72 to 88 degrees: " << endl;
                    cin >> fahTemp;
                    cout << endl;
                }
        } else if (object == "dog") {
            while (fahTemp < 99 - 0.20  || fahTemp > 102 + 0.20 ) {
                if (fahTemp < 99 - 0.20 ) {
                    cout << "Too low. ";
            } else {
                    cout << "Too high. ";
                }
                    cout << "Enter a temperature between 99 to 102 degrees: " << endl;
                    cin >> fahTemp;
                    cout << endl;
            }
        }
        //  Specification C2 - Temp Scale Menu
        //  Specification A3 - Another Temperature Scale (Newton)
        //  Specification A4 - Another Temperature Scale (Rømer)
        cout << "Temperature Scale" << endl;
        cout << "-----------------" << endl;
        cout << "Celsius = C " << endl;
        cout << "Newton = N" << endl;
        cout << "Rømer = O" << endl;
        cout << "Rankine = R " << endl;
        cout << "All of the above = A" << endl << endl;
        cout << "Which temperature would you like to convert to? (C,N,O,R,A)" << endl;
        cin >> scale;
        cout << endl;
        
        //  Specification C3 Valud Scale Menu Check
        while (!(scale == 'c' || scale == 'C' || scale == 'n' || scale == 'N' || scale == 'o' || scale == 'O' || scale == 'r' || scale == 'R' || scale == 'a' || scale == 'A')) {
            cout << "Please choose a valid input (C,N,O,R,A): ";
            cin >> scale;
            cout << endl;
        }
        switch (scale) {
            case 'c':
            case 'C':
                celTemp = true;
                break;
            case 'n':
            case 'N':
                newtTemp = true;
                break;
            case 'o':
            case'O':
                romTemp = true;
                break;
            case 'r':
            case 'R':
                ranTemp = true;
                break;
            case 'a':
            case 'A':
                celTemp = newtTemp = romTemp = ranTemp = true;
                break;
        }
    
        //  List of all conversions with adjusted spaccing
        cout << left << setw(12) << "Scale" << right << setw(12) << "Temperature" << endl;
        cout << left << setw(12) << "-----" << right << setw(12) << "-----------" << endl;
        cout << left << setw(12) << "Fahrenheit" << right << setw(12) << fahTemp << endl;
        if (celTemp) {
            cout << left << setw(12) << "Celsius" << right << setw(12) << ((fahTemp) - 32) * (5.0 / 9.0) << endl;
        }
        if (newtTemp) {
            cout << left << setw(12) << "Newton" << right << setw(12) << ((fahTemp) - 32) * (0.18333) << endl;
        }
        if (romTemp) {
        cout << left << setw(12) << "Rømer" << right << setw(12) << ((fahTemp) - 32) * 7/24+7.5 << endl;
        }
        if (ranTemp) {
            cout << left << setw(12) << "Rankine" << right << setw(12) << (fahTemp + 459.67) << endl;
    }
    //  End of Program
    return 0;
 }
