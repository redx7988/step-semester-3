#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ExtendedAccessChecker {
public:
    static string classifyAccess(const string& fieldModifier, const string& accessorContext) {
        if (fieldModifier == "public") return "ALLOWED";
        if (fieldModifier == "private") {
            return (accessorContext == "SAME_CLASS") ? "ALLOWED" : "DENIED";
        }
        if (fieldModifier == "default") {
            return (accessorContext == "SAME_CLASS" || accessorContext == "SAME_PACKAGE") ? "ALLOWED" : "DENIED";
        }
        if (fieldModifier == "protected") {
            // protected is ALLOWED for SUBCLASS_DIFFERENT_PACKAGE_OWN_TYPE but DENIED for PARENT_TYPE[cite: 1]
            if (accessorContext == "SAME_CLASS" || 
                accessorContext == "SAME_PACKAGE" || 
                accessorContext == "SUBCLASS_DIFFERENT_PACKAGE_OWN_TYPE") {
                return "ALLOWED";
            }
            return "DENIED";
        }
        return "DENIED";
    }

    static string firstDeniedAttempt(const vector<pair<string, string>>& attempts) {
        // Scans attempts strictly in order and stops at the very first denial[cite: 1]
        for (size_t i = 0; i < attempts.size(); ++i) {
            if (classifyAccess(attempts[i].first, attempts[i].second) == "DENIED") {
                return attempts[i].first + " via " + attempts[i].second + " (attempt #" + to_string(i + 1) + ")";
            }
        }
        return "None Denied";
    }
};