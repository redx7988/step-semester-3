import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

interface NotificationChannel {
    void send(String studentName, String message);
}

class EmailChannel implements NotificationChannel {
    public void send(String studentName, String message) {
        System.out.println("[Email → " + studentName + "] " + message);
    }
}

class SmsChannel implements NotificationChannel {
    public void send(String studentName, String message) {
        System.out.println("[SMS → " + studentName + "] " + message);
    }
}

class AppChannel implements NotificationChannel {
    public void send(String studentName, String message) {
        System.out.println("[App → " + studentName + "] " + message);
    }
}

class StudentNoticeInfo {
    String name;
    String department;
    List<NotificationChannel> channels;

    public StudentNoticeInfo(String name, String department, List<NotificationChannel> channels) {
        this.name = name;
        this.department = department;
        this.channels = channels;
    }
}

class NoticeBoard {
    private List<StudentNoticeInfo> students = new ArrayList<>();

    public void registerStudent(StudentNoticeInfo s) { students.add(s); }

    public void postNotice(String title, List<String> targetDepartments) {
        if (title == null || title.trim().isEmpty() || targetDepartments == null || targetDepartments.isEmpty()) {
            System.out.println("Cannot post notice: At least one target department is required.");
            return;
        }

        System.out.println("Notice '" + title + "' posted to " + String.join(", ", targetDepartments) + ".");
        
        for (StudentNoticeInfo s : students) {
            if (targetDepartments.contains(s.department)) {
                for (NotificationChannel channel : s.channels) {
                    channel.send(s.name, title);
                }
            }
        }
    }
}

public class Q5 {
    public static void main(String[] args) {
        NoticeBoard board = new NoticeBoard();
        
        StudentNoticeInfo asha = new StudentNoticeInfo("Asha", "CSE", Arrays.asList(new EmailChannel(), new AppChannel()));
        StudentNoticeInfo ravi = new StudentNoticeInfo("Ravi", "ECE", Arrays.asList(new SmsChannel()));
        
        board.registerStudent(asha);
        board.registerStudent(ravi);

        board.postNotice("Lab Closed Tomorrow", Arrays.asList("CSE"));
        board.postNotice("Fee Deadline Extended", Arrays.asList("CSE", "ECE"));
        board.postNotice("Sports Day", new ArrayList<>());
    }
}