interface MembershipPlan {
    String getName();
    double calculateFee();
}

class MonthlyPlan implements MembershipPlan {
    public String getName() { return "Monthly"; }
    public double calculateFee() { return 1000.0; }
}

class QuarterlyPlan implements MembershipPlan {
    public String getName() { return "Quarterly"; }
    public double calculateFee() { return (1000.0 * 3) * 0.90; }
}

class AnnualPlan implements MembershipPlan {
    public String getName() { return "Annual"; }
    public double calculateFee() { return (1000.0 * 12) * 0.75; }
}

class Membership {
    private String memberName;
    private String status;

    public Membership(String memberName, MembershipPlan plan) {
        this.memberName = memberName;
        this.status = "Active";
        System.out.printf("%s membership created for %s. Fee: %.2f. Status: %s.\n", 
            plan.getName(), memberName, plan.calculateFee(), status);
    }

    public void checkIn() {
        if (status.equals("Active")) {
            System.out.println(memberName + " checked in successfully.");
        } else {
            System.out.println("Check-in denied: " + memberName + "'s membership is " + status + ".");
        }
    }

    public void freeze() {
        if (status.equals("Expired")) {
            System.out.println("Cannot freeze an Expired membership.");
        } else if (status.equals("Active")) {
            status = "Frozen";
            System.out.println(memberName + "'s membership frozen. Status: " + status + ".");
        }
    }

    public void expire() {
        status = "Expired";
        System.out.println(memberName + "'s membership expired. Status: " + status + ".");
    }
}

public class Q4 {
    public static void main(String[] args) {
        Membership ashaMem = new Membership("Asha", new QuarterlyPlan());
        Membership raviMem = new Membership("Ravi", new MonthlyPlan());

        ashaMem.checkIn();
        ashaMem.freeze();
        ashaMem.checkIn();
        
        raviMem.expire();
        raviMem.freeze();
    }
}