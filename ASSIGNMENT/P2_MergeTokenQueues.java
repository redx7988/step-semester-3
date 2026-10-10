import java.util.Arrays;

public class P2_MergeTokenQueues {
    public static int[] mergeTokens(int[] counterA, int[] counterB) {
        int[] merged = new int[counterA.length + counterB.length];
        int i = 0, j = 0, k = 0;

        while (i < counterA.length && j < counterB.length) {
            if (counterA[i] <= counterB[j]) {
                merged[k++] = counterA[i++];
            } else {
                merged[k++] = counterB[j++];
            }
        }
        
        while (i < counterA.length) merged[k++] = counterA[i++];
        while (j < counterB.length) merged[k++] = counterB[j++];

        return merged;
    }

    public static void main(String[] args) {
        int[] counterA1 = {3, 8, 15, 20};
        int[] counterB1 = {5, 8, 12};
        System.out.println(Arrays.toString(mergeTokens(counterA1, counterB1))); // [3, 5, 8, 8, 12, 15, 20]

        int[] counterA2 = {};
        int[] counterB2 = {4, 9};
        System.out.println(Arrays.toString(mergeTokens(counterA2, counterB2))); // [4, 9]
    }
}