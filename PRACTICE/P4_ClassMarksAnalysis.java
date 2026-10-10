public class P4_ClassMarksAnalysis {
    public static void main(String[] args) {
        String[] names = {"Asha", "Ravi", "Neha"};
        int[][] grid = {
            {78, 85, 90},
            {88, 92, 79},
            {65, 70, 95}
        };

        int numStudents = names.length;
        int numSubjects = grid[0].length;
        
        int maxTotal = -1;
        String topperName = "";
        System.out.print("Totals ");
        
        for (int i = 0; i < numStudents; i++) {
            int currentTotal = 0;
            for (int j = 0; j < numSubjects; j++) {
                currentTotal += grid[i][j];
            }
            System.out.print(names[i] + " " + currentTotal + (i < numStudents - 1 ? ", " : "\n"));
            
            if (currentTotal > maxTotal) {
                maxTotal = currentTotal;
                topperName = names[i];
            }
        }
        
        System.out.print("averages ");
        for (int j = 0; j < numSubjects; j++) {
            double sum = 0;
            for (int i = 0; i < numStudents; i++) {
                sum += grid[i][j];
            }
            System.out.printf("%.2f%s", sum / numStudents, (j < numSubjects - 1 ? ", " : "\n"));
        }
        
        System.out.println("topper " + topperName + " (" + maxTotal + ")");
    }
}