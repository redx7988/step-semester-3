#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string empId;
    string empName;
    double salary;
    bool isIntern;

    // Constructor for permanent employees
    Employee(string id, string name, double sal) {
        empId = id;
        empName = name;
        salary = sal;
        isIntern = false;
    }

    // Constructor for interns using C++11 constructor chaining
    Employee(string id, string name) : Employee(id, name, 0.0) {
        isIntern = true; // Sets to true afterwards
    }

    void printProfile() {
        cout << empId << " | " << empName << " | Rs " << salary 
             << " | Intern: " << (isIntern ? "true" : "false") << "\n";
    }
};

int main() {
    Employee emp1("E-101", "Divya", 65000);
    Employee emp2("E-102", "Arjun");

    emp1.printProfile();
    emp2.printProfile();

    return 0;
}