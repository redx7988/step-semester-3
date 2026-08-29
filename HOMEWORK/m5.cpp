#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string empName;
    double salary;
    
    // Static fields shared by all employees
    static string companyName;
    static int employeeCount;

    Employee(string name, double sal) {
        empName = name;
        salary = sal;
        employeeCount++; // increments once inside constructor, every time
    }

    // Static method that does not reference any instance fields
    static void printCompanyInfo() {
        cout << companyName << "\n";
        cout << "Employees on record: " << employeeCount << "\n";
    }
};

// C++ requires initializing static class members outside the class
string Employee::companyName = "Bright Horizon Technologies";
int Employee::employeeCount = 0;

int main() {
    // Create three Employee objects
    Employee e1("Alice", 60000);
    Employee e2("Bob", 55000);
    Employee e3("Charlie", 62000);

    // Call static method through the class name, not through any object
    Employee::printCompanyInfo();

    return 0;
}