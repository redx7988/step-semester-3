import java.util.Arrays;

public class LibraryMemberFines {
    private int[] fineHistory = new int[10]; // Up to 10 fines per membership[cite: 1]
    private int fineCount = 0;

    protected void chargeFine(int amount) {
        if (fineCount < 10 && amount > 0) {
            fineHistory[fineCount++] = amount;
        }
    }

    // Returns a defensive copy to prevent outside tampering[cite: 1]
    public int[] getFineHistory() {
        return Arrays.copyOf(fineHistory, fineCount);
    }

    public int getTotalFine() {
        int total = 0;
        for (int i = 0; i < fineCount; i++) {
            total += fineHistory[i];
        }
        return total;
    }
}

class StudentMemberFines extends LibraryMemberFines {
    // Halves the fine amount and delegates logic to the parent class[cite: 1]
    @Override
    protected void chargeFine(int amount) {
        super.chargeFine(amount / 2);
    }
}