public class P4_HotWeatherAlert {
    public static int countAlerts(int[] readings, int k, int threshold) {
        if (readings.length < k) return 0;

        int count = 0;
        int currentSum = 0;
        int targetSum = k * threshold; // Compare against k * threshold to avoid division

        for (int i = 0; i < k; i++) {
            currentSum += readings[i];
        }
        if (currentSum >= targetSum) count++;

        for (int i = k; i < readings.length; i++) {
            currentSum += readings[i];         // Add new reading entering window
            currentSum -= readings[i - k];     // Subtract reading leaving window
            
            if (currentSum >= targetSum) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int[] readings = {2, 2, 2, 5, 5, 5, 8};
        System.out.println(countAlerts(readings, 3, 4)); // Expected: 3
    }
}