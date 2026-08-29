#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string regNo;
    double totalFee;

public:
    Account(string regNo, double totalFee) {
        this->regNo = regNo;
        this->totalFee = totalFee;
    }
    
    virtual ~Account() {}

    // 'final' locks this method
    virtual double calculateLateFee(int daysLate) final {
        if (daysLate <= 0) {
            return 0.0; // Skip entirely
        }
        return totalFee * 0.01 * daysLate; // 1% per day based on sample output
    }

    // 'final' locks this method
    virtual void printSummary(int daysLate) final {
        if (daysLate <= 0) {
            cout << regNo << " - On time, no late fee" << endl;
        } else {
            cout << regNo << " | Total Fee: Rs " << totalFee 
                 << " | Late Fee: Rs " << calculateLateFee(daysLate) << endl;
        }
    }
};

int main() {
    string regNos[] = {"RA001", "RA002", "RA003", "RA004"};
    double totalFees[] = {200000, 150000, 180000, 220000};
    int daysLate[] = {10, 0, -2, 5};

    for (int i = 0; i < 4; i++) {
        Account acc(regNos[i], totalFees[i]);
        acc.printSummary(daysLate[i]);
    }
    return 0;
}