/*
    madlibs.cpp
    Brandon George, CISP360
    11/25/18
*/

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

string askText(string), randWord(), wordMenu(), shortestVerb();
float randFloat();
bool spaceChecker(string input), nounSizeChecker(string input), verbSizeChecker(string input), vowelChecker(string input);
void printMessage(string const *TIMESPAN, string const *NOUN1, string const *VERB1, string const *VERB2, string const *NOUN2, string const *NOUN3, string const *VERB3,string const *WORD_OCCUPATION, string const *NOUN4, string const *NOUN5, string const *FAMOUS_PERSON, string const *ADJECTIVE1, string const *VERB4, string const *NOUN6, string const *NOUN7, string const *ADJECTIVE2, string const *NOUN8, string const *VERB5, string const *PREPOSITION, string const *INTEGER, string const *VERB6, float const *FLOAT, string const *LETTER), startMenu();

int main() {

    cout << "Welcome to MadLibs" << endl;
    cout << "=-==-=-=--=-=-==-=" << endl << endl;
    char again = 'Y';
    
    startMenu();
    do{
        cin.ignore();
        const string TIMESPAN = askText("Enter a time span: ");
        string NOUN1 = askText("Enter a noun (singular, max of 15 characters): ");
        while (nounSizeChecker(NOUN1) == 0){
            NOUN1 = askText("Please try again. Enter a noun (singular, max of 15 characters ): ");
        }
        const string VERB1 = askText("Enter a verb (present tense): ");
        const string VERB2 = randWord();
        const string NOUN2 = askText("Enter a noun (plural): ");
        const string NOUN3 = askText("Enter a noun (plural or singular): ");
        const string VERB3 = shortestVerb();
        string OCCUPATION = askText("Enter a 2 word occupation: ");
        while(spaceChecker(OCCUPATION) == 0){
            OCCUPATION = askText("Please try again. Enter a 2 word occupation: ");
        }
        const string NOUN4 = askText("Enter a noun (singular): ");
        const string NOUN5 = wordMenu();
        cin.ignore();
        string FAMOUS_PERSON = askText("Enter a famous person's name (2 words): ");
        while(spaceChecker(FAMOUS_PERSON) == 0){
            FAMOUS_PERSON = askText("Please try again. Enter a famous person's name (2 words): ");
        }
        const string ADJECTIVE1 = askText("Enter an adjective: ");
        const string VERB4 = askText("Enter a verb (present tense): ");
        const string NOUN6 = askText("Enter a noun (singular or plural): ");
        const string NOUN7 = askText("Enter a noun (plural): ");
        const string ADJECTIVE2 = askText("Enter an adjective: ");
        string NOUN8 = askText("Enter a noun (plural, starts with vowel): ");
        while(vowelChecker(NOUN8)==0){
            NOUN8 = askText("Please try again. Enter a noun (plural, starts with vowel): ");
        }
        string VERB5 = askText("Enter a verb (present tense, between 4 and 20 characters): ");
        while(verbSizeChecker(VERB5) == 0){
            VERB5 = askText("Please try again. Enter a verb (present tense, between 4 and 20 characters): ");
        }
        const string PREPOSITION = askText("Enter a preposition: ");
        const string INTEGER = askText("Enter an integer: ");
        const string VERB6 = askText("Enter a verb (present tense): ");
        const float FLOAT = randFloat();
        const string LETTER = askText("Enter a letter: ");
        
        printMessage(&TIMESPAN, &NOUN1, &VERB1, &VERB2, &NOUN2, &NOUN3, &VERB3,&OCCUPATION, &NOUN4, &NOUN5, &FAMOUS_PERSON, &ADJECTIVE1, &VERB4, &NOUN6, &NOUN7, &ADJECTIVE2, &NOUN8, &VERB5, &PREPOSITION, &INTEGER, &VERB6, &FLOAT, &LETTER);
        
        cout << "Would you like to play again? Enter Y to restart and N to end game: ";
        cin >> again;
        again = toupper(again);
        cout << endl;
        
        //  Specification A1 - Main Game Loop
        while (again != 'Y' && again != 'N') {
            cout << "Please enter Y to restart and N to end game: ";
            cin >> again;
            again = toupper(again);
            cout << endl;
        }
    }
    while(again == 'Y');
    return 0;
}

