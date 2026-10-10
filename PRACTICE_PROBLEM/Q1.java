abstract class Vehicle {
    protected String id;
    protected boolean isAvailable = true;
    public Vehicle(String id) { this.id = id; }
    public abstract double calculateRentalCharge(int days);
    public boolean isAvailable() { return isAvailable; }
    public void setAvailable(boolean available) { isAvailable = available; }
    public String getId() { return id; }
}

class Sedan extends Vehicle {
    public Sedan(String id) { super(id); }
    public double calculateRentalCharge(int days) { return days * 50.0; } // Assuming $50/day
}

class SUV extends Vehicle {
    public SUV(String id) { super(id); }
    public double calculateRentalCharge(int days) { return days * 80.0; } // Assuming $80/day
}

class Customer {
    private String name;
    public Customer(String name) { this.name = name; }
    public String getName() { return name; }
}

class RentalSystem {
    public void rentVehicle(Customer c, Vehicle v, int days) {
        if (!v.isAvailable()) {
            System.out.println(v.getId() + " is currently unavailable.");
            return;
        }
        v.setAvailable(false);
        System.out.println(v.getId() + " rented successfully by " + c.getName() + ". Rental charge: $" + v.calculateRentalCharge(days) + ".");
    }
    public void returnVehicle(Customer c, Vehicle v) {
        v.setAvailable(true);
        System.out.println(v.getId() + " returned by " + c.getName() + ".");
    }
}

public class Q1 {
    public static void main(String[] args) {
        RentalSystem system = new RentalSystem();
        Vehicle sedanA = new Sedan("Sedan A");
        Vehicle suvB = new SUV("SUV B");
        
        Customer customer1 = new Customer("Customer 1");
        Customer customer2 = new Customer("Customer 2");
        Customer customer3 = new Customer("Customer 3");

        // Sample Input Execution
        system.rentVehicle(customer1, sedanA, 3);
        system.rentVehicle(customer2, sedanA, 2);
        system.returnVehicle(customer1, sedanA);
        system.rentVehicle(customer3, suvB, 5);
    }
}