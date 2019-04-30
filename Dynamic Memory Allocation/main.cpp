//
//  main.cpp
//  Dynamic Memory Allocation
//
//  Created by Brandon on 12/18/18.
//  Copyright © 2018 Brandon George. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    char* gchar = nullptr;
    int size = 3;
    gchar = new char[size];
    gchar[0] = 'A'; gchar[1] = 'B'; gchar[2] = 'C';
    
    for (int i = 0; i < size; i++)
    cout << gchar[i] << " ";
    cout << endl;
    
    char* gTemp = nullptr;
    size = size + 3;
    gTemp = new char[size];
    gTemp[0] = gchar[0];
    gTemp[1] = gchar[1];
    gTemp[2] = gchar[2];
    gTemp[3] = 'D';
    gTemp[4] = 'E';
    gTemp[5] = 'F';
    
    delete[] gchar;
    gchar = gTemp;
    gTemp = nullptr;
    
    for (int i = 0; i < size; i++)
    cout << gchar[i] << " ";
    cout << endl;
    
    size = size - 2;
    gTemp = new char[size];
    gTemp[0] = gchar[0];
    gTemp[1] = gchar[1];
    gTemp[2] = gchar[2];
    gTemp[3] = gchar[3];
    
    delete[] gchar;
    gchar = gTemp;
    gTemp = nullptr;
    
    for (int i = 0; i < size; i++)
    cout << gchar[i] << " ";
    cout << endl;
    
    return 0;
    
}
