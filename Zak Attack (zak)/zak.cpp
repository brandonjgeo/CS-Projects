/*
    zak.cpp
    Brandon George, CISP360
    12/09/18
*/

#include <iostream>
#include <string>
#include <array>
using namespace std;

class Test {
private:
    float testScore;
    int testNumber;
    string dropped;
    char grade;
    
public:
    float getTestScore();
    void enterTest(), showTestData(), setDropped(), setTestNumber(int);
};

//  Retrieving score data for students
void Test::enterTest() {
    cout << "Enter the score for test " << testNumber << " (0 to 100): ";
    cin >> testScore;
    
    // Specification C3 - Grade Input Validation
    while (testScore < 0 || testScore > 100) {
        cout << "Try again. Enter the score for test " << testNumber << " (0 to 100): ";
        cin >> testScore;
    }
    if (testScore >= 90) {
        grade = 'A';
    } else if (testScore >= 80) {
        grade = 'B';
    } else if (testScore >= 70) {
        grade = 'C';
    } else if (testScore >= 60) {
        grade = 'D';
    } else {
        grade = 'F';
    }
}
float Test::getTestScore() {
    return testScore;
}
void Test::showTestData() {
    cout << "Test " << testNumber << ": " << testScore << " (" << grade << ") " << dropped << endl;
}

//  Specification B3 - Signify Dropped
void Test::setDropped() {
    dropped = "DROPPED";
}
void Test::setTestNumber(int n) {
    testNumber = n;
}
class Student {
private:
    float gpa;
    int testCount;
    string name;
    Test * tests;
    
public:
    Student();
    string getName();
    float getGPA();
    int numberOfTests();
    void showSummary(), getTestData(), showGPA(), sortScores(), dropScores(), setFields(int), showAverage(Student[], int);
};
//  Specification C2 - Student Name
Student::Student() {
    cout << "Enter the student's name: ";
    getline(cin, name);
}
string Student::getName() {
    return name;
}
float Student::getGPA() {
    return gpa;
}
int Student::numberOfTests() {
    return testCount;
}
void Student::setFields(int numTests) {
    testCount = numTests;
    tests = new Test[numTests];
}

//  Specification C1 - Student Summary
void Student::showSummary() {
    showGPA();
    cout << endl << "------------------------" << endl;
    cout << "Summary for: " << name << endl;
    cout << "Number of Tests: " << testCount << endl << endl;
    cout << "Scores: " << endl;
    for (int i = 0; i < testCount; i++) {
        tests[i].showTestData();
    }
    cout << endl << "GPA: " << gpa << endl << endl;
    
    //  Specification C4 - GPA Advice
    if (gpa >= 90) {
        cout << "A average. You made it, keep up the great work!" << endl;
    } else if (gpa >= 80) {
        cout << "B average. You're almost to an A, keep up the pace!" << endl;
    } else if (gpa >= 70) {
        cout << "C average. Could be better, I suggest more time for study or getting a tutor." << endl;
    } else if (gpa >= 60) {
        cout << "D average. Seek a tutor if you are struggling." << endl;
    } else {
        cout << "F average. I would highly recommend a tutor." << endl;
    }
}

//  Student scores per test
void Student::getTestData() {
    cout << endl << "Scores for " << name << endl;
    for (int i = 0; i < testCount; i++) {
        tests[i] = Test();
        tests[i].setTestNumber(i + 1);
        tests[i].enterTest();
    }
}

//  Specification B4 – Sorted Output
void Student::sortScores() {
    Test temp;
    int i, j;
    for (i = 0; i < testCount - 1; i++) {
        for (j = 0; j < testCount - i - 1; j++) {
            if (tests[j].getTestScore() < tests[j + 1].getTestScore()) {
                temp = tests[j];
                tests[j] = tests[j + 1];
                tests[j + 1] = temp;
            }
        }
    }
}

//  Specification B2 - Drop Lowest
void Student::dropScores() {
    for (int i = testCount-1; i > testCount-4; i--) {
        tests[i].setDropped();
    }
    float sum = 0;
    for (int i = 0; i < testCount-3; i++) {
        sum += tests[i].getTestScore();
    }
    float possible = 100 * (testCount - 3);
    gpa = sum / possible * 100;
}

//  GPA calculator
void Student::showGPA() {
    sortScores();
    if (testCount >= 4) {
        dropScores();
    } else {
        float sum = 0;
        for (int i = 0; i < testCount; i++) {
            sum += tests[i].getTestScore();
        }
        float possible = 100 * testCount;
        gpa = sum / possible * 100;
    }
}

//  Specification A3 - Class Stats
void Student::showAverage(Student arr[], int studentCount) {
    for (int i = 0; i < testCount; i++) {
        float sum = 0;
        for (int j = 0; j < studentCount; j++) {
            sum += arr[j].tests[i].getTestScore();
        }
        char grade;
        float average = sum / studentCount;
        if (average >= 90) {
            grade = 'A';
        } else if (average >= 80) {
            grade = 'B';
        } else if (average >= 70) {
            grade = 'C';
        } else if (average >= 60) {
            grade = 'D';
        } else {
            grade = 'F';
        }
        cout << "Class average for test " << i + 1 << ": " << average << " (" << grade << ")" << endl;
    }
}

//  Program Greeting
int main() {
    cout << "Zak Attack" << endl;
    cout << "----------" << endl;
    cout << "Zak Attack is a program, designed for Prof. Zak, that will calculate a student's GPA and the class average for each quiz during a semester. If more than 4 quizzes are taken Prof. Zak will drop the lowest 3." << endl << endl;
    
    //  Specification B1 - Pseudo Dynamic Array
    static int numTests = 0;
    cout << "How many quizzes did you have this semester? (Enter a number greater than 0): ";
    cin >> numTests;
    cout << endl;
    
    //  Specification A2 - Number of Students Prompt
    static int numStudents;
    cout << "How many students did you have total? (Enter a number greater than 0): ";
    cin >> numStudents;
    cin.ignore(1);
    cout << endl;
    Student * students;
    students = new Student[numStudents];
    
    // Specification A1 - Main Student Loop
    for (int i = 0; i < numStudents; i++) {
        students[i].setFields(numTests);
        students[i].getTestData();
    }
    cout << endl;
    students[0].showAverage(students, numStudents);

    for (int i = 0; i < numStudents; i++) {
        students[i].showSummary();
    }
    return 0;
}
