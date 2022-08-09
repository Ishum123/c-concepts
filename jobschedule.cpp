#Weighted Job Scheduling
struct job{
      int st,ed,cost;
};

int getTime(string s){
     int hr=(s[0]-'0')*10 + (s[1]-'0');
     int min=(s[2]-'0')*10 + (s[3]-'0');
     
     return hr*60+min;
}

bool compare(job a, job b){
     return a.ed<b.ed;
}

int search(job arr[], int st, int ed, int key){
     int ans=-1;
     
     while(st<=ed){
          int mid=(st+ed)/2;
          
          if(arr[mid].ed<=key){
               ans=mid;
               st=mid+1;
          }
          
          else ed=mid-1;
     }
     
     return ans;
}

pair<int,int> solve(job arr[], int n){
     int dp[n]={0};
     int num[n]={0};
     
     dp[0]=arr[0].cost;
     num[0]=1;
     
     for(int i=1;i<n;i++){
          int curr=arr[i].cost;
          int nums=1;
          int idx=search(arr,0,i-1,arr[i].st);
          
          if(idx!=-1){
               curr+=dp[idx];
               nums+=num[idx];
          }
          
          if(curr>dp[i-1]){
               dp[i]=curr;
               num[i]=nums;
          }
          
          else{
               dp[i]=dp[i-1];
               num[i]=num[i-1];
          }
     }
     
     return {num[n-1],dp[n-1]};
}

void hihi(){
     int n;
     cin>>n;
     
     job arr[n];
     int cost;
     string st,ed;
     int total=0;
     
     for(int i=0;i<n;i++){
          cin>>st>>ed>>cost;
          arr[i].st=getTime(st);
          arr[i].ed=getTime(ed);
          arr[i].cost=cost;
          total+=cost;
     }
     
     sort(arr,arr+n,compare);
     
     pair<int,int> res=solve(arr,n);
     cout<<n-res.first<<endl;
     cout<<total-res.second<<endl;
}
