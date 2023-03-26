import java.util.*;

/**
 * BinaryTree
 */
public class BinaryTree {
static class Node{
int data;
Node left;
Node right;
Node(int data){
	this.data=data;
	this.left=null;
     this.right=null;
}
}
static class BuildTree_From_PreOrder{
static int idx=-1;
public static Node buildTree(int nodes[] ){
	idx++;
	if(nodes[idx]==-1){
		return null;
	}
	Node newNode= new Node(nodes[idx]);
	newNode.left=   buildTree(nodes);
	newNode.right=  buildTree(nodes);
	return newNode;

}
/*-----------------------------------------------------------
Q.s1-Binary tree ke dfs traversal-preorder,inorder,postorder
*/
//preorder
public static void preOrder(Node root){
if(root==null){
	return;
}
System.out.print(root.data+" ");
 preOrder(root.left);
  preOrder(root.right);
}
//postorder
public static void postOrder(Node root){
	if(root==null){
		return;
	}
	postOrder(root.left);
	postOrder(root.right);
	System.out.print(root.data + " ");
}
//inorder
public static void inOrder(Node root){
if(root ==null){
	return;
}
    inOrder(root.left);
System.out.print(root.data + " ");
inOrder(root.right);
}
//_________________________________________________________________________
/*-----------------------------------------------------------
 Q.s2 Binary tree ka BFS traversal
 or Level order travesal
 Approach -FIFO , Queue ds 
  -use null to track next line
  -inital add  first time root and null in q
  - now remove the node from q , print it and add it's child node in q
  -when currNode get null, {if(!q empty)} then push[at end] 
  -else print currnode and add it's right child ,and left child
*/
public static void LevelOrderTraversal(Node root){
	Queue<Node>q = new LinkedList<>();
	q.add(root);
	q.add(null);
	while(!q.isEmpty()){
		Node currNode=q.remove(); //removed Node
		
		if(currNode==null){
			// case 1 q empty
		if(q.isEmpty()){
			break;
		}
		//case 2 get null in q
		else{
			System.out.println("");
			q.add(null);
		}
	 }
	 else{
	   System.out.print(currNode.data +" ");
	   if(currNode.left!=null){
		q.add(currNode.left);
	   }
	   	if (currNode.right != null) {
			q.add(currNode.right);
		}
	 }

	}
}
//________________________________________________________________________
 /* ---------------------------------------------------------
 * q.s 3 Count numOf nodes in Binary tree
 * Recursive approach -
 * count of root= lscount(root.left)+rscount(root.right)+1
 */
public static int countOfNodes(Node root){
	if(root==null){
		return 0;
	}
	int lscount=countOfNodes(root.left);
	int rscount=countOfNodes(root.right);

	return lscount+rscount+1;
}
//___________________________________________________________________________
/*-------------------------------------------------------------
 * q.s4 - Toatal -Sum of all nodes of binary tree-
 * Recursive Approach-
 * sum of node = lsubtreeSum+ rsubtreeSum +root.data
 */
public static int sumOfNodes(Node root){
	if(root==null){
		return 0;
	}
	int Lsum=sumOfNodes(root.left);
	int Rsum = sumOfNodes(root.right);
	int tsum=Lsum+Rsum+root.data;
	return tsum;
}
// ___________________________________________________________________________
/*-------------------------------------------------------------
 * q.s5 - hight of binary tree-
 * hight== diff of distance between root and deepest node
 * Recursive Approach-
 *  h=1+max(lshight,rshight)
 */
public static int hight(Node root){
	if(root==null){
		return 0;
	}
	int LShight=hight(root.left);
	int RShight=hight(root.right);
	int hightOftree=1+Math.max(LShight,RShight);
	return hightOftree;

}
//_________________________________________________________________________________
/*--------------------------------------------------------------------------
 * Q.s-6 Diameter of tree-
 * -longest path of tree which contain maximum node.
 * Approach -1 O(n^2)
 * There can be 3 case-
 * Case1: diameter lie in left sub tree
 *           1
 *          / \
 *         2   3
 *        / \
 *       4   5
 *      /     \
 *     7       6
 *    /         \
 *   11          8
 *                \
 *                 9
 *  (diameter -8 path[11-7-4-2-5-6-8-9] cantain 8 node)
 * Case2: diameter lie in the right subtree
              1
             / \
			2   3
               / \
              4   5
			 /     \
			7       6
		   /         \     
		  8           9
		               \
					   11
          (diameter -8 path[8-7-4-3-5-6-9-11])

Case-3 diameter go through root
           1
          / \
 *       2   3
 *      /     \
 *     4       5
 *    (diameter -5 path[4-2-1-3-5])
 *   we calculate for each node -
 *    -Left subtree diameter-Ls
 *    -Right subtree diameter -RS
 *    -diameter go through root-dr= Left hight(LH) + right hight(RH) +1
 * now diameter of tree -myDia= max(LS,RS,dr)
 * In Approach 1 we use above hight(Node root) function to calculate hight
 */
public static int diameter1(Node root){
	if(root==null){
		return 0;
	}
	int LS=diameter1(root.left);
	int RS = diameter1(root.right);
	int dr= hight(root.left)+hight(root.right)+1;
	int mydiam= Math.max(Math.max(LS,RS),dr);
	return mydiam;

}
/*-------------Approach-2 Liner time complexity O(n)------------
In this approach we didn't calculate hight by function externally
  but we calculate hight with in it 
 so for that we  create an TreeInfo class which store the diameter and hight of each node
*/
static class TreeInfo{
	int diam;
	int hight;
	TreeInfo(int diam, int hight){
		this.diam=diam;
		this.hight=hight;
	}
	// to create object that store both value
}
public static TreeInfo diameter2(Node root){
	if(root==null){
		return new TreeInfo(0, 0);
	}
	TreeInfo left=diameter2(root.left);
	TreeInfo right=diameter2(root.right);
	int myHight=Math.max(left.hight,right.hight)+1;
	int LS=left.diam;
	int RS=right.diam;
	int dr=left.hight+right.hight+1;
	int myDia=Math.max(Math.max(LS,RS),dr);
	return new TreeInfo(myDia, myHight);
}
 
