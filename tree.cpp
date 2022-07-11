Q1) Kth ancestor of a tree node.
  Given a binary tree in which nodes are numbered from 1 to n. Given a node and a positive integer K. We have to print the Kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then print -1.
  
Link: https://www.geeksforgeeks.org/kth-ancestor-node-binary-tree-set-2/

//Approach:
1) First, we find the node we need to find ancestors of and then we recursively backtrack to reach the node that is our answer, if no such node exists, means if the called parent is not NULL(We can't reach that node) return -1.

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
  
