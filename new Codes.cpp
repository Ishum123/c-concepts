Q1: Given an array arr[], find the lexicographically smallest array that can be obtained after performing at maximum of k consecutive swaps. 
Link: https://www.geeksforgeeks.org/lexicographically-smallest-array-k-consecutive-swaps/

Sol:  int n;
      cin>>n;
   
   int k;
   cin>>k;
   
   vector<int> a(n);
   take(a);
   

//first swap until we fix first element that is smallest and reachable in k swaps
//then repeat till k not equal to zero!
   for(int i=0;i<n && k>0; i++){
        int pos=i;
        for(int j=i+1;j<n;j++){
             
             if(j-i>k){
                  break;
             }
             //change position to next smaller element
             if(a[j]<a[pos]){
                  pos=j;
             }
        }
        
     //swap elements till smaller reachable element reaches end!
        for(int j=pos;j>i;j--){
             swap(a[j],a[j-1]);
        }
        
     //Change k values to the swaps we made
        k-=pos-i;
   }
   
   for(auto i: a){
        cout<<i<<" ";
   }
   cout<<endl;
