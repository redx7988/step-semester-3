public class TrainCoachesBothWays {
    static class Node {
        String name;
        Node prev;
        Node next;

        public Node(String name) {
            this.name = name;
        }
    }

    private Node head;
    private Node tail;

    public void addLast(String name) {
        Node newNode = new Node(name);
        if (head == null) {
            head = tail = newNode;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
        }
    }

    public void remove(String name) {
        Node curr = head;
        while (curr != null) {
            if (curr.name.equals(name)) {
                if (curr.prev != null) {
                    curr.prev.next = curr.next;
                } else {
                    head = curr.next;
                }

                if (curr.next != null) {
                    curr.next.prev = curr.prev;
                } else {
                    tail = curr.prev;
                }
                return;
            }
            curr = curr.next;
        }
    }

    public void printForward() {
        System.out.print("Forward: ");
        Node curr = head;
        while (curr != null) {
            System.out.print(curr.name);
            if (curr.next != null) {
                System.out.print(" <-> ");
            }
            curr = curr.next;
        }
        System.out.println();
    }

    public void printBackward() {
        System.out.print("Backward: ");
        Node curr = tail;
        while (curr != null) {
            System.out.print(curr.name);
            if (curr.prev != null) {
                System.out.print(" <-> ");
            }
            curr = curr.prev;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        TrainCoachesBothWays train = new TrainCoachesBothWays();

        // Sample: coaches Engine, A1, B1, B2, Guard; remove B1
        String[] coaches = {"Engine", "A1", "B1", "B2", "Guard"};
        for (String coach : coaches) {
            train.addLast(coach);
        }

        train.remove("B1");

        // Expected Output:
        // Forward: Engine <-> A1 <-> B2 <-> Guard
        // Backward: Guard <-> B2 <-> A1 <-> Engine
        train.printForward();
        train.printBackward();
    }
}