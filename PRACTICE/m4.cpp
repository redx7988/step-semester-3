#include <iostream>
#include <string>

// Abstract Base Class
class KitchenTool {
private:
    int speedLevel = 1; // Default valid speed

public:
    virtual ~KitchenTool() = default;

    virtual std::string prepare() const = 0;

    int getSpeedLevel() const {
        return speedLevel;
    }

    void setSpeedLevel(int level) {
        if (level >= 1 && level <= 5) {
            speedLevel = level;
        } else {
            std::cout << "rejected, speed level stays " << speedLevel << "\n";
        }
    }
};

// Interface
class Washable {
public:
    virtual ~Washable() = default;
    virtual std::string clean() const = 0;
};

// Subclass inheriting both abstract class and interface
class Blender : public KitchenTool, public Washable {
public:
    std::string prepare() const override {
        return "Blending at speed " + std::to_string(getSpeedLevel());
    }

    std::string clean() const override {
        return "Blender rinsed and dried";
    }
};

int main() {
    Blender b;
    b.setSpeedLevel(3);
    std::cout << b.getSpeedLevel() << "\n";

    b.setSpeedLevel(9); // Should reject

    std::cout << b.prepare() << "\n";
    std::cout << b.clean() << "\n";

    return 0;
}