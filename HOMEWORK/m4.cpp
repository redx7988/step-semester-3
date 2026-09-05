#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MembershipCard {
public:
    static string libraryName;
    static string validUntil;
    string studentName;

private:
    // Helper to simulate Java static block execution exactly once
    static bool initializeStaticData() {
        libraryName = "SRM Central Library";
        validUntil = "May 2027";
        cout << "Library info loaded\n";
        return true;
    }
    static bool isInitialized;

public:
    MembershipCard(string studentName) {
        this->studentName = studentName;
    }
};

// Static initializations (executes before main)
string MembershipCard::libraryName = "";
string MembershipCard::validUntil = "";
bool MembershipCard::isInitialized = MembershipCard::initializeStaticData();

int main() {
    vector<string> names = {"Ananya", "Rohan", "Priya", "Arjun", "Sneha"};

    for (const string& name : names) {
        MembershipCard card(name);
        cout << "Membership card issued: " << card.studentName << "\n";
    }
    return 0;
}