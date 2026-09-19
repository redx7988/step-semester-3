#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cctype>

class GymMember {
protected:
    std::string memberId;
    int monthlyFee;
    int sessionsAttended = 0;

public:
    GymMember(std::string memberId, int monthlyFee) 
        : memberId(memberId), monthlyFee(monthlyFee) {
        
        bool isBlankOrWhitespace = true;
        for (char c : memberId) {
            if (!std::isspace(c)) {
                isBlankOrWhitespace = false;
                break;
            }
        }
        
        if (memberId.length() < 4 || isBlankOrWhitespace) {
            throw std::invalid_argument("construction rejected");
        }
    }

    virtual ~GymMember() = default;

    virtual void attendSession() {
        sessionsAttended++;
    }

    int getSessionsAttended() const {
        return sessionsAttended;
    }

    static std::string signUpBatch(const std::vector<std::string>& memberIds, int monthlyFee) {
        int signedUp = 0;
        int rejected = 0;
        
        for (const std::string& id : memberIds) {
            try {
                GymMember member(id, monthlyFee);
                signedUp++;
            } catch (const std::invalid_argument&) {
                rejected++;
            }
        }
        return "Signed Up: " + std::to_string(signedUp) + " | Rejected: " + std::to_string(rejected);
    }
};

class PremiumMember : public GymMember {
private:
    std::string trainerName;

public:
    PremiumMember(std::string memberId, int monthlyFee, std::string trainerName)
        : GymMember(memberId, monthlyFee), trainerName(trainerName) {}
};

int main() {
    // Example 1
    try {
        GymMember gm1("GM1", 1000);
    } catch (const std::invalid_argument& e) {
        std::cout << "Output: " << e.what() << "\n";
    }

    // Example 2
    PremiumMember p("MEM01", 2000, "Coach Riya");
    p.attendSession();
    p.attendSession();
    std::cout << "Output: " << p.getSessionsAttended() << "\n";

    // Example 3
    std::vector<std::string> batch = {"MEM1", "GM1", "MEM2", "   ", "MEM3"};
    std::cout << "Output: " << GymMember::signUpBatch(batch, 1000) << "\n";

    return 0;
}