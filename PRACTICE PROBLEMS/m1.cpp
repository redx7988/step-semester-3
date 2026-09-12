#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cctype>

using namespace std;

class LibraryMember {
protected:
    string memberId;
    int borrowLimit;
    int booksBorrowed;

    // Helper to check for blank or whitespace-only strings
    bool isBlank(const string& s) {
        for (char c : s) {
            if (!isspace(static_cast<unsigned char>(c))) return false;
        }
        return true;
    }

public:
    LibraryMember(string id, int limit) : borrowLimit(limit), booksBorrowed(0) {
        // Constructor rejects memberId that is blank, whitespace-only, or shorter than 4 characters
        if (id.length() < 4 || isBlank(id)) {
            throw invalid_argument("construction rejected");
        }
        memberId = id;
    }

    virtual ~LibraryMember() = default;

    virtual void borrowBook() {
        if (booksBorrowed < borrowLimit) {
            booksBorrowed++;
        }
    }

    int getBooksBorrowed() const {
        return booksBorrowed;
    }
};

// StudentMember extends LibraryMember directly and forwards shared fields
class StudentMember : public LibraryMember {
private:
    string course;

public:
    // Does not duplicate memberId or borrowLimit; uses parent constructor
    StudentMember(string id, int limit, string course) 
        : LibraryMember(id, limit), course(course) {}
};

class EnrollmentValidator {
public:
    static string enrollBatch(const vector<string>& memberIds, int borrowLimit) {
        int enrolled = 0;
        int rejected = 0;
        
        // Attempts construction per array entry using try/catch to count rejections[cite: 2]
        for (const string& id : memberIds) {
            try {
                LibraryMember temp(id, borrowLimit);
                enrolled++;
            } catch (const invalid_argument&) {
                rejected++;
            }
        }
        
        return "Enrolled: " + to_string(enrolled) + " | Rejected: " + to_string(rejected);
    }
};