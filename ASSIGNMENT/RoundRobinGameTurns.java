public class RoundRobinGameTurns {
    static class Node {
        String name;
        Node next;

        public Node(String name) {
            this.name = name;
        }
    }

    private Node tail;

    public void addLast(String name) {
        Node newNode = new Node(name);
        if (tail == null) {
            tail = newNode;
            tail.next = tail; // Points to itself in a 1-node circular list
        } else {
            newNode.next = tail.next; // New node points to head (tail.next)
            tail.next = newNode;      // Old tail points to new node
            tail = newNode;           // Update tail to new node
        }
    }

    public void printTurns(int turns) {
        if (tail == null || turns <= 0) {
            return;
        }
        Node curr = tail.next; // Head is tail.next
        for (int i = 0; i < turns; i++) {
            System.out.print(curr.name + (i < turns - 1 ? " " : ""));
            curr = curr.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        RoundRobinGameTurns game = new RoundRobinGameTurns();

        // Sample: players Asha, Ravi, Neha; turns = 7
        game.addLast("Asha");
        game.addLast("Ravi");
        game.addLast("Neha");

        // Expected Output: Asha Ravi Neha Asha Ravi Neha Asha
        game.printTurns(7);
    }
}