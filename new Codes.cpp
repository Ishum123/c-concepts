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


Q2: Very very important To convert Binary Tree into BST:
Link: https://www.geeksforgeeks.org/minimum-swap-required-convert-binary-tree-binary-search-tree/#:~:text=Given%20the%20array%20representation%20of,it%20into%20Binary%20Search%20Tree.&text=Swap%201%3A%20Swap%20node%208,node%209%20with%20node%2010.

Sol:
 //approach is to convert inorder traversal of binary tree, as inorder of a BST will be sorted array itself.
 //So we make sorted array and solve the question.

//inorder function
void inorder(vector<int> &v, int n, int index, int a[]){
      if(index>=n){
      return;
      }
      
      inorder(v, n, 2*index + 1, a); //left
      v.push_back(a[index]);
      inorder(v, n, 2*index+2, a); //right
  }


//minimum swaps function
int minSwaps(vector<int> v, int n ){
      vector<pair<int,int>> t(n);
      
      for(int i=0;i<n;i++){
            t[i].first=v[i];
            t[i].second=i;
      }
      
      sort(t.begin(),t.end());
      
     for(int i=0;i<n;i++){
     if(t[i].second!=i){
           swap(t[i].first,t[t[i].second].first);
           swap(t[i].second,t[t[i].second].second);
     }
           
           if(i!=t[i].second){
           i--;
           ans++;
           }
     }
      return ans;
}

Q3: Minimum time to complete all tasks. (Greedy plus binary Search!)
Link: https://www.google.com/url?q=https://www.geeksforgeeks.org/find-minimum-time-to-finish-all-jobs-with-given-constraints/&sa=D&source=editors&ust=1654850639064943&usg=AOvVaw1x6fTB3jCSku63z0n1xDCn

Sol://same as allocate minimum pages just multiply by t at last!

void hihi(){
   
   int k,t;
   cin>>k>>t;
   int n;
   cin>>n;
   
   int ans=INT_MAX;
   
   vector<int> a(n);
   take(a);
   
   sort(all(a));
   
   int low=0,high=0;
   
   for(int i=0;i<n;i++){
        high+=a[i];
   }
   
   
   while(low<=high){
        int mid=low+(high-low)/2;
        int st=1;
        int sum=0;
        
        
        for(int i=0;i<n;i++){
             if(a[i]>mid){
                  break;
             }
             
             if(sum+a[i]>mid){
                  sum=a[i];
                  st++;
             
             
             if(st>k){
                  break; //check inside the if condition!
             }
             }
             
             else{
                  sum=sum+a[i];
             }
        }
        
        if(st==k){
             ans=min(mid,ans);
             high=mid-1;
        }
        
        else low=mid+1;
   }
   
   cout<<ans*t<<endl;
   
   return;
}
