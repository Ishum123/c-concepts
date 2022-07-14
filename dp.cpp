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

