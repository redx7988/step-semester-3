#include <string>

using namespace std;

class LibraryMemberBean {
private:
    string membershipId;
    bool isMembershipIdSet; // Tracks write-once state
    string name;
    bool premiumMember;
    string securityAnswer;

public:
    // Public no-argument constructor[cite: 1]
    LibraryMemberBean() : membershipId(""), isMembershipIdSet(false), name(""), premiumMember(false), securityAnswer("") {}

    string getMembershipId() const {
        return membershipId;
    }

    void setMembershipId(const string& id) {
        // Write-once implementation: later calls are silently ignored[cite: 1]
        if (!isMembershipIdSet) {
            membershipId = id;
            isMembershipIdSet = true;
        }
    }

    string getName() const {
        return name;
    }

    void setName(const string& n) {
        name = n;
    }

    // JavaBean convention for boolean fields uses "isX()"[cite: 1]
    bool isPremiumMember() const {
        return premiumMember;
    }

    void setPremiumMember(bool premium) {
        premiumMember = premium;
    }

    void setSecurityAnswer(const string& answer) {
        // Store only a one-way transformed value[cite: 1]
        string transformed = "";
        for (char c : answer) {
            transformed += to_string(c ^ 0x3A); // Simple mock transformation
        }
        securityAnswer = transformed;
    }
    
    // No getter exists for securityAnswer[cite: 1]
};