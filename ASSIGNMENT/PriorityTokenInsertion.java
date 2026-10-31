public class PriorityTokenInsertion {
    static class Node {
        int data;
        Node next;

        public Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    private Node head;

    public void addFirst(int token) {
        Node newNode = new Node(token);
        newNode.next = head;
        head = newNode;
    }

    public void addLast(int token) {
        Node newNode = new Node(token);
        if (head == null) {
            head = newNode;
            return;
        }
        Node curr = head;
        while (curr.next != null) {
            curr = curr.next;
        }
        curr.next = newNode;
    }

    public void insertAt(int index, int token) {
        if (index <= 0 || head == null) {
            addFirst(token);
            return;
        }
        Node curr = head;
        for (int i = 0; i < index - 1 && curr.next != null; i++) {
            curr = curr.next;
        }
        Node newNode = new Node(token);
        newNode.next = curr.next;
        curr.next = newNode;
    }

    public void printList() {
        Node curr = head;
        while (curr != null) {
            System.out.print(curr.data + " -> ");
            curr = curr.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        PriorityTokenInsertion list = new PriorityTokenInsertion();

        // Starting list: 101 -> 102 -> 103
        list.addLast(101);
        list.addLast(102);
        list.addLast(103);

        // Operations from Sample: addFirst(100), addLast(104), insertAt(2, 150)
        list.addFirst(100);
        list.add