class Tree {
    Node root;

    Tree() {
    }

    void addNode(float value) {
        if(this.root == null) {
            root = new Node(value);
        } else {
            this.root.addNode(value);
        }
    }

    void prefix() {
        this.root.prefix(this.root);
    }

    boolean search(float value) {
        return this.root.search(this.root, value);
    }
}
