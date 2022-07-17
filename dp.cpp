1) recurrence bn rha to dp lg skti
2) kbhi kbhi matrix exponentiation se bhi ho jaata

problems: 
1) Fibnonacci: Recurrence rel: dp[i]=dp[i-1]+dp[i-2];
2) Minimum no of squares whose sum equals to n: iterate till sqrt n and minimise;
   Code:
      	int MinSquares(int n)
	{
	    if(n==0 || n==1 || n==2|| n==3){
	        return n;
	    }
	    int dp[n+1];
	    for(int i=0;i<=n;i++){
	        dp[i]=0;
	    }
	    
	   dp[0]=0;
	   dp[1]=1;
	   dp[2]=2;
	   dp[3]=3;
	    for (int i = 4; i <= n; i++)
    {
         
        // max value is i as i can
        // always be represented
        // as 1*1 + 1*1 + ...
        dp[i] = i;
 
        // Go through all smaller numbers to
        // to recursively find minimum
        for (int x = 1; x <= ceil(sqrt(i)); x++)
        {
            int temp = x * x;
            if (temp > i)
                break;
            else
                dp[i] = min(dp[i], 1 +
                                  dp[i - temp]);
        }
    }
	    
	    return dp[n];
	}

 -----------             *               -----------                 *             ---------------              *                  ---------------------           *

3) Questions that use LCS concept:
   a) Diff Utility
   b) min number of insertions/deletions: (n-lcs)+(m-lcs) link:https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
   c) Shortest common supersequence(length): (m+n)-lcs
   d) Shortest common supersequence(string hard): 
       Approach: 1) Combination of c and making of string
       Code with explanation: https://leetcode.com/submissions/detail/746996850/
   e) Longest palindromic subsequence: (length) easy: lcs(reverse,string)
   f) Longest palindromic subsequence: (string) hard: 
       Code: string lpa(string a)
{
     int n=a.size();
        
        string rev=a;
        reverse(rev.begin(),rev.end());
        
        string ans="";
        
        int dp[n+1][n+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 or j==0){
                    dp[i][j]=0;
                }
                
                else{
                    if(a[i-1]==rev[j-1]){
                        dp[i][j]=1+dp[i-1][j-1];
                    }
                    
                    else{
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        
        int i=n,j=n;
        
        while(i>0 and j>0){
             if(a[i-1]==rev[j-1]){
                  ans+=a[i-1];
                  i--;
                  j--;
             }
             
             else if(dp[i-1][j]>dp[i][j-1]){
                  i--;
             }
             
             else{
                  j--;
             }
        }
        
        return ans;
}
     g) Longest repeating subseq
     h) Space optimised solution of LCS
     i) Printing LCS:
         Code:
         string lcs(string a,string rev)
{
     int n=a.size();
     int m=rev.size();
        
        string ans="";
        
        int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 or j==0){
                    dp[i][j]=0;
                }
                
                else{
                    if(a[i-1]==rev[j-1]){
                        dp[i][j]=1+dp[i-1][j-1];
                    }
                    
                    else{
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        
        int i=n,j=m;
        
        while(i>0 and j>0){
             if(a[i-1]==rev[j-1]){
                  ans+=a[i-1];
                  i--;
                  j--;
             }
             
             else if(dp[i-1][j]>dp[i][j-1]){
                  i--;
             }
             
             else{
                  j--;
             }
        }
       
       reverse(ans.begin(),ans.end());
        return ans;
}


 -----------             *               -----------                 *             ---------------              *                  ---------------------           *

4) Word Break problem
# approach: We use a boolean vector dp[]. dp[i] is set to true if a valid word (word sequence) ends there. The optimization is
# to look from current position i back and only look up in case the preceding position j with dp[j] == true is found.

