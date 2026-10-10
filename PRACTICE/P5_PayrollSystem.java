import java.util.ArrayList;
import java.util.List;

abstract class Staff {
    protected String name;
    protected String type;
    public Staff(String name, String type) { this.name = name; this.type = type; }
    public abstract int calculatePay();
    public String getName() { return name; }
    public String getPayslip() {
        return "Payslip [name=" + name + ", type=" + type + ", pay=" + calculatePay() + "]";
    }
}

class FullTime extends Staff {
    private int salary;
    public FullTime(String name, int salary) { super(name, "FullTime"); this.salary = salary; }
    public int calculatePay() { return salary; }
}

class PartTime extends Staff {
    private int hours, rate;
    public PartTime(String name, int hours, int rate) { super(name, "PartTime"); this.hours = hours; this.rate = rate; }
    public int calculatePay() { return hours * rate; }
}

class Intern extends Staff {
    private int stipend;
    public Intern(String name, int stipend) { super(name, "Intern"); this.stipend = stipend; }
    public int calculatePay() { return stipend; }
}

public class P5_PayrollSystem {
    public static void main(String[] args) {
        List<Staff> staffList = new ArrayList<>();
        staffList.add(new FullTime("Asha", 50000));
        staffList.add(new PartTime("Ravi", 80, 300));
        staffList.add(new Intern("Neha", 15000));

        int totalPay = 0;
        int maxPay = -1;
        String topEarner = "";

        for (Staff s : staffList) {
            System.out.println(s.getPayslip());
            int pay = s.calculatePay();
            totalPay += pay;
            if (pay > maxPay) {
                maxPay = pay;
                topEarner = s.getName();
            }
        }
        System.out.println("Total " + totalPay);
        System.out.println("top earner " + topEarner);
    }
}