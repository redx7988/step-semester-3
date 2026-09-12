#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class LibraryMember {
protected:
    int booksBorrowed = 0;
public:
    virtual ~LibraryMember() = default;
    virtual string displayInfo() const {
        return "General | Books: " + to_string(booksBorrowed);
    }
};

class StudentMember : public LibraryMember {
private:
    string course;
public:
    StudentMember(string crs) : course(crs) {}
    string getCourse() const { return course; }
    
    string displayInfo() const override {
        return "Student | Course: " + course + " | Books: " + to_string(booksBorrowed);
    }
};

class ReportGenerator {
public:
    static string batchPrint(const vector<LibraryMember*>& members) {
        ostringstream reportBuilder; // Assembles text with string builder equivalent, not repeated concatenation[cite: 2]
        
        for (const auto* member : members) {
            // Polymorphic call without instanceof-based if-else chains for printing base info[cite: 2]
            reportBuilder << member->displayInfo();
            
            // Genuine StudentMember downcast guard using dynamic_cast (instanceof equivalent)[cite: 2]
            if (const StudentMember* student = dynamic_cast<const StudentMember*>(member)) {
                reportBuilder << " [Course via downcast: " << student->getCourse() << "]";
            }
            reportBuilder << " | ";
        }
        
        return reportBuilder.str();
    }
};