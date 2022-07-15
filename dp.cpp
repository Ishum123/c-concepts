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

