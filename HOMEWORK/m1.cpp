#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Participant {
private:
    string name;
    string teamName;
    bool registered;

public:
    // Main constructor
    Participant(string name, string teamName) {
        this->name = name;
        this->teamName = teamName;
        this->registered = true;
    }

    // Delegating constructor (C++ equivalent of this(...) chaining)
    Participant(string name) : Participant(name, "Unassigned") {}

    void printStatus() const {
        cout << name << " | " << teamName << " | Registered: " << (registered ? "true" : "false") << "\n";
    }
};

int main() {
    vector<string> names = {"Ravi", "Meera", "Karthik", "Divya"};
    vector<string> teamNames = {"ByteBusters", "", "CodeCrafters", ""};

    for (size_t i = 0; i < names.size(); i++) {
        if (teamNames[i] == "") {
            Participant p(names[i]);
            p.printStatus();
        } else {
            Participant p(names[i], teamNames[i]);
            p.printStatus();
        }
    }
    return 0;
}