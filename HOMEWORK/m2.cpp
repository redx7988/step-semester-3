#include <iostream>
using namespace std;

class PayrollAccount {
private:
    double basicSalary;
    double bonus;

public:
    // Constructor 
    PayrollAccount(double openingSalary) {
        bonus = 0; // Initialize bonus to 0
        if (openingSalary < 0) {
            basicSalary = 0;
            cout << "Warning: Opening salary cannot be negative. Starting at 0.\n";
        } else {
            basicSalary = openingSalary;
        }
    }

    // Credit bonus method
    void creditBonus(double amount) {
        if (amount <= 0) {
            cout << "Bonus rejected: amount must be greater than 0\n";
        } else {
            bonus += amount;
            cout << "Bonus credited: Rs " << amount << "\n";
        }
    }

    // Deduct tax method
    void deductTax(double percent) {
        if (percent < 0 || percent > 100) {
            cout << "Tax deduction rejected: percent must be between 0 and 100\n";
        } else {
            basicSalary -= (basicSalary * (percent / 100.0));
            cout << "Tax deducted: " << percent << "%\n";
        }
    }

    // Read-only access for net salary
    double getNetSalary() {
        return basicSalary + bonus;
    }
};

int main() {
    PayrollAccount account(50000);
    account.creditBonus(5000);
    account.deductTax(10);
    cout << "Net salary: Rs " << account.getNetSalary() << "\n";
    return 0;
}