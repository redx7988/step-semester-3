import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

abstract class Seat {
    protected String id;
    public Seat(String id) { this.id = id; }
    public String getId() { return id; }
    public abstract double getPrice();
}

class RegularSeat extends Seat {
    public RegularSeat(String id) { super(id); }
    public double getPrice() { return 150.0; }
}

class PremiumSeat extends Seat {
    public PremiumSeat(String id) { super(id); }
    public double getPrice() { return 250.0; }
}

class ReclinerSeat extends Seat {
    public ReclinerSeat(String id) { super(id); }
    public double getPrice() { return 400.0; }
}

class Booking {
    private String customer;
    private List<Seat> seats;
    private double total;

    public Booking(String customer, List<Seat> seats) {
        this.customer = customer;
        this.seats = seats;
        for (Seat s : seats) this.total += s.getPrice();
    }
    public String getCustomer() { return customer; }
    public List<Seat> getSeats() { return seats; }
    public double getTotal() { return total; }
}

class Show {
    private Set<String> bookedSeatIds = new HashSet<>();
    private List<Booking> bookings = new ArrayList<>();

    public void book(String customer, List<Seat> seatsToBook) {
        if (seatsToBook.size() > 6) {
            System.out.println("Cannot book more than 6 seats.");
            return;
        }
        for (Seat s : seatsToBook) {
            if (bookedSeatIds.contains(s.getId())) {
                System.out.println("Seat " + s.getId() + " is already booked for this show.");
                return;
            }
        }
        
        Booking b = new Booking(customer, seatsToBook);
        bookings.add(b);
        for (Seat s : seatsToBook) bookedSeatIds.add(s.getId());
        
        List<String> seatNames = new ArrayList<>();
        for(Seat s : seatsToBook) seatNames.add(s.getId());
        
        System.out.printf("Booking confirmed for %s: %s. Total: %.2f.\n", 
            customer, String.join(", ", seatNames), b.getTotal());
    }

    public void cancel(String customer) {
        Booking toRemove = null;
        for (Booking b : bookings) {
            if (b.getCustomer().equals(customer)) {
                toRemove = b;
                break;
            }
        }
        if (toRemove != null) {
            List<String> seatNames = new ArrayList<>();
            for (Seat s : toRemove.getSeats()) {
                bookedSeatIds.remove(s.getId());
                seatNames.add(s.getId());
            }
            bookings.remove(toRemove);
            System.out.println(customer + "'s booking cancelled. Seats " + String.join(", ", seatNames) + " released.");
        }
    }
}

public class Q3 {
    public static void main(String[] args) {
        Show show = new Show();
        
        Seat a1 = new RegularSeat("A1");
        Seat a2 = new RegularSeat("A2");
        Seat f5 = new PremiumSeat("F5");
        Seat r1 = new ReclinerSeat("R1");

        show.book("Asha", Arrays.asList(a1, a2, f5));
        show.book("Ravi", Arrays.asList(a2));
        show.book("Ravi", Arrays.asList(r1));
        
        show.cancel("Asha");
        show.book("Neha", Arrays.asList(a2));
    }
}