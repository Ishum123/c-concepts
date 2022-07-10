Question: Chromatic colored graph: color graph with minimum number of colors.
 
Code:
void hihi(){
   //The graph coloring problem having n nodes and m edges.
   int n,m;
   cin>>n>>m;
   
   vector<int> u(m), v(m);
   take(u);
   take(v);
   
   vector<int> adj[n];
   
   for(int i=0;i<m;i++){
        adj[u[i]].pb(v[i]);
        adj[v[i]].pb(u[i]); //undirected graph.
   }
   
   int res[n]; //resultant array to store colors of all nodes
   bool available[n]; //colors are available or not!
   res[0]=0; //color of 0 node = 0
   
   for(int i=1;i<n;i++) res[i]=-1; //initialing with -1(not colored)
   for(int i=0;i<n;i++) available[i]=false;  //all colors available
   
   int cn=0; //chromatic number is zero intitially.
   for(int i=1;i<n;i++){
        for(auto x:adj[i]){
             if(res[x]!=-1){ //adjacent vertex is colored.
                  available[res[x]]=true; //us color ko nahi use kr skte
             }
        }
        
        int cr; //trying to initialise color with smallest node number(searching min)
        for(cr=0;cr<n;cr++){
             if(available[cr]==false){ //color mil gya
                  break;
             }
        }
        
        res[i]=cr;
        cn=max(cn,cr+1); //chormatic number 0 means 1 color used so +1.
        
        //re-intialising available array
        for(auto x: adj[i]){
             if(res[x]!=-1){
                  available[res[x]]=false;
             }
        }
   }
   cout<<cn<<endl;
   
   return;
}
