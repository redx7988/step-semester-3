#include <iostream>
using namespace std;

class MessWallet {
private:
    double balance;

public:
    // Constructor
    MessWallet(double openingBalance) {
        if (openingBalance < 0) {
            balance = 0;
            cout << "Warning: Opening balance cannot be negative. Starting at 0.\n";
        } else {
            balance = openingBalance;
        }
    }

    // Top-up method
    void topUp(double amount) {
        if (amount <= 0) {
            cout << "Top-up rejected: amount must be greater than 0\n";
        } else {
            balance += amount;
            cout << "Balance after top-up: " << balance << "\n";
        }
    }

    // Deduct method
    void deduct(double amount) {
        if (amount > balance) {
            cout << "Deduct rejected: insufficient balance\n";
        } else {
            balance -= amount;
            cout << "Final balance: " << balance << "\n";
        }
    }

    // Read-only access
    double getBalance() {
        return balance;
    }
};

int main() {
    MessWallet wallet(500); // opening = 500
    wallet.topUp(200);      
    wallet.deduct(1000);    
    return 0;
}