Code:  bool wordBreak(string s, vector<string>& wdict) {
        int n=s.length();
        
        unordered_set<string> dict; //to find if string is present or not
        for(int i=0;i<wdict.size();i++){
            dict.insert(wdict[i]);
        }
        
        vector<bool> dp(n,false); //ans vector
            
        dp[0]=true; //if no char left
        
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                //iterate back and check whether a string exists!
                if(dp[j]){
                    string word=s.substr(j,i-j);
                    
                    if(dict.find(word)!=dict.end()){
                       dp[i]=true;
                        break; //found a string
                    }
                }
            }
        }
        
        return dp[n];
    }
};


 -----------             *               -----------                 *             ---------------              *                  ---------------------           *
 5) Combination Sums
 Link: https://leetcode.com/problems/combination-sum-iv/discuss/85120/C%2B%2B-template-for-ALL-Combination-Problem-Set

# Combination sum ->printing all possible combinations is a backtracking solution
# while printing number of possible combinations is a dp solution, its complexity is nlogn due to sorting: just check if(i<nums[j)then break, else dp[i]+=dp[i-nums[j]]

 -----------             *               -----------                 *             ---------------              *                  ---------------------           *
 6) Maximum Jump problem:
   # a) need to figure out whether we would reach end or not.
   # Recursion mx=max(mx,nums[i]+i); //i should be less than maxindex, bcoz if it becomes greater, that means we can't reach there with our current max.

 -----------             *               -----------                 *             ---------------              *                  ---------------------           *
 7) Partition sum problem:
# Approach: Very easy and logical, 
# Obs-1) If sum is odd, we can never divide it, so bool=false;
# Obs-2) If we divide sum by 2 and find sum/2 in array, problem reduces to subset sum problem as if sum/2 is found, the rest of the sum in the array is also sum/2
# Hence the logic is clear.
# Now let us code:
Code:
int equalPartition(int n, int arr[])
    {
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        
        if(sum%2){
            return 0;
        }
        
        sum=sum/2; //finding sum/2 in array, reducing problem to subset sum.
        
        int dp[n+1][sum+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                
                //if sum=0 means we made the sum, hence ans=1
                if(j==0){
                    dp[i][j]=1;
                }
                
                //if no element is left and sum is not formed, ans=0
                else if(i==0){
                    dp[i][j]=0;
                }
                
                else{
                    if(arr[i-1]>j){
                        dp[i][j]=dp[i-1][j]; //no other option as array value is greater than current sum
                    }
                    
                    else{
                       dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
                       //if one is true, we got it!
                    }
                }
            }
        }
        
        return dp[n][sum];
    }
## Note: Take care of if else, because if you miss middle else if, the above if would become the only if statement for the next else!!

 -----------             *               -----------                 *             ---------------              *                  ---------------------           *
 8) Gold Mine Problem:
# to reach from first col to last while collecting maximum gold, recursion is quite clear
# it is max(dp[i-1][j-1], dp[i][j-1], dp[i+1][j-1])+gold[i][j] with all boundary conditions.
# But we are moving from right to left, hence we need to fill the rows and columns by first filling all rows in previous columns and then moving ahead
# So the for loop is opposite of the usual ones!
PS: It is not a combinatories problem as combinatories work when number of ways are required.

Code:
https://practice.geeksforgeeks.org/viewSol.php?subId=331263e06b325b38264ae20c2ea7d1c9&pid=704162&user=yashasweni123


 -----------             *               -----------                 *             ---------------              *                  ---------------------           *
 9) Cutting maximum segments problem:
# need to find maximum segments that can be cut,
# the recursive memoisation solution is easy and intuitive, that recur until l==0, and keep subtracting x/y/z:
# pseudocode:
if(l==0)return 0;
if(dp[n]!=-1) return dp[n];
if(x<=n) a=func(n-x,x,y,z);
if(y<=n) b=func(n-y,x,y,z);
if(z<=n) c=func(n-z,x,y,z);
return dp[n]=max(a,b,c)+1;
# This can also be solved by coin change problem with little changes!
Link: https://practice.geeksforgeeks.org/viewSol.php?subId=c20ca4d2c92b2e8dd29a4f53a72eb99c&pid=701901&user=yashasweni123

 -----------             *               -----------                 *             ---------------              *                  ---------------------           *
