/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class mergeBinaryTrees {
    public TreeNode mergeTrees(TreeNode root1, TreeNode root2) {
    //return roots if the trees are null
        if( root1 == null) return root2;
        if( root2 == null) return root1;
    // merge at the root
        root1.val += root2.val;
    // recursive merge on the left child
        root1.left = mergeTrees(root1.left, root2.left );
    // recursive merge on the right child
        root1.right = mergeTrees(root1.right, root2.right);
        return root1;
    }
}