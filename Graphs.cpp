Q1) Reversing edge of graph st destination is reachable from source.
Link: https://www.codechef.com/problems/REVERSE

//Approach:
1) Think Greedily!
2) Make anothr edge into same graph of weight 1, that means reverse edge we created and weight of original edge=0
3) Apply Dijstra to find shortest path among them.
4) If distance is still inf, we can't reach that node, else return distance.
  
Trying....
//Code
https://www.codechef.com/viewsolution/68787528
(use 0-1 BFS for better time complexity than Dijstra).
(Everything about BFs in notes).
  
Q2) Alien Dictionary
Link: https://practice.geeksforgeeks.org/problems/alien-dictionary/1
# Approach: At first, it does not looks like a graph question, but it is!
# Iterater over the two adjacent strings and if the characters are not matching make edge from first string to second, indicating that first alphabet should appear first.
# Then do topological traversal of graph or normal dfs traversal with help of stack for k nodes.
//Code:
void dfs(vector<int> adj[], vector<int> &vis, stack<int> &st,int node){
        vis[node]=1;
        
        for(auto child: adj[node]){
            if(vis[child]==0){
                dfs(adj,vis,st,child);
            }
        }
        st.push(node);
    }
    
    string findOrder(string dict[], int n, int k) {
      vector<int> adj[k];
      
      vector<int> vis(k,0);
      stack<int> st; //to keep index of character(a->0) during topological traversal
      
      //int n=dict.length();
      
      for(int i=0;i<n-1;i++){
          string one=dict[i];
          string two=dict[i+1];
          
          int len=min(one.length(),two.length());
          for(int j=0;j<len;j++){
              if(one[j]!=two[j]){//first letter of mismatch safely
                  adj[one[j]-'a'].push_back(two[j]-'a');
                  break;
              }
          }
      }
      
      for(int i=0;i<k;i++){
          if(vis[i]==0){
              dfs(adj,vis,st,i);
          }
      }
      
      string ans="";
      while(!st.empty()){
          auto top=st.top();
          st.pop();
          
          char ch=top+'a';
          ans+=ch;
      }
      return ans;
    }
