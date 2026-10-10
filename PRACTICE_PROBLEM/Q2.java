enum LeaveStatus { PENDING, APPROVED, REJECTED }

abstract class Employee {
    protected String name;
    public Employee(String name) { this.name = name; }
    public String getName() { return name; }
}

class FullTimeEmployee extends Employee { 
    public FullTimeEmployee(String name) { super(name); } 
}
class PartTimeEmployee extends Employee { 
    public PartTimeEmployee(String name) { super(name); } 
}

class LeaveRequest {
    private Employee employee;
    private String dates;
    private LeaveStatus status = LeaveStatus.PENDING;

    public LeaveRequest(Employee e, String dates) {
        this.employee = e;
        this.dates = dates;
        System.out.println("Leave request submitted for " + e.getName() + " (" + dates + "). Status: " + status + ".");
    }

    public void setStatus(LeaveStatus newStatus) {
        if (this.status == LeaveStatus.APPROVED || this.status == LeaveStatus.REJECTED) {
            System.out.println("Cannot change leave request status from " + this.status + " to " + newStatus + ".");
            return;
        }
        this.status = newStatus;
        System.out.println(employee.getName() + "'s leave request (" + dates + ") " + newStatus.toString().toLowerCase() + ". Status: " + newStatus + ".");
    }
}

class Manager {
    private String name;
    public Manager(String name) { this.name = name; }
    public void reviewRequest(LeaveRequest req, boolean approve) {
        req.setStatus(approve ? LeaveStatus.APPROVED : LeaveStatus.REJECTED);
    }
}

public class Q2 {
    public static void main(String[] args) {
        FullTimeEmployee john = new FullTimeEmployee("John");
        PartTimeEmployee jane = new PartTimeEmployee("Jane");
        Manager alice = new Manager("Alice");
        Manager bob = new Manager("Bob");

        // Sample Input Execution
        LeaveRequest req1 = new LeaveRequest(john, "Jan 1-5");
        alice.reviewRequest(req1, true);

        LeaveRequest req2 = new LeaveRequest(jane, "Feb 10-11");
        bob.reviewRequest(req2, false);

        req1.setStatus(LeaveStatus.PENDING);
    }
}