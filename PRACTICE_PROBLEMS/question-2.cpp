#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string id;
    double salary;

public:
    Employee(string id, double salary) {
        this->id = id;          // 'this->' points to the class variable
        this->salary = salary;
    }

    void raiseSalary(double salary) {
        this->salary += salary; // Adds the parameter to the class variable
    }

    void printFinalSalary() {
        cout << id << " | Final Salary: Rs " << salary << endl;
    }
};

int main() {
    Employee team[] = {
        Employee("E-101", 40000),
        Employee("E-102", 55000),
        Employee("E-103", 62000),
        Employee("E-104", 48000)
    };

    for (int i = 0; i < 4; i++) {
        team[i].raiseSalary(5000);
        team[i].printFinalSalary();
    }
    return 0;
}