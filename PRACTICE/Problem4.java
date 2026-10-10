import java.util.HashSet;
import java.util.Set;

public class Problem4 {
    public static boolean hasPairWithSum(int[] nums, int target) {
        // Data structure to quickly check for complements
        Set<Integer> seenNumbers = new HashSet<>();
        
        for (int num : nums) {
            int complement = target - num;
            
            // If the complement is already in the set, we found our pair
            if (seenNumbers.contains(complement)) {
                return true;
            }
            // Otherwise, add the current number to the set
            seenNumbers.add(num);
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println(hasPairWithSum(new int[]{2, 7, 11, 15}, 9)); // Expected: true
        System.out.println(hasPairWithSum(new int[]{3, 4, 6}, 20));     // Expected: false
    }
}