//Inorder Traversal of Binary Tree using Morris Traversal
import java.util.Random;
public class MorrisTraversal 
{
    static class Node{          
        int data;               
        Node left,right;        
        Node(int d){            
           this.data=d;
           this.left=null;
           this.right=null;
        }
    }
    public static void printInorder(Node root){
         if(root==null){             
            return;   
         }
         Node curr=root;             
         Node prev;                  
         while(curr!=null){           
            if(curr.left==null){                            
               System.out.print(curr.data+" ");             
               curr=curr.right;                            
            }else{
               prev=curr.left;
               while(prev.right!=null && prev.right!=curr){   
                    prev=prev.right;
               }
               if(prev.right==null){
                  prev.right=curr;            
                  curr = curr.left;           
               }else{
                  prev.right=null;           
                  System.out.print(curr.data+" ");
                  curr=curr.right;
               }
            }   
         }
    }
    public static void main(String args[]){
       Node root = new Node(1);
       root.left = new Node(2);
       root.right = new Node(3);
       root.left.left = new Node(4);
       root.left.right = new Node(5);
       root.right.left = new Node(6);
       root.right.right = new Node(7);
       printInorder(root);
    }
}
