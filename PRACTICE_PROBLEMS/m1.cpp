#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AccessChecker {
public:
    static string classifyAccess(const string& fieldModifier, const string& accessorContext) {
        if (fieldModifier == "public") {
            return "ALLOWED";
        } 
        if (fieldModifier == "private") {
            return (accessorContext == "SAME_CLASS") ? "ALLOWED" : "DENIED";
        } 
        if (fieldModifier == "default" || fieldModifier == "protected") {
            return (accessorContext == "SAME_CLASS" || accessorContext == "SAME_PACKAGE") ? "ALLOWED" : "DENIED";
        } 
        return "DENIED";
    }

    static string summarizeBatch(const vector<pair<string, string>>& attempts) {
        int allowed = 0, denied = 0;
        for (const auto& attempt : attempts) {
            if (classifyAccess(attempt.first, attempt.second) == "ALLOWED") {
                allowed++;
            } else {
                denied++;
            }
        }
        return "Allowed: " + to_string(allowed) + "\nDenied: " + to_string(denied);
    }
};