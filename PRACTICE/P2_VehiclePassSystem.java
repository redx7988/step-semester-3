import java.util.HashMap;
import java.util.Map;

interface Chargeable {
    boolean isChargeable();
}

abstract class Vehicle {
    protected String passNumber;
    protected String ownerName;
    protected String type;
    protected int passFee;

    public Vehicle(String type, String passNumber, String ownerName, int passFee) {
        this.type = type;
        this.passNumber = passNumber;
        this.ownerName = ownerName;
        this.passFee = passFee;
        System.out.println(passNumber + " (" + type + ") pass fee " + passFee);
    }
    public String getPassNumber() { return passNumber; }
}

class Bike extends Vehicle implements Chargeable {
    public Bike(String passNumber, String ownerName) { super("Bike", passNumber, ownerName, 300); }
    public boolean isChargeable() { return false; }
}
class ECar extends Vehicle implements Chargeable {
    public ECar(String passNumber, String ownerName) { super("ECar", passNumber, ownerName, 1000); }
    public boolean isChargeable() { return true; }
}

public class P2_VehiclePassSystem {
    public static void main(String[] args) {
        Map<String, Vehicle> vehicles = new HashMap<>();

        Bike b1 = new Bike("KA01", "Asha");
        vehicles.put("KA01", b1);
        
        ECar c1 = new ECar("KA02", "Ravi");
        vehicles.put("KA02", c1);

        String[] chargeRequests = {"KA02", "KA01"};
        for (String req : chargeRequests) {
            Vehicle v = vehicles.get(req);
            if (v instanceof Chargeable && ((Chargeable) v).isChargeable()) {
                System.out.println(req + " charging bay allotted");
            } else {
                System.out.println(req + " rejected: charging unsupported");
            }
        }
    }
}