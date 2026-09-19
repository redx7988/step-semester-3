#include <iostream>
#include <string>
#include <vector>
#include <cctype>

class GymMember {
private:
    static int globalCounter;
    static int membersEnrolled;
    int feesPaid = 0;

protected:
    int monthlyFee;

public:
    const std::string membershipNumber;

    GymMember(int monthlyFee) 
        : monthlyFee(monthlyFee), 
          membershipNumber("GYM-" + std::to_string(++globalCounter)) {
        membersEnrolled++;
    }

    virtual ~GymMember() = default;

    void payFee(int amount) {
        feesPaid += amount;
    }

    void payFee(int amount, const std::string& mode) {
        std::cout << "[Recording Mode: " << mode << "]\n";
        payFee(amount); // Reuse logic
    }

    int getFeesPaid() const {
        return feesPaid;
    }

    static bool isValidReferralCode(const std::string& code) {
        if (code.length() != 4) return false;
        if (code[0] != 'G') return false;
        if (!std::isdigit(code[1]) || !std::isdigit(code[2])) return false;
        if (!std::isupper(code[3])) return false;
        
        return true;
    }

    static int getMembersEnrolled() {
        return membersEnrolled;
    }
};

// Static initialization
int GymMember::globalCounter = 2000;
int GymMember::membersEnrolled = 0;

class GroupClassMember : public GymMember {
private:
    std::string className;

public:
    GroupClassMember(int monthlyFee, std::string className)
        : GymMember(monthlyFee), className(className) {}
};

std::string processWeeklyCheckIn(const std::vector<GymMember*>& members) {
    int processed = 0;
    int nullSkipped = 0;
    int group = 0;
    int individual = 0;

    for (GymMember* m : members) {
        if (m == nullptr) {
            nullSkipped++;
            continue;
        }
        
        processed++;
        
        if (dynamic_cast<GroupClassMember*>(m)) {
            group++;
        } else {
            individual++;
        }
    }
    
    return std::to_string(processed) + " processed | " + 
           std::to_string(nullSkipped) + " null skipped | " + 
           std::to_string(group) + " group | " + 
           std::to_string(individual) + " individual";
}

int main() {
    GymMember m1(1000);
    std::cout << "Membership Number: " << m1.membershipNumber << "\n";
    std::cout << "Enrolled: " << GymMember::getMembersEnrolled() << "\n\n";

    std::cout << "G45B: " << (GymMember::isValidReferralCode("G45B") ? "true" : "false") << "\n";
    std::cout << "G4B: " << (GymMember::isValidReferralCode("G4B") ? "true" : "false") << "\n";
    std::cout << "X45B: " << (GymMember::isValidReferralCode("X45B") ? "true" : "false") << "\n\n";

    m1.payFee(500);
    m1.payFee(500, "UPI");
    std::cout << "Total Fees Paid: " << m1.getFeesPaid() << "\n\n";

    GymMember* gm = new GymMember(1000);
    GroupClassMember* gcm = new GroupClassMember(1500, "Zumba");
    
    std::vector<GymMember*> checkinBatch = {gcm, nullptr, gm};
    std::cout << processWeeklyCheckIn(checkinBatch) << "\n";

    delete gm;
    delete gcm;

    return 0;
}