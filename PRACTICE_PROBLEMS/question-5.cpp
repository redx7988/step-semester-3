#include <iostream>
using namespace std;

class FeeAccount {
public:
    // Base class needs at least one virtual function for dynamic_cast to work
    virtual ~FeeAccount() {} 
};

class HostelFeeAccount : public FeeAccount {
    // Empty class just to prove the concept
};

class FinanceOffice {
public:
    int hostelCount = 0;
    int dayScholarCount = 0;

    void processPayment(FeeAccount* account, double amount) {
        // dynamic_cast checks if 'account' is actually a HostelFeeAccount
        if (dynamic_cast<HostelFeeAccount*>(account) != NULL) {
            cout << "Paid in two installments (hostel account)" << endl;
            hostelCount++;
        } else {
            cout << "Paid in one go (day-scholar account)" << endl;
            dayScholarCount++;
        }
    }

    void printCounters() {
        cout << "Hostel accounts processed: " << hostelCount 
             << " | Day-scholar accounts processed: " << dayScholarCount << endl;
    }
};

int main() {
    FinanceOffice office;

    HostelFeeAccount h1, h2;
    FeeAccount f1, f2;

    // Put pointers to our objects in an array
    FeeAccount* accounts[] = {&h1, &h2, &f1, &f2};
    double amount = 60000;

    for (int i = 0; i < 4; i++) {
        office.processPayment(accounts[i], amount);
    }

    office.printCounters();
    return 0;
}