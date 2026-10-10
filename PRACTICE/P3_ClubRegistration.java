import java.util.HashSet;
import java.util.Objects;
import java.util.Set;

class Student {
    String rollNumber;
    String name;

    public Student(String rollNumber, String name) {
        this.rollNumber = rollNumber;
        this.name = name;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Student student = (Student) obj;
        return Objects.equals(rollNumber, student.rollNumber);
    }

    @Override
    public int hashCode() {
        return Objects.hash(rollNumber);
    }
}

public class P3_ClubRegistration {
    public static void main(String[] args) {
        Set<Student> members = new HashSet<>();

        String[][] inputs = {
            {"ADD", "21CS01", "Asha"},
            {"ADD", "21CS01", "Asha"},
            {"ADD", "21CS02", "Ravi"},
            {"CONTAINS", "21CS02", "Ravi"},
            {"CONTAINS", "21CS03", "Priya"}
        };

        for (String[] op : inputs) {
            Student s = new Student(op[1], op[2]);
            if (op[0].equals("ADD")) {
                if (members.add(s)) {
                    System.out.println("Added");
                } else {
                    System.out.println("duplicate rejected");
                }
            } else if (op[0].equals("CONTAINS")) {
                System.out.println("contains: " + members.contains(s));
            }
        }
        System.out.println("member count " + members.size());
    }
}