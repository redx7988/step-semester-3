#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class GymMember {
protected:
    std::string memberId;
    int monthlyFee;
    int sessionsAttended = 0;

public:
    GymMember(std::string id, int fee) : memberId(id), monthlyFee(fee) {}
    virtual ~GymMember() = default;

    virtual std::string displayInfo() const {
        return "Standard | Sessions: " + std::to_string(sessionsAttended);
    }
};

class PremiumMember : public GymMember {
private:
    std::string trainerName;

public:
    PremiumMember(std::string id, int fee, std::string trainer)
        : GymMember(id, fee), trainerName(trainer) {}

    std::string getTrainerName() const {
        return trainerName;
    }

    std::string displayInfo() const override {
        return "Premium | Trainer: " + trainerName + " | Sessions: " + std::to_string(sessionsAttended);
    }
};

std::string batchPrint(const std::vector<GymMember*>& members) {
    std::ostringstream announcement;
    
    for (GymMember* m : members) {
        if (!m) continue;
        
        announcement << m->displayInfo();
        
        // Polymorphic check and downcast to extract Premium specifics
        if (PremiumMember* pm = dynamic_cast<PremiumMember*>(m)) {
            announcement << " [Trainer via downcast: " << pm->getTrainerName() << "]";
        }
        
        announcement << " | \n";
    }
    
    return announcement.str();
}

int main() {
    GymMember* gm = new GymMember("MEM6", 1000);
    PremiumMember* pm = new PremiumMember("MEM7", 2000, "Coach Riya");
    
    std::vector<GymMember*> members = {gm, pm};
    
    std::cout << batchPrint(members);

    // Demonstrating proper runtime safety avoidance of ClassCastException. 
    // In C++, dynamic_cast returns nullptr if the cast fails.
    GymMember* plain = new GymMember("MEM8", 1000);
    PremiumMember* bad = dynamic_cast<PremiumMember*>(plain);
    
    if (bad == nullptr) {
        std::cout << "\nSafe Downcast Result: Cast rejected at runtime (Avoided ClassCastException).\n";
    }

    delete gm;
    delete pm;
    delete plain;

    return 0;
}