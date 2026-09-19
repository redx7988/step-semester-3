#include <iostream>
#include <string>
#include <vector>
#include <numeric>

class GymMember {
private:
    std::vector<int> lateFeeHistory;

protected:
    std::string memberId;
    int monthlyFee;

public:
    GymMember(std::string id, int fee) : memberId(id), monthlyFee(fee) {}
    virtual ~GymMember() = default;

    virtual void chargeLateFee(int amount) {
        if (amount > 0) {
            lateFeeHistory.push_back(amount);
        }
    }

    std::vector<int> getLateFeeHistory() const {
        // Returning by value creates a defensive copy in C++
        return lateFeeHistory; 
    }

    int getTotalLateFees() const {
        int total = 0;
        for(int fee : lateFeeHistory) {
            total += fee;
        }
        return total;
    }
};

class PremiumMember : public GymMember {
private:
    std::string trainerName;

public:
    PremiumMember(std::string id, int fee, std::string trainer)
        : GymMember(id, fee), trainerName(trainer) {}

    void chargeLateFee(int amount) override {
        // Delegate to superclass with halved amount
        GymMember::chargeLateFee(amount / 2);
    }
};

int main() {
    PremiumMember p("MEM5", 2000, "Coach Riya");
    
    p.chargeLateFee(200);
    std::cout << "Total Late Fees: " << p.getTotalLateFees() << "\n";

    std::vector<int> history = p.getLateFeeHistory();
    std::cout << "History[0] before modification: " << history[0] << "\n";
    
    // Attempting to tamper with the returned copy
    history[0] = 999;
    
    std::vector<int> historyAfter = p.getLateFeeHistory();
    std::cout << "History[0] in actual object: " << historyAfter[0] << "\n";

    return 0;
}