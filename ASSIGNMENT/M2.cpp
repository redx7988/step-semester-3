#include <iostream>
#include <string>
#include <vector>

class GymMember {
protected:
    std::string memberId;
    int monthlyFee;
    int sessionsAttended = 0;

public:
    GymMember(std::string id, int fee) : memberId(id), monthlyFee(fee) {}
    virtual ~GymMember() = default;

    virtual std::string displayInfo() const {
        return "Standard Member | Sessions: " + std::to_string(sessionsAttended);
    }

    virtual void attendSession() { sessionsAttended++; }
    int getSessionsAttended() const { return sessionsAttended; }
};

class PremiumMember : public GymMember {
protected:
    std::string trainerName;
public:
    PremiumMember(std::string id, int fee, std::string trainer)
        : GymMember(id, fee), trainerName(trainer) {}

    std::string displayInfo() const override {
        return "Premium Member | Trainer: " + trainerName + " | Sessions: " + std::to_string(sessionsAttended);
    }
};

class EliteMember : public PremiumMember {
private:
    std::string lockerNumber;
public:
    EliteMember(std::string id, int fee, std::string trainer, std::string locker)
        : PremiumMember(id, fee, trainer), lockerNumber(locker) {}

    std::string displayInfo() const override {
        return "Elite Member | Trainer: " + trainerName + " | Locker: " + lockerNumber + " | Sessions: " + std::to_string(sessionsAttended);
    }
};

class GroupClassMember : public GymMember {
private:
    std::string className;
public:
    GroupClassMember(std::string id, int fee, std::string className)
        : GymMember(id, fee), className(className) {}

    std::string displayInfo() const override {
        return "Group Class Member | Class: " + className + " | Sessions: " + std::to_string(sessionsAttended);
    }
};

std::string classifyGeneration(GymMember* member) {
    if (dynamic_cast<EliteMember*>(member)) {
        return "Multilevel descendant (3 generations deep)";
    }
    if (dynamic_cast<GroupClassMember*>(member)) {
        return "Hierarchical sibling (independent branch)";
    }
    if (dynamic_cast<PremiumMember*>(member)) {
        return "Multilevel descendant (2 generations deep)";
    }
    return "Base Generation";
}

int getTotalSessionsAttended(const std::vector<GymMember*>& members) {
    int total = 0;
    for (GymMember* m : members) {
        if (m) total += m->getSessionsAttended();
    }
    return total;
}

int main() {
    GymMember base("MEM1", 1000);
    PremiumMember premium("MEM2", 2000, "Coach Riya");
    EliteMember elite("MEM3", 3000, "Coach Arjun", "L12");
    GroupClassMember group("MEM4", 1500, "Zumba");

    std::cout << base.displayInfo() << "\n";
    std::cout << premium.displayInfo() << "\n";
    std::cout << elite.displayInfo() << "\n";
    std::cout << group.displayInfo() << "\n\n";

    std::cout << classifyGeneration(&elite) << "\n";
    std::cout << classifyGeneration(&group) << "\n\n";

    premium.attendSession(); premium.attendSession(); premium.attendSession();
    elite.attendSession(); elite.attendSession();
    group.attendSession(); group.attendSession(); group.attendSession(); group.attendSession();

    std::vector<GymMember*> list = {&premium, &elite, &group};
    std::cout << "Total Sessions: " << getTotalSessionsAttended(list) << "\n";

    return 0;
}