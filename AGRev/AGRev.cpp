//  AGRev.cpp
//  Brandon George, CISP 360
//  9/16/18
//  Copyright © 2018 Brandon George. All rights reserved.

#include <iostream>
using namespace std;

int main( ) {
    
    //July Average Temperatures
    int newYorkJul = 85,
        denverJul = 88,
        phoenixJul = 106,
        sacramentoJul = 92,
    
    // Specification A1 – Another city
        seatleJul = 74,
    
    // Specification A2 – Mean January Temps
        newYorkJan = 39,
        denverJan = 45,
        phoenixJan = 68,
        sacramentoJan = 56,
    
    // Specification A1 – Another city
        seatleJan = 47;
   
    // Specification B1 - Mixed outputs
    double temp15 = 2.0,
        temp30 = 4.0,
        temp50 = 6.67,
        oceanInput,
        airTemp,
        inchToCent = 2.54,
        inchToMilli = 25.4;
    
    // Specification B1 - Mixed output
    double oceanInch = 0.122047,
        oceanCent = 0.31,
        oceanMilli = 3.1,
        ocean100Inch = 0.070866,
        ocean100Cent = 0.18,
        ocean100Milli = 1.8;
    
    // Specification B4 - Client Name
    string name;
    
    // Program pause identifier
    char enterKey;

    //Displaying program name and purpose
    cout << "Al Gore's Revenge" << endl;
    cout << "Exploration of the changing weather." << endl << endl;
    cout << "WEATHER CALCULATIONS" << endl;
    cout << "=====================" << endl << endl;
    cout << "Calculating changes in sea levels." << endl;
    cout << "----------------------------------" << endl;
    
    // Specification C1 - Rising Seas
    cout << "The worlds oceans rose over the last 100 years by " << ocean100Inch << " Inches or " << ocean100Cent << " centimeters or " << ocean100Milli << " millimeter." << endl << endl;
    
    // Specification C2 - 15 year rise
    cout << "In 15 years, the oceans will have risen by " << oceanInch * 15 << " Inches or " << oceanCent * 15 << " centimeters or " << oceanMilli * 15 << " millimeter." << endl << endl;
    
    // Specification C3 - 30 year rise
    cout << "In 30 years, the oceans will have risen by " << oceanInch * 30 << " Inches or " << oceanCent * 30 << " centimeters or " << oceanMilli * 30 << " millimeter." << endl << endl;
    
    // Specification A3 - Calculate the sea level rise in 50 years.
    cout << "In 50 years, the oceans will have risen by " << oceanInch * 50 << " Inches or " << oceanCent * 50 << " centimeters or " << oceanMilli * 50 << " millimeter." << endl << endl << endl;
    
    // Specification D3 - Prompt the client and accept keyboard input for Mean Annual Sea Level Increase
    cout << "Calculating sea level changes with your own values." << endl;
    cout << "---------------------------------------------------" << endl;
    
    // Specification B4 - Client Name
    cout << "What's your name: " << endl;
    getline(cin, name);
    cout << endl;
    
    // Specification B4 - Client Name Output
    cout << name << ", please input a value in inches to change sea level projections: " << endl;
    cin >> oceanInput;
    cout << endl;
    
    // Specification D3 - Prompt the client and accept keyboard input for Mean Annual Sea Level Increase
    cout << "In 15 years, the oceans will have risen by " << oceanInput * 15 << " Inches or " << oceanInput * 15 * inchToCent << " centimeters or " << oceanInput * 15 * inchToMilli << " millimeter." << endl << endl;
    cout << "In 30 years, the oceans will have risen by " << oceanInput * 30 << " Inches or " << oceanInput * 30 * inchToCent << " centimeters or " << oceanInput * 30 * inchToMilli << " millimeter." << endl << endl;
    cout << "In 50 years, the oceans will have risen by " << oceanInput * 50 << " Inches or " << oceanInput * 50 * inchToCent << " centimeters or " << oceanInput * 50 * inchToMilli << " millimeter." << endl << endl << endl;
    
    // Program pause to allow user to read results before moving on.
    cout << "The program has paused. Press Enter to continue onto Mean January & July Air Temperatures." << endl;
    cin.get(enterKey);
    enterKey = cin.get();
    
    // Specification A2 – Mean January Temps
    cout << "Calculating changes in January air temperatures." << endl;
    cout << "------------------------------------------------" << endl;
    
    // Specification B1 - Mixed output
    cout << "Average January Temperatures today: " << endl;
    cout << "New York City, NY: " << newYorkJan << "°F or " << (newYorkJan - 32) * 5/9 << "°C" << endl;
    cout << "Denver, CO: " << denverJan << "°F or " << (denverJan - 32) * 5/9 << "°C" << endl;
    cout << "Phoenix, AZ: " << phoenixJan << "°F or " << (phoenixJan - 32) * 5/9 << "°C" << endl;
    cout << "Sacramento, CA: " << sacramentoJan << "°F or " << (sacramentoJan - 32) * 5/9 << "°C" << endl;
    cout << "Seatle, WA: " << seatleJan << "°F or " << (seatleJan - 32) * 5/9 << "°C" << endl << endl;
    
    // Specification C4 - 15 year temp
    cout << "Average January Temperatures in 15 years: " << endl;
    cout << "New York City, NY: " << newYorkJan + temp15 << "°F or " << (newYorkJan + temp15 - 32) * 5/9 << "°C" << endl;
    cout << "Denver, CO: " << denverJan + temp15 << "°F or " << (denverJan + temp15 - 32) * 5/9 << "°C" << endl;
    cout << "Phoenix, AZ: " << phoenixJan + temp15 << "°F or " << (phoenixJan + temp15 - 32) * 5/9 << "°C" << endl;
    cout << "Sacramento, CA: " << sacramentoJan + temp15 << "°F or " << (sacramentoJan + temp15 - 32) * 5/9 << "°C" << endl;
    cout << "Seatle, WA: " << seatleJan + temp15 << "°F or " << (seatleJan + temp15 - 32) * 5/9 << "°C" << endl << endl;
    
    // Specification C5 - 30 year temp
    cout << "Average January Temperatures in 30 years: " << endl;
    cout << "New York City, NY: " << newYorkJan + temp30 << "°F or " << (newYorkJan + temp30 - 32) * 5/9 << "°C" << endl;
    cout << "Denver, CO: " << denverJan + temp30 << "°F or " << (denverJan + temp30 - 32) * 5/9 << "°C" << endl;
    cout << "Phoenix, AZ: " << phoenixJan + temp30 << "°F or " << (phoenixJan + temp30 - 32) * 5/9 << "°C" << endl;
    cout << "Sacramento, CA: " << sacramentoJan + temp30 << "°F or " << (sacramentoJan + temp30 - 32) * 5/9 << "°C" << endl;
    cout << "Seatle, WA: " << seatleJan + temp30 << "°F or " << (seatleJan + temp30 - 32) * 5/9 << "°C" << endl <<endl;
    
    // Specification B3 - 50 Year Temp
    cout << "Average January Temperatures in 50 years: " << endl;
    cout << "New York City, NY: " << newYorkJan + temp50 << "°F or " << (newYorkJan + temp50 - 32) * 5/9 << "°C" << endl;
    cout << "Denver, CO: " << newYorkJan + temp50 << "°F or " << (denverJan + temp50 - 32) * 5/9 << "°C" << endl;
    cout << "Phoenix, AZ: " << phoenixJan + temp50 << "°F or " << (phoenixJan + temp50 - 32) * 5/9 << "°C" << endl;
    cout << "Sacramento, CA: " << sacramentoJan + temp50 << "°F or " << (sacramentoJan + temp50 - 32) * 5/9 << "°C" << endl;
    cout << "Seatle, WA: " << seatleJan + temp50 << "°F or " << (seatleJan + temp50 - 32) * 5/9 << "°C" << endl << endl;
    
    // Calculating Mean July Temperatures.
    cout << "Calculating changes in July air temperatures." << endl;
    cout << "--------------------------------------------" << endl;
    
    // Specification B1 - Mixed outputs
    cout << "Average July Temperatures today: " << endl;
    cout << "New York City, NY: " << newYorkJul << "°F or " << (newYorkJul - 32) * 5/9 << "°C" << endl;
    cout << "Denver, CO: " << denverJul << "°F or " << (denverJul - 32) * 5/9 << "°C" << endl;
    cout << "Phoenix, AZ: " << phoenixJul << "°F or " << (phoenixJul - 32) * 5/9 << "°C" << endl;
    cout << "Sacramento, CA: " << sacramentoJul << "°F or " << (sacramentoJul - 32) * 5/9 << "°C" << endl;
    cout << "Seatle, WA: " << seatleJul << "°F or " << (seatleJul - 32) * 5/9 << "°C" << endl << endl;
    
    // Specification C4 - 15 year temp
    cout << "Average July Temperatures in 15 years: " << endl;
    cout << "New York City, NY: " << newYorkJul + temp15 << "°F or " << (newYorkJul + temp15 - 32) * 5/9 << "°C" << endl;
    cout << "Denver, CO: " << denverJul + temp15 << "°F or " << (denverJul + temp15 - 32) * 5/9 << "°C" << endl;
    cout << "Phoenix, AZ: " << phoenixJul + temp15 << "°F or " << (phoenixJul + temp15 - 32) * 5/9 << "°C" << endl;
    cout << "Sacramento, CA: " << sacramentoJul + temp15 << "°F or " << (sacramentoJul + temp15 - 32) * 5/9 << "°C" << endl;
    cout << "Seatle, WA: " << seatleJul + temp15 << "°F or " << (seatleJul + temp15 - 32) * 5/9 << "°C" << endl << endl;

    // Specification C5 - 30 year temp
    cout << "Average July Temperatures in 30 years: " << endl;
    cout << "New York City, NY: " << newYorkJul + temp30 << "°F or " << (newYorkJul + temp30 - 32) * 5/9 << "°C" << endl;
    cout << "Denver, CO: " << denverJul + temp30 << "°F or " << (denverJul + temp30 - 32) * 5/9 << "°C" << endl;
    cout << "Phoenix, AZ: " << phoenixJul + temp30 << "°F or " << (phoenixJul + temp30 - 32) * 5/9 << "°C" << endl;
    cout << "Sacramento, CA: " << sacramentoJul + temp30 << "°F or " << (sacramentoJul + temp30 - 32) * 5/9 << "°C" << endl;
    cout << "Seatle, WA: " << seatleJul + temp30 << "°F or " << (seatleJul + temp30 - 32) * 5/9 << "°C" << endl <<endl;
    
    // Specification B3 - 50 Year Temp
    cout << "Average July Temperatures in 50 years: " << endl;
    cout << "New York City, NY: " << newYorkJul + temp50 << "°F or " << (newYorkJul + temp50 - 32) * 5/9 << "°C" << endl;
    cout << "Denver, CO: " << newYorkJul + temp50 << "°F or " << (denverJul + temp50 - 32) * 5/9 << "°C" << endl;
    cout << "Phoenix, AZ: " << phoenixJul + temp50 << "°F or " << (phoenixJul + temp50 - 32) * 5/9 << "°C" << endl;
    cout << "Sacramento, CA: " << sacramentoJul + temp50 << "°F or " << (sacramentoJul + temp50 - 32) * 5/9 << "°C" << endl;
    cout << "Seatle, WA: " << seatleJul + temp50 << "°F or " << (seatleJul + temp50 - 32) * 5/9 << "°C" << endl << endl;
    
    // Specification D3 - Prompt the client and accept keyboard input for Mean Annual Air Temperature
    cout << "Calculate changes in the Mean Annual Air Temperature using your own values." << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << name << ", what is your region's Mean Annual Air Temperature in Fahrenheit: " << endl;
    cin >> airTemp;
    cout << endl;
    
    // Calculated Mean Annual Air Temperature from user input
    cout << "Your location's Mean Annual Air Temperature: " << endl;
    cout << "Right now: " << airTemp << "°F or " << airTemp - 32 * 5/9 << "°C" << endl;
    cout << "In 15 years: " << airTemp + temp15 << "°F or " << (airTemp + temp15 - 32) * 5/9 << "°C" << endl;
    cout << "In 30 years: " << airTemp + temp30 << "°F or " << (airTemp + temp30 - 32) * 5/9 << "°C" << endl;
    cout << "In 50 years: " << airTemp + temp50 << "°F or " << (airTemp + temp50 - 32) * 5/9 << "°C" << endl << endl;
    
    // Program pause to allow user to read results before moving on.
    cout << "The program has paused. Press Enter to receive advice." << endl;
    cin.get(enterKey);
    enterKey = cin.get();
    
    // Specification B2 - Advice
    cout << "Here's some advice " << name << ": work with others to reduce the impacts of climate change on our habitat. The data and projections from this program (and the ones you entered) show that our planet is going to continue to warm if we do nothing. So it up to us to reduce the effects of climate change." << endl << endl;
    
    return 0;
}
