#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class AccessChecker {
public:
    static string classifyAccess(const string& fieldModifier, const string& accessorContext) {
        if (fieldModifier == "public") return "ALLOWED";
        if (fieldModifier == "private") {
            return (accessorContext == "SAME_CLASS") ? "ALLOWED" : "DENIED";
        }
        if (fieldModifier == "default" || fieldModifier == "protected") {
            return (accessorContext == "SAME_CLASS" || accessorContext == "SAME_PACKAGE") ? "ALLOWED" : "DENIED";
        }
        return "DENIED";
    }

    static string summarizeByModifier(const vector<pair<string, string>>& attempts) {
        // Group results per modifier, independent of the result split
        map<string, pair<int, int>> stats = {
            {"private", {0, 0}}, {"default", {0, 0}},
            {"protected", {0, 0}}, {"public", {0, 0}}
        };

        for (const auto& attempt : attempts) {
            string result = classifyAccess(attempt.first, attempt.second);
            if (result == "ALLOWED") stats[attempt.first].first++;
            else stats[attempt.first].second++;
        }

        return "private: " + to_string(stats["private"].first) + " allowed / " + to_string(stats["private"].second) + " denied\n" +
               "default: " + to_string(stats["default"].first) + " allowed / " + to_string(stats["default"].second) + " denied\n" +
               "protected: " + to_string(stats["protected"].first) + " allowed / " + to_string(stats["protected"].second) + " denied\n" +
               "public: " + to_string(stats["public"].first) + " allowed / " + to_string(stats["public"].second) + " denied";
    }
};

class LibraryMember {
private:
    string membershipPin; // Inaccessible from outside LibraryMember
protected: 
    string branchCode;     // Mimicking package-private / protected boundaries
    double finesOwed;
public:
    string displayName;   // Reachable from anywhere
};