#include <string>

using namespace std;

class PremiumAccessChecker {
public:
    static string classifyAccess(const string& fieldModifier, const string& accessorContext) {
        if (fieldModifier == "public") {
            return "ALLOWED";
        } 
        if (fieldModifier == "private") {
            return (accessorContext == "SAME_CLASS") ? "ALLOWED" : "DENIED";
        } 
        if (fieldModifier == "default") {
            return (accessorContext == "SAME_CLASS" || accessorContext == "SAME_PACKAGE") ? "ALLOWED" : "DENIED";
        } 
        if (fieldModifier == "protected") {
            if (accessorContext == "SAME_CLASS" || 
                accessorContext == "SAME_PACKAGE" || 
                accessorContext == "SUBCLASS_DIFFERENT_PACKAGE_OWN_TYPE") {
                return "ALLOWED";
            }
            // SUBCLASS_DIFFERENT_PACKAGE_PARENT_TYPE falls through to DENIED
            return "DENIED";
        }
        return "DENIED";
    }
};