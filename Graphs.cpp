Q1) Reversing edge of graph st destination is reachable from source.
Link: https://www.codechef.com/problems/REVERSE

//Approach:
1) Think Greedily!
2) Make anothr edge into same graph of weight 1, that means reverse edge we created and weight of original edge=0
3) Apply Dijstra to find shortest path among them.
4) If distance is still inf, we can't' reach that node, else return distance.
  
Trying....
//Code
https://www.codechef.com/viewsolution/68787528
(use 0-1 BFS for better time complexity than Dijstra).
(Everything about BFs in notes).
  
 ----------------------------------------------------------------------------------------------------------------------------------------------------------------------  
  
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

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  
 Q3) Disjoint Sets by rank and path compression methodology.
  Operations:
# To make set
# To find the ultimate root of tree(FindPar)
# To connect to sets if they are disjoint.

//The program is very easy and is used in algorithms like Kruksal's MST.
//Code:
int parent[10001];
int rank[10001];

void makeSet(){
     for(int i=0;i<=n;i++){
          parent[i]=i;
          rank[i]=0;
     }
}

//Works in 4alpha time complexity, if path compression is not done, it worls in logarithmic!
int findPar(int node){
     if(node==parent[node]){
          return node;
     }
     
     //path compressing -> parent[node]==...
     return parent[node]=findPar(parent[node]);
}

void union(int u, int v){
     u=findPar(u);
     v=findPar(v);
     
     if(rank[u]>rank[v]){
          parent[v]=u;
     }
     
     else if(rank[u]<rank[v]){
          parent[u]=v;
     }
     
     //rank or height of tree only changes or nicrease by 1
     //when same height nodes are attached!
     else{
          parent[u]=v;
          rank[v]++;
     }
}
void hihi(){
    makeSet();
    
    int m;
    cin>>m;
    
    while(m--){
         int u,v;
         union(u,v);
    }
    
    if(findPar(u)!=findPar(v)){
         cout<<"Different components"<<endl;
    }
    
    else cout<<"Same components!"<<endl;
    return;
}
//if same components come -> means that graph contains cycle!
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  Q4) Kruskal MST problem:
/* 
1) Sort all edges with respect to weight
2) Greedily choose shortest edge
3) If nodes don't belong to same component, take them
4) Keep taking until the two nodes don't belong to the same set
5) Don't pick if they are from same component.
6) This way no cycle would be added and we get minimum cost
7) Time complexity is O(m log m) + O(m * O(4alpha)) --> O(mlogm)
8) Space complexity is O(N)
*/

//Creating sturcture
struct node{
  int u, v, wt;
  node(int first,int second, int weight){
       u=first;
       v=second;
       wt=weight;
  }
};

//Works in 4alpha time complexity, if path compression is not done, it works in logarithmic!
int findPar(int node, vector<int> &parent){
     if(node==parent[node]){
          return node;
     }
     
     //path compressing -> parent[node]==...
     return parent[node]=findPar(parent[node], parent);
}

//making cmp
bool cmp(node one, node two){
     return one.wt<two.wt;
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank){
     u=findPar(u,parent);
     v=findPar(v,parent);
     
     if(rank[u]>rank[v]){
          parent[v]=u;
     }
     
     else if(rank[u]<rank[v]){
          parent[u]=v;
     }
     
     //rank or height of tree only changes or nicrease by 1
     //when same height nodes are attached!
     else{
          parent[u]=v;
          rank[v]++;
     }
}

void hihi(){
   // makeSet();
    int n,m;
    cin>>n>>m;
    
    vector<node> edges;
    
    //Taking input in linear form!
    for(int i=0;i<m;i++){
         int u,v,wt;
         cin>>u>>v>>wt;
         
         edges.pb(node(u,v,wt));
    }
    
    //Sorting according to weight
    sort(edges.begin(),edges.end(),cmp);
    
    vector<int> parent(n);
    for(int i=0;i<n;i++){
         parent[i]=i;
    }
    
    vector<int> rank(n,0);
    
    int cost=0;
    vector<pair<int,int>> mst;
    
    for(auto it: edges){
         if(findPar(it.v , parent)!=findPar(it.u, parent)){
              mst.push_back({it.u, it.v});
              cost+=it.wt;
              unionn(it.u, it.v, parent, rank);
         }
    }
    
    cout<<cost<<endl;
    
    for(auto it:mst){
         cout<<it.first<<" "<<it.second<<endl;
    }
   
    return;
}
Prim MST: https://practice.geeksforgeeks.org/viewSol.php?subId=f5d1aeb42139567ff5be017f9c579885&pid=700343&user=yashasweni123

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  
  