10) LIS
You know O(n2) DP solution but space optimised solution
A better O(nlogn) solution comes from using binary search(lower bound)
Code:
  int lengthOfLIS(vector<int>& nums) {
      
       int n=nums.size();
       vector<int> res;
       //lower bound returns immediately greater than or equal to that number
       
       for(int i=0;i<n;i++){
           auto it=lower_bound(res.begin(),res.end(),nums[i]);
           
           if(it==res.end()){
               res.push_back(nums[i]);
           }
           
           else{
               //*(it) indiactes the element which is lower bound of nums[i]
               *(it)=nums[i]; //we replace nums[i] with even lesser number or equal to number for maximising                               //our answer
           } 
       }
       
       return res.size();
}
-----------             *               -----------                 *             ---------------              *                  ---------------------           *
11) Minimum moves to reach the end:
   # O(n square) DP solution:
   //Similar to LIS
   vector<ll> dp(n,INT_MAX);
   
   //dp[i] represents minimum moves required to reach i
   dp[0]=0; //can get to 0 by 0 moves
   
   for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
             if(i<=j+v[j]){
                  //if we can reach i from jth move
                  dp[i]=min(dp[i],dp[j]+1);
                  break;
             }
        }
   }
   
    cout<<dp[n-1]<<endl;

   # O(n) greedy solution:
   void hihi(){
    
   int n;
   cin>>n;
  
   vector<int> a(n);
   take(a);
   
   /*
   #1) Take three variables:
      a) maxReach to tell you ki yha se kaha tk jaa skte he hum
      b) step to indicate kitni steps bchi he, hum kitni step aage gye
      c) jump to store answer
   */
   
   int maxR=a[0];
   int step=a[0]; //itni step he na filhal to humaare paas
   int jump=1; //0 se aage to bdhna hi he
   
   
   if(n==1){
        cout<<0<<endl; //already at destination
        return;
   }
   
   if(a[0]==0){
        cout<<-1<<endl;
        return;
   }
   
   for(int i=1;i<n;i++){
        if(i==n-1){
             cout<<jump<<endl;
             return; //we got to answer safely
        }
        
        maxR=max(maxR,i+a[i]);
        step--; //took a step
        
        if(step==0){
             //ab hume jump krna hi pdega, 
             jump++;
             
             if(maxR<=i){
             //means we can't even reach i from our current reach,
             //answer is not possible
             cout<<-1<<endl;
             return;
             }
        }
        
        step=maxR-i; //remaining steps
   }
   
    return;
}
-----------             *               -----------                 *             ---------------              *                  ---------------------           *
12) Counting palindromic subsequences:
  # Need to count all the possible palindromic subsequences.
  # len 1 is always a palindrome
 
-----------             *               -----------                 *             ---------------              *                  ---------------------           *
13) Who will win, a or b
Code:
void hihi(){
    int n,x,y;
    cin>>n>>x>>y;
 
    bool dp[n+1];
    
    dp[0]=false;
    dp[1]=1;
    
    for(int i=2;i<=n;i++){
         if(i-1>=0 and !dp[i-1]){
              dp[i]=true; //dp[i-1] needs to be false else the other player would win!
         }
         
         else if(i-x>=0 and !dp[i-x]){
              dp[i]=true;
         }
         
         else if(i-y>=0 and !dp[i-y]){
              dp[i]=true;
         }
         
         else dp[i]=false;
    }
    
    if(dp[n]==true){
         cout<<"A wins!"<<endl;
    }
    
    else cout<<"B wins!"<<endl;
    return;
}
-----------             *               -----------                 *             ---------------              *                  ---------------------           *
14) Optimal Strategy for a game:
# it is clear that is both play optimally, whatever we pick, we will get minimum of the next available options, as opponent is wise too!
# it's clear we gonna start with 0 and n-1 and iterate until i>j
# Code:
long long dp[1001][1001];
    
    long long solve(int i, int j, int arr[]){
        if(i>j){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int x=arr[i]+min(solve(i+2,j,arr),solve(i+1,j-1,arr));
        int y=arr[j]+min(solve(i+1,j-1,arr),solve(i,j-2,arr));
        
        return dp[i][j]=max(x,y);
    }
    
    long long maximumAmount(int arr[], int n){
        
       memset(dp,-1,sizeof(dp));
        return solve(0,n-1,arr);
    }
