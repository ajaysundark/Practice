import java.util.*;

class BST <T extends Comparable<T>> {

    private Node<T> root;

    // BST insert operation
    public void insert(T data) {
        root = insert(root, data);
    }

    private Node<T> insert(Node<T> parent, T toInsert) {
        if(parent ==  null) return new Node<T> (toInsert);

        if(compare(parent.data, toInsert)==0) return parent;

        if(compare(parent.data, toInsert) < 0)
            parent.left = insert(parent.left, toInsert);
        else
            parent.right = insert(parent.right, toInsert);
        
        return parent;
    }

    // BST search operation
    public Node<T> search(T data) {
        return search(root, data);
    }

    private Node<T> search(Node<T> parent, T toSearch) {
        if (parent == null) return null;

        if (compare(parent.data, toSearch) == 0) return parent;
        else
            if(compare(parent.data, toSearch)<0)
                return search(parent.left, toSearch);
            else
                return search(parent.right, toSearch);
    }

    // BST delete operation
    public void delete (T data) {
        root = delete(root, data);
    }

    private Node<T> delete (Node<T> parent, T toDelete) {
        if(parent == null) return null;
        else if (compare(parent.left, toDelete) < 0)
            parent.left = delete(parent.left, toDelete);
        else if (compare(parent.right, toDelete) > 0)
            parent.right = delete(parent.right, toDelete);
        else {
            //right only subtree
            if(parent.left == null) return parent.right;
            //left only subtree
            if(parent.right == null) return parent.left;

            //full bush
            // find the right most node at left subtree to replace this node content
            parent.data = findRightMostData(parent.left);
            //delete that node now
            parent.left = delete(parent.left, parent.data);
        }
        return parent;
    }

    private T findRightMostData(Node<T> node) {
        while(node.right != null) node = node.right;
        return node.data;
    }


    // Node signature
    class Node<T> {
        public Node(T data) {this.data = data;}
        public Node(T data, Node<T> l, Node<T> r) {
            this.data = data;
            this.left = l;
            this.right = r;
        }

        T data;
        Node<T> left;
        Node<T> right;

        public String toString() {
            return data.toString();
        }
    }

    public String toString() {
        return this.inOrder().toString();
    }

    // Traversals
    // preorder
    public List<T> preOrder() {
        List<T> list = new ArrayList<>();
        recursivePreOrder(root, list);
        return list;
    }

    private void recursivePreOrder(Node<T> node, List<T> list) {
        if(node!=null) {
            list.add(node);
            recursivePreOrder(node.left, list);
            recursivePreOrder(node.right, list);
        }
    }

    // inorder
    public List<T> inOrder() {
        List<T> list = new ArrayList<>();
        recursiveInOrder(root, list);
        return list;
    }

    private void recursiveInOrder(Node<T> node, List<T> list) {
        if(node!=null) {
            recursivePreOrder(node.left, list);
            list.add(node);
            recursivePreOrder(node.right, list);
        }
    }

    // postorder
    public List<T> postOrder() {
        List<T> list = new ArrayList<>();
        recursivePostOrder(root, list);
        return list;
    }

    private void recursivePostOrder(Node<T> node, List<T> list) {
        if(node!=null) {
            recursivePostOrder(node.left, list);
            recursivePostOrder(node.right, list);
            list.add(node);
        }
    }

    public static void main (String[] args) {
        BST bst = new BST<Integer>();
        bst.insert(4);
        bst.insert(5);
        bst.insert(3);
        bst.insert(1);
        bst.insert(2);

        System.out.println(bst);
        bst.delete(3);
        System.out.println(bst);
        System.out.println("Do you have data = 2? : " + (bst.search(2)!=null ? "yes" : "no") );

    }
}
