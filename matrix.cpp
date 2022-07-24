Q1) Submatrix with 0 sum or maximum no of zeroes and ones
pair<int,int> subsum(vector<int> &temp, int col){
     map<int,int> mp;
     int maxLength=0;
     int sum=0;
     int end=-1;
     
     for(int i=0;i<col;i++){
          sum+=temp[i];
          if(temp[i]==0){
               maxLength=max(maxLength,1);
          }
          if(sum==0){
               maxLength=i+1;
               end=i;
          }
          
          if(mp.find(sum)!=mp.end()){
              if(maxLength<i-mp[sum])
                {
                     maxLength=i-mp[sum];
                     end=i;
                }
          }
          
          else{
               mp[sum]=i;
          }
     }
     
     pair<int,int>p{maxLength,end};
     return p;
}

void hihi(){
     int n;
     cin>>n;
     
     int a[n][n];
     for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
               cin>>a[i][j];
          }
     }
     
        //int left=0,right=0,up=0,down=0;
        int srow=0;
        int erow=0;
        int scol=0;
        int ecol=0;
        int flen=0;
        int row=n,col=n;
     
     for(int i=0;i<row;i++){
          vector<int> temp(col,0);
          for(int j=i;j<row;j++){
               for(int k=0;k<col;k++){
                    if(a[j][k]==0){
                         temp[k]+=-1;
                    }
                    else temp[k]+=1;
               }
               
               pair<int,int> res=subsum(temp,col);
               
               if((flen*(erow-srow+1))<(res.first*(j-i+1))){
                    flen=res.first;
                    srow=i;
                    erow=j;
                    scol=res.second-res.first+1;
                    ecol=res.second;
               }
          }
     }
     
     int finalArea=flen*(erow-srow+1);
     cout<<finalArea<<endl;
     
     for(int i=srow;i<=erow;i++){
          for(int j=scol;j<=ecol;j++){
               cout<<a[i][j]<<" ";
          }
          cout<<endl;
     }
     return;
}
