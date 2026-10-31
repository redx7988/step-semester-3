public class CancelledOrdersCleanup {
    static class Node {
        int data;
        Node next;

        public Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    public static Node removeAll(Node head, int code) {
        // First remove matching nodes from the front by moving head
        while (head != null && head.data == code) {
            head = head.next;
        }

        // Walk with a previous reference and skip matching nodes
        Node prev = head;
        while (prev != null && prev.next != null) {
            if (prev.next.data == code) {
                prev.next = prev.next.next;
            } else {
                prev = prev.next;
            }
        }
        return head;
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
        // Sample 1: orders = 5 -> 3 -> 5 -> 8 -> 5, code = 5
        Node head1 = buildList(new int[]{5, 3, 5, 8, 5});
        head1 = removeAll(head1, 5);
        printList(head1); // Expected Output: 3 -> 8 -> null

        // Sample 2: orders = 5 -> 5 -> 5, code = 5
        Node head2 = buildList(new int[]{5, 5, 5});
        head2 = removeAll(head2, 5);
        printList(head2); // Expected Output: null
    }
}