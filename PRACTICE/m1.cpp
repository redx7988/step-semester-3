#include <iostream>
#include <string>
#include <vector>

class Toy {
private:
    static int counter;

public:
    // Final toyId assigned via a shared static counter inside its constructor
    const std::string toyId;
    std::string name;

    Toy(std::string toyName) : toyId("TOY-" + std::to_string(++counter)), name(toyName) {}
    
    virtual ~Toy() = default;

    // Abstract method that prevents instantiation of the base class
    virtual std::string makeSound() const = 0;

    std::string getToyId() const {
        return toyId;
    }
};

// Initialize static counter
int Toy::counter = 1000;

class ToyCar : public Toy {
public:
    ToyCar(std::string name) : Toy(name) {}

    std::string makeSound() const override {
        return name + ": Vroom vroom!";
    }
};

class ToyRobot : public Toy {
public:
    ToyRobot(std::string name) : Toy(name) {}

    std::string makeSound() const override {
        return name + ": Beep boop!";
    }
};

int main() {
    ToyCar c("Speedster");
    std::cout << c.makeSound() << "\n";
    
    ToyRobot r("Bolt");
    std::cout << r.makeSound() << "\n";
    
    std::cout << c.getToyId() << "\n";
    std::cout << r.getToyId() << "\n";
    
    // Uncommenting the below line will cause a compile-time error:
    // Toy t("Generic"); 

    return 0;
}