void printMessage(string const *TIMESPAN, string const *NOUN1, string const *VERB1, string const *VERB2, string const *NOUN2, string const *NOUN3, string const *VERB3,string const *WORD_OCCUPATION, string const *NOUN4, string const *NOUN5, string const *FAMOUS_PERSON, string const *ADJECTIVE1, string const *VERB4, string const *NOUN6, string const *NOUN7, string const *ADJECTIVE2, string const *NOUN8, string const *VERB5, string const *PREPOSITION, string const *INTEGER, string const *VERB6, float const *FLOAT, string const *LETTER){
    cout << "A Day In The Life Of a College Student" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Every " << *TIMESPAN << " A.M., I wake up and get off my " << *NOUN1 << ". I don\'t always have time to " << *VERB1 << " a shower, but I always make sure to " << *VERB2 << " my hair. Once that\'s done I get some " << *NOUN2 << ", and then it\'s off to my first " << *NOUN3 <<". I often get caught " << *VERB3 << " in class. No one likes it when the " << *WORD_OCCUPATION << " gives a surprise " << *NOUN4 << ". My second class is " << *NOUN5 << " Theory. Dr. " << *FAMOUS_PERSON << " is incredibly " << *ADJECTIVE1 << ", but I never " << *VERB4 << " her because of her thick " << *NOUN6 << ". Her " << *NOUN7 << ", however, are really " << *ADJECTIVE2 << ". After lunch, I have no more " << *NOUN8 << " and I\'m free to " << *VERB5 << " " << *PREPOSITION << " my friends. This is right around " << *INTEGER << " o\'clock. Before I go to bed I " << *VERB6 << " a little bit, in my room, " << *FLOAT << *LETTER << "." << endl << endl;
}

string askText(string prompt)
{
    string text;
    cout << prompt;
    getline (cin, text);
    return text;
}

    //  Specification C1 - Random Word
    string randWord(){
    int randNum = rand() % (3 - 1 + 1) + 1;
    string randoWord = "";
    if (randNum == 1) {
        randoWord = "comb";
    } else if (randNum == 2) {
        randoWord = "paint";
    } else if (randNum == 3){
        randoWord = "remove";
    }
    return randoWord;
}
    //  Specification C2 - Random Float
    float randFloat(){
    float randNum = (15 - 1) * ((((float) rand()) / (float) RAND_MAX)) + 1;
    return randNum;
}

    //  Specification C3 - Word Menu
    string wordMenu(){
    char input;
        cout << "WORD MENU" << endl;
        cout << "1. breakfast" << endl;
        cout << "2. fishes" << endl;
        cout << "3. copper coins" << endl;
        cout << "Which noun would you like to choose: ";
        cin >> input;
    while (input != '1' && input != '2' && input != '3') {
        cout << "Please enter a valid input (enter 1, 2, or 3): ";
        cin >> input;
        cout << endl;
    }
    switch (input) {
        case '1':
            return "breakfast";
        case '2':
            return "fishes";
        case '3':
            return "copper coins";
    }
    return "Error. Wrong Input.";
}

//  Specification B1 - Phrase Validation
bool spaceChecker(string str){
    return std::find_if(str.begin(), str.end(), ::isspace) != str.end();
}

//  Specification B2 - Maximum Word Size Validation
bool nounSizeChecker(string str){
    if (str.size()>15){
        return false;
    }
    return true;
}

//  Specification B3 - Range Validation
bool verbSizeChecker(string str){
    if (str.size()<4 || str.size()>20){
        return false;
    }
    return true;
}

//  Specification B4 - Simple Menu
void startMenu() {
    cout << "START MENU:" << endl;
    cout << "-----------" << endl;
    cout << "1. Explain MadLibs" << endl;
    cout << "2. Start MadLibs" << endl;
    cout << "3. Quit" << endl << endl;
    cout << "What would you like to do? (Enter 1, 2, or 3): ";
    int input = 0;
    cin >> input;
    cout << endl;
    
    while (input != 1 && input != 2 && input != 3) {
        cout << "Enter 1, 2, or 3: ";
        cin >> input;
        cout << endl;
    }
    if (input == 1) {
        cout << "MadLibs is a hilarious program designed to input nouns, verbs, etc. into an unseen story that is displayed at the end." << endl << endl;
        startMenu();
    } else if (input == 2) {
        cout << "MadLibs has started now." << endl << endl;
    } else if (input == 3) {
        cout << "You have quit MadLibs." << endl;
        exit(0);
    }
}
    /*
        Specification A2 - C Style String
        Do not use a C++ style strubg for NOUN8, use a C style string instead.
    */

    //  Specification A2 - Starts with vowel
    bool vowelChecker(string str){
    if(str[0]!='a' && str[0]!='e' && str[0]!='i' && str[0]!='o' && str[0]!='u'){
        return 0;
    }
    return 1;
}
    //  Specification A3 - Shortest verb
    string shortestVerb(){
    string verb1 = askText("Enter a verb ending in ING: ");
    string verb2 = askText("Enter another verb ending in ING: ");
    cout << "The shortest verb will be used." << endl;
    if (verb1.size() <= verb2.size()){
        return verb1;
    }
    return verb2;
}
