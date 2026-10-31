public class ReverseTheQueue {
    static class Node {
        int data;
        Node next;

        public Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    public static Node reverse(Node head) {
        Node prev = null;
        Node curr = head;
        while (curr != null) {
            Node next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    public static Node buildList(int[] arr) {
        Node head = null, tail = null;
        for (int val : arr) {
            Node newNode = new Node(val);
            if (head == null) {
                head = tail = newNode;
            } else {
                tail.next = newNode;
                tail = newNode;
            }
        }
        return head;
    }

    public static void printList(Node head) {
        Node curr = head;
        while (curr != null) {
            System.out.print(curr.data + " -> ");
            curr = curr.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        // Sample 1: queue = 1 -> 2 -> 3 -> 4
        Node head1 = buildList(new int[]{1, 2, 3, 4});
        head1 = reverse(head1);
        printList(head1); // Expected Output: 4 -> 3 -> 2 -> 1 -> null

        // Sample 2: queue = 9
        Node head2 = buildList(new int[]{9});
        head2 = reverse(head2);
        printList(head2); // Expected Output: 9 -> null
    }
}