 //______________________________________________________________________________________
 	/*-------------------------------------------------------------------------------
	q.s 7 sum of kth level nodes.
	 * Approach-
	 we do level order traversal while(c<= till kth level)
	 -and use counter c to track level ( if we initialize c=0,then k=k-1)
	 -when c==k
	 add the node.data in our sum, 
	 and print that sum
	
	 */
  	public static void KthSum(Node root,int k) {
		k=k-1; //0 based index
          if(root==null){
			return;
		  }
		  int c=0;
		  int sum=0;
		Queue<Node> q = new LinkedList<>();
		q.add(root);
		q.add(null);
		while (!q.isEmpty() && c<=k) {
			Node currNode = q.remove(); // removed Node

			if (currNode == null) {
				// case 1 q empty
				if (q.isEmpty()) {

					break;
				}
				// case 2 get null in q
				else {
					//go to next level
                    c++;
					q.add(null);
				}
			}
			 else {
				if(c==k){
					sum+=currNode.data;
				}
				
				if (currNode.left != null) {
					q.add(currNode.left);
				}
				if (currNode.right != null) {
					q.add(currNode.right);
				}
			}

			}

			System.out.println("sum of kth level "+sum);
	}
	//_______________________________________________________________________________
	/*
	 * In this file I added 7 q.s in which Binary Tree data structure based questions are explained as above.
	 * 
	 * 
	 * 
	 * 
	 */
}
public static void main(String[] args) {
	BuildTree_From_PreOrder tree = new BuildTree_From_PreOrder();
   int nodes[] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
   Node root=tree.buildTree(nodes);
   System.out.println(root.data);
   //q.s1 --------------------------------------------

   System.out.println("PreOrder traversal");
   tree.preOrder(root);
   System.out.println("");
   // 

   	System.out.println("PostOrder traversal");
   tree.postOrder(root);
	System.out.println("");
	//

   	System.out.println("Inorder traversal");
       tree.inOrder(root);
	   	System.out.println("");
    //

   	System.out.println("Level order traversal");
	tree.LevelOrderTraversal(root);
	System.out.println("");
	//
	System.out.println("total Count of nodes in Binary tree "+tree.countOfNodes(root));
   //

	System.out.println("total Sum of nodes of Binary tree " + tree.sumOfNodes(root));

	//
	System.out.println("total hight of Binary tree " + tree.hight(root));
   	//
	System.out.println("Diameter of Binary tree by Approach-1 " + tree.diameter1(root));
	//
	System.out.println("Diameter of Binary tree by Approach-2 " + tree.diameter2(root).diam);
       //  sum of nodes of kth level 
	tree.KthSum(root, 2);
}
}

