import java.util.ArrayList;
import java.util.List;

interface PaymentMethod {
    boolean processPayment(double amount);
    String getName();
}

class CreditCardPayment implements PaymentMethod {
    public boolean processPayment(double amount) { return true; } // Simulate success
    public String getName() { return "Credit Card"; }
}

class PayPalPayment implements PaymentMethod {
    public boolean processPayment(double amount) { return false; } // Simulate failure
    public String getName() { return "PayPal"; }
}

class Order {
    private String id;
    private List<String> products = new ArrayList<>();
    private String status = "Pending";

    public Order(String id) {
        this.id = id;
        System.out.println("Order created for " + id + ".");
    }

    public void addProduct(String product, int qty) { 
        for(int i=0; i<qty; i++) {
            products.add(product); 
        }
    }

    public void pay(PaymentMethod method) {
        if (products.isEmpty()) {
            System.out.println("Cannot process payment for an empty order.");
            return;
        }
        System.out.println("Payment initiated via " + method.getName() + " for Order " + id + ".");
        
        // Simulating a fixed total amount for demonstration
        if (method.processPayment(100.0)) {
            status = "Paid";
            System.out.println("Payment for Order " + id + " successful. Order status: " + status + ".");
        } else {
            System.out.println("Payment for Order " + id + " failed. Order status: " + status + ".");
        }
    }
}

public class Q5 {
    public static void main(String[] args) {
        // Customer X
        Order orderX = new Order("Customer X");
        orderX.addProduct("Product A", 2);
        orderX.addProduct("Product B", 1);
        orderX.pay(new CreditCardPayment());

        // Customer Y
        Order orderY = new Order("Customer Y");
        orderY.pay(new CreditCardPayment());

        // Customer Z
        Order orderZ = new Order("Customer Z");
        orderZ.addProduct("Product C", 1);
        orderZ.pay(new PayPalPayment());
    }
}