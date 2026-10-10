abstract class WashType {
    public abstract String getName();
    public abstract int getDuration();
    public abstract double getCharge();
}

class QuickWash extends WashType {
    public String getName() { return "Quick"; }
    public int getDuration() { return 30; }
    public double getCharge() { return 20.00; }
}

class NormalWash extends WashType {
    public String getName() { return "Normal"; }
    public int getDuration() { return 45; }
    public double getCharge() { return 30.00; }
}

class HeavyWash extends WashType {
    public String getName() { return "Heavy"; }
    public int getDuration() { return 60; }
    public double getCharge() { return 45.00; }
}

class Student {
    private String name;
    public Student(String name) { this.name = name; }
    public String getName() { return name; }
}

class WashingMachine {
    private String id;
    private boolean isFree = true;
    
    public WashingMachine(String id) { this.id = id; }
    public String getId() { return id; }
    public boolean isFree() { return isFree; }
    
    public void setFree(boolean status) { this.isFree = status; }
}

class LaundrySystem {
    public void startWash(Student s, WashingMachine m, WashType w) {
        if (!m.isFree()) {
            System.out.println("Machine " + m.getId() + " is currently busy.");
            return;
        }
        m.setFree(false);
        System.out.printf("%s wash started on %s for %s (%d min). Charge: %.2f.\n", 
            w.getName(), m.getId(), s.getName(), w.getDuration(), w.getCharge());
    }

    public void completeWash(WashingMachine m) {
        m.setFree(true);
        System.out.println(m.getId() + " cycle completed. " + m.getId() + " is now free.");
    }
}

public class Q1 {
    public static void main(String[] args) {
        LaundrySystem system = new LaundrySystem();
        WashingMachine m1 = new WashingMachine("M1");
        WashingMachine m2 = new WashingMachine("M2");
        
        Student asha = new Student("Asha");
        Student ravi = new Student("Ravi");
        Student neha = new Student("Neha");

        system.startWash(asha, m1, new QuickWash());
        system.startWash(ravi, m1, new HeavyWash());
        system.startWash(ravi, m2, new HeavyWash());
        system.completeWash(m1);
        system.startWash(neha, m1, new NormalWash());
    }
}