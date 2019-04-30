/*
    drake.cpp
    Brandon George, CISP 360
    9/8/18.
    Copyright © 2018 Brandon George. All rights reserved.
*/

#include <iostream>
using namespace std;

int main( ) {
    
    //Variables of the Drake equation
    int rateOfStars = 7;
    double percentOfStarsWithPlanets = 0.4,
           numberOfPotentialPlanets = 0.9,
           percentOfPlanetsWithLife = 0.13,
           percentOfIntLife = 0.5,
           percentOfIntLifeThatCanComm = 0.8;
    int expLifetimeOfCiv = 10000;
    
    //Drake equation calculation
    double DrakeResults = rateOfStars * percentOfStarsWithPlanets * numberOfPotentialPlanets * percentOfPlanetsWithLife * percentOfIntLife * percentOfIntLifeThatCanComm * expLifetimeOfCiv;
    
    //Program Greating
    cout << "This program calculates the number of potential civilizations using the Drake equation." << endl;
    
    //Displaying information to user
    cout << "Variables: " << endl;
    cout << "Rate of star creation: " << rateOfStars << endl;
    cout << "Percentage of stars with planets: " << percentOfStarsWithPlanets << endl;
    cout << "Average number of planets that can support life: " << numberOfPotentialPlanets << endl;
    cout << "Percentage of planets that go on to develop life: " << percentOfPlanetsWithLife << endl;
    cout << "Percentage of planets that go on to develop intelligent life: " << percentOfIntLife << endl;
    cout << "Percentage of intelligent life willing and able to communicate: " << percentOfIntLifeThatCanComm << endl;
    cout << "Expected lifetime of civilizations: " << expLifetimeOfCiv << endl;
    
    //Displaying information to user and showing the Drake equation calculation result
    cout << "Estimated number of detectable civilizations in the universe: " << DrakeResults << endl;
    return 0;
}
