class Node {
    float value;
    Node left;
    Node right;

    Node(float value) {
        this.value = value;
    }

    void addNode(float value) {
        if (value < this.value) {
            if (this.left == null) {
                this.left = new Node(value);
                return;
            }
            this.left.addNode(value);
        }
        if (value > this.value) {
            if (this.right == null) {
                this.right = new Node(value);
                return;
            }
            this.right.addNode(value);
        }
    }

    void prefix(Node node) {
        if (node.left != null) prefix(node.left);
        System.out.println(node.value);
        if(node.right != null) prefix(node.right);
    }

    boolean search(Node node,float value) {
        if (value < node.value) {
            if (node.left != null) return search(node.left, value);
        } else if (value > node.value) {
            if(node.right != null) return search(node.right, value);
        } else return value == node.value;

        return false;
    }
}
