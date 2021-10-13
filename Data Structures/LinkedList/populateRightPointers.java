/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class populateRightPointers {
    public Node connect(Node root) {
        // base condition
        if(root == null || root.right == null || root.left == null) return root;
        
        // connecting the left and right
        root.left.next = root.right;
        
        //connecting the children nodes of two different branches
        if(root.next != null){
            root.right.next = root.next.left;
        }
        connect(root.left);
        connect(root.right);
        return root;
    }
    
}
