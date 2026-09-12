// Requires LibraryMember and StudentMember from Problem 1
class HonorsStudentMember extends StudentMember {
    private int bonusLimit;

    // Multilevel inheritance (three classes deep)[cite: 1]
    public HonorsStudentMember(String memberId, int borrowLimit, String course, int bonusLimit) {
        super(memberId, borrowLimit, course);
        this.bonusLimit = bonusLimit;
    }
    
    public String displayInfo() {
        return "Honors Student Member | Course: " + course + " | Bonus Limit: " + bonusLimit + " | Books Borrowed: " + getBooksBorrowed();
    }
}

class FacultyMember extends LibraryMember {
    private String department;

    // Hierarchical inheritance directly from LibraryMember[cite: 1]
    public FacultyMember(String memberId, int borrowLimit, String department) {
        super(memberId, borrowLimit);
        this.department = department;
    }
    
    public String displayInfo() {
        return "Faculty Member | Department: " + department + " | Books Borrowed: " + getBooksBorrowed();
    }
}

class MembershipUtils {
    // Decides answer using instanceof checks alone without manual type fields[cite: 1]
    public static String classifyGeneration(LibraryMember member) {
        if (member instanceof HonorsStudentMember) {
            return "Multilevel descendant (3 generations deep)";
        } else if (member instanceof FacultyMember) {
            return "Hierarchical sibling (independent branch)";
        } else if (member instanceof StudentMember) {
            return "Multilevel descendant (2 generations deep)";
        }
        return "Base Generation";
    }

    // Accepts any mix of the four membership types and sums borrowed counts via polymorphism[cite: 1]
    public static int getTotalBooksBorrowed(LibraryMember[] members) {
        int total = 0;
        for (LibraryMember member : members) {
            total += member.getBooksBorrowed();
        }
        return total;
    }
}