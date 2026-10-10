import java.util.Arrays;

public class Problem3 {
    public static boolean hasPairWithSum(int[] nums, int target) {
        // First, sort the array
        Arrays.sort(nums);
        
        // Use two pointers starting at both ends of the sorted array
        int left = 0;
        int right = nums.length - 1;
        
        while (left < right) {
            int currentSum = nums[left] + nums[right];
            
            if (currentSum == target) {
                return true; // Pair found
            } else if (currentSum < target) {
                left++; // We need a larger sum, move left pointer right
            } else {
                right--; // We need a smaller sum, move right pointer left
            }
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println(hasPairWithSum(new int[]{2, 7, 11, 15}, 9)); // Expected: true
        System.out.println(hasPairWithSum(new int[]{3, 4, 6}, 20));     // Expected: false
    }
}