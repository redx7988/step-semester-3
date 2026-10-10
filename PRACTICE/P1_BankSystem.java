import java.util.HashMap;
import java.util.Map;

abstract class BankAccount {
    protected String id;
    protected double balance;

    public BankAccount(String id, double initialBalance) {
        this.id = id;
        this.balance = initialBalance;
    }

    public abstract void withdraw(double amount);
}

class SavingsAccount extends BankAccount {
    public SavingsAccount(String id, double initialBalance) {
        super(id, initialBalance);
    }

    @Override
    public void withdraw(double amount) {
        if (balance - amount < 1000) {
            System.out.println(id + " rejected: minimum balance 1000");
        } else {
            balance -= amount;
            System.out.println(id + " balance " + (int)balance);
        }
    }
}

class CurrentAccount extends BankAccount {
    public CurrentAccount(String id, double initialBalance) {
        super(id, initialBalance);
    }

    @Override
    public void withdraw(double amount) {
        if (balance - amount < -5000) {
            System.out.println(id + " rejected: overdraft limit 5000");
        } else {
            balance -= amount;
            System.out.println(id + " balance " + (int)balance);
        }
    }
}

public class P1_BankSystem {
    public static void main(String[] args) {
        Map<String, BankAccount> accounts = new HashMap<>();
        
        accounts.put("S1", new SavingsAccount("S1", 5000));
        accounts.get("S1").withdraw(4500);
        
        accounts.put("C1", new CurrentAccount("C1", 2000));
        accounts.get("C1").withdraw(6000);
        
        accounts.get("S1").withdraw(3000);
        accounts.get("C1").withdraw(2000);
    }
}