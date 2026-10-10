import java.util.ArrayList;
import java.util.List;

abstract class Room {
    protected String id;
    public Room(String id) { this.id = id; }
    public abstract double calculatePrice(int days);
    public String getId() { return id; }
}

class StandardRoom extends Room {
    public StandardRoom(String id) { super(id); }
    public double calculatePrice(int days) { return days * 100.0; } // Assuming $100/day
}

class DeluxeRoom extends Room {
    public DeluxeRoom(String id) { super(id); }
    public double calculatePrice(int days) { return days * 200.0; } // Assuming $200/day
}

class Reservation {
    private Room room;
    private String customer;
    private int start, end;
    private String dateString;

    public Reservation(Room room, String customer, int start, int end, String dateString) {
        this.room = room;
        this.customer = customer;
        this.start = start;
        this.end = end;
        this.dateString = dateString;
    }
    public Room getRoom() { return room; }
    public boolean overlaps(int s, int e) { return (s <= end && e >= start); }
    public String getDateString() { return dateString; }
}

class BookingSystem {
    private List<Reservation> reservations = new ArrayList<>();

    public boolean isAvailable(Room room, int start, int end) {
        for (Reservation r : reservations) {
            if (r.getRoom().getId().equals(room.getId()) && r.overlaps(start, end)) return false;
        }
        return true;
    }

    public void checkAvailability(Room room, int start, int end, String dateString) {
        if (isAvailable(room, start, end)) {
            System.out.println(room.getId() + " is available from " + dateString + ".");
        } else {
            System.out.println(room.getId() + " is not available from " + dateString + ".");
        }
    }

    public void reserve(Room room, String customer, int start, int end, String dateString) {
        if (isAvailable(room, start, end)) {
            reservations.add(new Reservation(room, customer, start, end, dateString));
            double price = room.calculatePrice(end - start + 1);
            System.out.println("Reservation confirmed for " + customer + ", " + room.getId() + " (" + dateString + "). Price: $" + price + ".");
        } else {
            System.out.println(room.getId() + " is not available from " + dateString + ".");
        }
    }
    
    public void cancel(Room room, String customer, String dateString) {
        boolean removed = reservations.removeIf(r -> r.getRoom().getId().equals(room.getId()) && r.getDateString().equals(dateString));
        if (removed) {
            System.out.println("Reservation for " + customer + ", " + room.getId() + " (" + dateString + ") cancelled successfully.");
        }
    }
}

public class Q4 {
    public static void main(String[] args) {
        BookingSystem system = new BookingSystem();
        Room std101 = new StandardRoom("Standard Room 101");
        Room dlx201 = new DeluxeRoom("Deluxe Room 201");

        // Representing dates as integers (1 to 365) for overlap logic simplification
        // Sample Input Execution
        system.checkAvailability(std101, 1, 5, "Jan 1 to Jan 5");
        system.reserve(std101, "Customer A", 1, 5, "Jan 1-5");
        system.reserve(std101, "Customer B", 3, 7, "Jan 3 to Jan 7");
        system.cancel(std101, "Customer A", "Jan 1-5");
        system.reserve(dlx201, "Customer C", 41, 43, "Feb 10-12"); // Feb 10 is 41st day
    }
}