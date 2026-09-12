public class CirculationReport {

    // Builds a single piece of text using StringBuilder without repeated string concatenation[cite: 1]
    public static String batchPrint(LibraryMember[] members) {
        StringBuilder report = new StringBuilder();
        
        for (LibraryMember member : members) {
            // Polymorphic call avoiding instanceof-based if-else chains[cite: 1]
            report.append(member.displayInfo()); 
            
            // Guards downcast with instanceof for genuine StudentMembers[cite: 1]
            if (member instanceof StudentMember) {
                StudentMember sm = (StudentMember) member;
                report.append(" [Course via downcast: ").append(sm.course).append("] | ");
            } else {
                report.append(" | ");
            }
        }
        
        return report.toString();
    }
}