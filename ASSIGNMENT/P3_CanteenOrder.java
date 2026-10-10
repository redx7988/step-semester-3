import java.util.HashMap;
import java.util.Map;

class PopularOrder {
    String item;
    int count;
    public PopularOrder(String item, int count) {
        this.item = item;
        this.count = count;
    }
}

public class P3_CanteenOrder {
    public static PopularOrder mostPopular(String[] orders) {
        Map<String, Integer> counts = new HashMap<>();
        for (String order : orders) {
            counts.put(order, counts.getOrDefault(order, 0) + 1);
        }

        int maxCount = 0;
        String bestItem = "";

        // Iterate original list to break ties by first appearance
        for (String order : orders) {
            int count = counts.get(order);
            if (count > maxCount) {
                maxCount = count;
                bestItem = order;
            }
        }
        return new PopularOrder(bestItem, maxCount);
    }

    public static void main(String[] args) {
        String[] orders1 = {"dosa", "idli", "vada", "dosa", "idli", "dosa", "tea"};
        PopularOrder res1 = mostPopular(orders1);
        System.out.println("(\"" + res1.item + "\", " + res1.count + ")"); // ("dosa", 3)
        
        String[] orders2 = {"tea", "coffee", "coffee", "tea"};
        PopularOrder res2 = mostPopular(orders2);
        System.out.println("(\"" + res2.item + "\", " + res2.count + ")"); // ("tea", 2)
    }
}