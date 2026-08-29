#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int attendance;
    
    // Static fields shared by all students
    static string collegeName;
    static int studentCount;

    Student(string n, int att) {
        name = n;
        attendance = att;
        studentCount++; // increments once every time constructor is called
    }

    // Static method that does not touch instance fields
    static void printCollegeInfo() {
        cout << collegeName << "\n";
        cout << "Students created: " << studentCount << "\n";
    }
};

// C++ requires static variables to be initialized outside the class declaration
string Student::collegeName = "SRM Institute of Science and Technology";
int Student::studentCount = 0;

int main() {
    // Create two Student objects
    Student s1("Alice", 85);
    Student s2("Bob", 92);

    // Call through the class name, not the object
    Student::printCollegeInfo();

    return 0;
}