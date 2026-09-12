public class LibraryMemberAudit {
    private static int counter = 100; 
    private static int membersEnrolled = 0;
    
    // Final field assigned at construction; never changeable[cite: 1]
    public final String memberNumber;
    protected int borrowLimit;
    protected int booksBorrowed;
    protected String lastGenreBorrowed;

    public LibraryMemberAudit(int borrowLimit) {
        this.memberNumber = "LIB-" + (++counter);
        this.borrowLimit = borrowLimit;
        this.booksBorrowed = 0;
        membersEnrolled++;
    }

    public void borrowBook() {
        if (booksBorrowed < borrowLimit) {
            booksBorrowed++;
        }
    }

    // Overloaded method that records genre before delegating to the no-argument version[cite: 1]
    public void borrowBook(String genre) {
        this.lastGenreBorrowed = genre;
        this.borrowBook(); 
    }

    public int getBooksBorrowed() {
        return booksBorrowed;
    }

    public static int getMembersEnrolled() {
        return membersEnrolled;
    }

    // Checks exact format strictly using charAt() and Character methods[cite: 1]
    public static boolean isValidRenewalCode(String code) {
        if (code == null || code.length() != 4) return false;
        if (code.charAt(0) != 'R') return false;
        if (!Character.isDigit(code.charAt(1))) return false;
        if (!Character.isDigit(code.charAt(2))) return false;
        if (!Character.isUpperCase(code.charAt(3))) return false;
        return true;
    }

    // Safely skips missing entries and uses instanceof to categorize counts[cite: 1]
    public static String processNightlyAudit(LibraryMemberAudit[] members) {
        int processed = 0, skipped = 0, faculty = 0, regular = 0;
        
        for (LibraryMemberAudit m : members) {
            if (m == null) {
                skipped++;
                continue;
            }
            processed++;
            if (m instanceof FacultyMemberAudit) {
                faculty++;
            } else {
                regular++;
            }
        }
        return processed + " processed | " + skipped + " null skipped | " + faculty + " faculty | " + regular + " regular";
    }
}

class FacultyMemberAudit extends LibraryMemberAudit {
    private String department;

    public FacultyMemberAudit(int borrowLimit, String department) {
        super(borrowLimit);
        this.department = department;
    }
}