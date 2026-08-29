#include <iostream>
#include <string>
using namespace std;

class SrmStudent {
private:
    string name;
    static string collegeName;
    static string academicYear;
    
    // Simulating Java's 'static block'
    struct StaticBlock {
        StaticBlock() {
            cout << "College info loaded" << endl;
            collegeName = "SRM";
            academicYear = "2026";
        }
    };
    static StaticBlock initializer; // Runs exactly once

public:
    SrmStudent(string name) {
        this->name = name;
        cout << "Student record created: " << this->name << endl;
    }
};

// Defining the static variables outside the class
string SrmStudent::collegeName;
string SrmStudent::academicYear;
SrmStudent::StaticBlock SrmStudent::initializer; 

int main() {
    string names[] = {"Ravi", "Meera", "Karthik", "Divya", "Anitha"};

    for (int i = 0; i < 5; i++) {
        SrmStudent student(names[i]);
    }
    return 0;
}