#include <iostream>
#include <string>

// Level 1: Abstract Base Class
class Instrument {
public:
    virtual ~Instrument() = default;
    
    // Abstract method
    virtual std::string play() const = 0;
};

// Level 2: Concrete subclass
class StringInstrument : public Instrument {
public:
    StringInstrument() {} // Constructor calls default parent constructor implicitly

    std::string play() const override {
        return "Strumming the strings";
    }
};

// Level 3: Deep subclass
class Violin : public StringInstrument {
public:
    Violin() : StringInstrument() {} // Explicitly calling parent constructor

    std::string play() const override {
        // Calls super.play() equivalent and appends unique detail
        return StringInstrument::play() + ", with a bow drawn across four strings";
    }
};

int main() {
    StringInstrument s;
    std::cout << s.play() << "\n";

    Violin v;
    std::cout << v.play() << "\n";

    return 0;
}