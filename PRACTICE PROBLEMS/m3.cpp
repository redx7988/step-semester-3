#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LibraryMember {
private:
    vector<int> fineHistory; // Private array field to record every fine applied[cite: 2]

protected:
    virtual void chargeFine(int amount) {
        if (amount > 0 && fineHistory.size() < 10) { // Limit to 10 fines[cite: 2]
            fineHistory.push_back(amount);
        }
    }

public:
    LibraryMember() {}
    virtual ~LibraryMember() = default;

    vector<int> getFineHistory() const {
        return fineHistory; // Returns a defensive copy (C++ vector returns by value)[cite: 2]
    }

    int getTotalFine() const {
        int total = 0;
        for (int fine : fineHistory) {
            total += fine;
        }
        return total;
    }
};

class StudentMember : public LibraryMember {
public:
    StudentMember(string id, int limit, string course) {}

    // Overrides chargeFine to halve the amount and call the parent's logic[cite: 2]
    void chargeFine(int amount) override {
        LibraryMember::chargeFine(amount / 2); // Calls super.chargeFine(...) with halved amount[cite: 2]
    }
};