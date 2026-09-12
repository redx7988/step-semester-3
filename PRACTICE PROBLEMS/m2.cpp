#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LibraryMember {
protected:
    string memberId;
    int borrowLimit;
    int booksBorrowed;

public:
    LibraryMember(string id, int limit) : memberId(id), borrowLimit(limit), booksBorrowed(0) {}
    virtual ~LibraryMember() = default;

    virtual void borrowBook() { booksBorrowed++; }
    virtual int getBooksBorrowed() const { return booksBorrowed; }

    virtual string displayInfo() const {
        return "General Member | Books Borrowed: " + to_string(booksBorrowed);
    }
};

class StudentMember : public LibraryMember {
protected:
    string course;
public:
    StudentMember(string id, int limit, string crs) : LibraryMember(id, limit), course(crs) {}
    string displayInfo() const override {
        return "Student Member | Course: " + course + " | Books Borrowed: " + to_string(booksBorrowed);
    }
};

// HonorsStudentMember extends StudentMember (multilevel inheritance)[cite: 2]
class HonorsStudentMember : public StudentMember {
private:
    int bonusLimit;
public:
    HonorsStudentMember(string id, int limit, string crs, int bonus) 
        : StudentMember(id, limit, crs), bonusLimit(bonus) {}
        
    string displayInfo() const override {
        return "Honors Student Member | Course: " + course + " | Bonus Limit: " + to_string(bonusLimit) + " | Books Borrowed: " + to_string(booksBorrowed);
    }
};

// FacultyMember extends LibraryMember directly (hierarchical inheritance)[cite: 2]
class FacultyMember : public LibraryMember {
private:
    string department;
public:
    FacultyMember(string id, int limit, string dept) : LibraryMember(id, limit), department(dept) {}
    
    string displayInfo() const override {
        return "Faculty Member | Department: " + department + " | Books Borrowed: " + to_string(booksBorrowed);
    }
};

class MembershipUtils {
public:
    static string classifyGeneration(LibraryMember* member) {
        // Decides answer using instanceof (dynamic_cast) alone; no manual type field used[cite: 2]
        if (dynamic_cast<HonorsStudentMember*>(member)) {
            return "Multilevel descendant (3 generations deep)";
        }
        if (dynamic_cast<FacultyMember*>(member)) {
            return "Hierarchical sibling (independent branch)";
        }
        return "General/Student Member";
    }

    static int getTotalBooksBorrowed(const vector<LibraryMember*>& members) {
        int total = 0;
        // Sums borrowed-book counts using each member's own getBooksBorrowed() polymorphically[cite: 2]
        for (const auto& member : members) {
            if (member) {
                total += member->getBooksBorrowed();
            }
        }
        return total;
    }
};