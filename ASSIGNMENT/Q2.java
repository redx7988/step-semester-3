abstract class Assignment {
    protected String title;
    protected int maxMarks;
    protected int dueDay;

    public Assignment(String title, int maxMarks, int dueDay) {
        this.title = title;
        this.maxMarks = maxMarks;
        this.dueDay = dueDay;
    }
    public String getTitle() { return title; }
    public int getMaxMarks() { return maxMarks; }
    public int getDueDay() { return dueDay; }
    
    public abstract double calculateLatePenaltyPercentage(int lateDays);
}

class CodingAssignment extends Assignment {
    public CodingAssignment(String title, int maxMarks, int dueDay) { super(title, maxMarks, dueDay); }
    public double calculateLatePenaltyPercentage(int lateDays) { return lateDays * 10.0; }
}

class WrittenAssignment extends Assignment {
    public WrittenAssignment(String title, int maxMarks, int dueDay) { super(title, maxMarks, dueDay); }
    public double calculateLatePenaltyPercentage(int lateDays) { return lateDays * 20.0; }
}

class Submission {
    private String studentName;
    private Assignment assignment;
    private String status = "Submitted";
    private int submitDay;

    public Submission(String studentName, Assignment assignment, int submitDay) {
        this.studentName = studentName;
        this.assignment = assignment;
        this.submitDay = submitDay;
        
        int lateDays = Math.max(0, submitDay - assignment.getDueDay());
        String timing = lateDays == 0 ? "on time" : lateDays + " days late";
        System.out.println(studentName + "'s submission for '" + assignment.getTitle() + "' received (" + timing + "). Status: " + status + ".");
    }

    public void grade(int awardedMarks) {
        if (status.equals("Graded")) {
            System.out.println("Cannot resubmit: '" + assignment.getTitle() + "' has already been graded.");
            return;
        }
        
        int lateDays = Math.max(0, submitDay - assignment.getDueDay());
        double penaltyPercent = assignment.calculateLatePenaltyPercentage(lateDays);
        double finalMarks = awardedMarks - (awardedMarks * (penaltyPercent / 100.0));
        
        this.status = "Graded";
        
        if (penaltyPercent > 0) {
            System.out.printf("%s graded: %.0f/%d after %.0f%% late penalty. Status: %s.\n", 
                studentName, finalMarks, assignment.getMaxMarks(), penaltyPercent, status);
        } else {
            System.out.printf("%s graded: %.0f/%d. Status: %s.\n", 
                studentName, finalMarks, assignment.getMaxMarks(), status);
        }
    }
    
    public void resubmit() {
        if (status.equals("Graded")) {
            System.out.println("Cannot resubmit: '" + assignment.getTitle() + "' has already been graded.");
        }
    }
}

public class Q2 {
    public static void main(String[] args) {
        Assignment lab = new CodingAssignment("Linked List Lab", 50, 10);
        Assignment essay = new WrittenAssignment("Design Essay", 50, 12);
        
        Submission ashaSub = new Submission("Asha", lab, 10);
        Submission raviSub = new Submission("Ravi", essay, 14);
        
        ashaSub.grade(45);
        raviSub.grade(40);
        
        ashaSub.resubmit();
    }
}