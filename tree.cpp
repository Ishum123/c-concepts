Q1) Kth ancestor of a tree node.
  Given a binary tree in which nodes are numbered from 1 to n. Given a node and a positive integer K. We have to print the Kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then print -1.
  
Link: https://www.geeksforgeeks.org/kth-ancestor-node-binary-tree-set-2/

//Approach:
1) First, we find the node we need to find ancestors of and then we recursively backtrack to reach the node that is our answer, if no such node exists, means if the called parent is not NULL(We cant reach that node) return -1.

Code:
Node* temp = NULL;
 
// recursive function to calculate Kth ancestor
Node* kthAncestorDFS(Node *root, int node , int &k)
{  
    // Base case
    if (!root)
        return NULL;
     
    if (root->data == node||
       (temp =  kthAncestorDFS(root->left,node,k)) ||
       (temp =  kthAncestorDFS(root->right,node,k)))
    {  
        if (k > 0)       
            k--;
         
        else if (k == 0)
        {
            // print the kth ancestor
            cout<<"Kth ancestor is: "<<root->data;
             
            // return NULL to stop further backtracking
            return NULL;
        }
         
        // return current node to previous call
        return root;
    }
}

int main(){
  Node* parent = kthAncestorDFS(root,node,k);
     
    // check if parent is not NULL, it means
    // there is no Kth ancestor of the node
    if (parent)
        cout << "-1";
     
}

Q2) Binary Tree to DLL:
# We would use the same left and right pointers to convert binary tree to linked list, while doing inorder traversal of tree
# if prev==NULL, this means this is head pointer,
# Rest we just need to change the references of prev and root and we will get our answers.

Code: 
  Node *prev=NULL;
    
    Node * bToDLL(Node *root)
    {
        if(root==NULL) return root; //end of linked list
        
        Node *head=bToDLL(root->left);//inorder first call
        if(prev==NULL){
            head=root; //head of the linked list, if orev is null, this is first pointer
        }
        
        else{
            root->left=prev;//making connections.
            prev->right=root;
        }
        prev=root; //update for next iteration
        
        bToDLL(root->right); //inorder right call.
        return head; //returning answer
    }
  
Q3) Tree from postorder and inorder, preorder and inorder:
1) In prerder, we follow normal preorder traversal,
2) while in postorder, we reverse the criteria, that is we do: root->right->left instead of left->right->root. Also we start with reverse iterating in post array.
  
Links:
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/0/?track=DSASP-Tree&batchId=154#

Q4) Given a height h, count the maximum number of balanced binary trees possible with height h. Print the result modulo 109 + 7.
Link: https://practice.geeksforgeeks.org/problems/bbt-counter4914/1

#Approach: this is a dp solution. Maximum possible balanced trees of height h follow recursive formula:
# dp[i]=(dp[i-1]*((2*dp[i-2])%mod + dp[i-1])%mod;

Code:
long long int countBT(int h) {
      
    long long int dp[h + 1];
    //base cases
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= h; i++) {
        dp[i] = (dp[i - 1] * ((2 * dp [i - 2])%mod + dp[i - 1])%mod) % mod;
    }
    return dp[h];
}
