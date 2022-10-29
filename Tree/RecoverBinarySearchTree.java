import java.io.*;
import java.lang.*;
import java.util.*;

class RecoverBST
{
   static class TreeNode
   {
        TreeNode left;
        TreeNode right;
        int val;
         
        public TreeNode(int x)
        {
            this.val = x;
        }
   }
 
    TreeNode firstStartPoint, lastEndPoint;
    TreeNode prevNode;
 
    public void findSegments(TreeNode root) 
    {
        if (root == null) return;
         
        findSegments (root.left);
         
        if (prevNode != null) 
        {
            if (prevNode.val   >  root.val) 
            {
                if (firstStartPoint == null)
                {
                    firstStartPoint = prevNode;
                }
                lastEndPoint = root;
             }
        }
        prevNode = root;
         
        findSegments (root.right);   
   }
     
   public void recoverTree(TreeNode root) 
   {
       findSegments(root);
       int x = firstStartPoint.val;
       firstStartPoint.val = lastEndPoint.val;
       lastEndPoint.val = x;
   }
 
   public void printInOrder(TreeNode root)
   {
       if (root == null) return;
            
       printInOrder(root.left);
       System.out.println(root.val);
       printInOrder(root.right);
   }
    
   public static void main(String[] args)
   {
       TreeNode root = new TreeNode(10);
       TreeNode n1   = new TreeNode(15);
       TreeNode n2   = new TreeNode(5);
       TreeNode n3   = new TreeNode(4);
       TreeNode n4   = new TreeNode(7);
       TreeNode n5   = new TreeNode(14);
       TreeNode n6   = new TreeNode(17);
        
       root.left  = n1;
       root.right = n2;
        
       n1.left  = n3;
       n1.right = n4;
        
       n2.left  = n5;
       n2.right = n6;
        
       RecoverBST solution = new RecoverBST();
        
       System.out.println("In-Order traversal of BST before recovery: ");
       solution.printInOrder(root);
 
       solution.recoverTree(root);
        
       System.out.println("In-Order traversal of BST after recovery: ");
       solution.printInOrder(root);
   }
}
