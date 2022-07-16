//1 removing duplicates

int remDups(int arr[], int n)
{
	int res = 1;

	for(int i = 1; i < n; i++)
	{
		if(arr[res - 1] != arr[i])
		{
			arr[res] = arr[i];
			res++;
		}
	}

	return res;
}

// 2 to move all zero at back:
   
   int count=0;
 for(int i=0;i<n;i++){
      if(a[i]!=0){
           swap(a[i], a[count]);
           count++;
       }
    }
    
    
//  3 to left shift by d

void leftRotate(int arr[], int d, int n)
{
	int temp[d];

	for(int i = 0; i  < d; i++)
	{
		temp[i] = arr[i];
	}

	for(int i = d; i  < n; i++)
	{
		arr[i - d] = arr[i];
	}

	for(int i = 0; i  < d; i++)
	{
		arr[n - d + i] = temp[i];
	}	
}

// 4 leaders (solved by myself)

  int lead=a[n-1];
    cout<<a[n-1]<<" ";
    for(int i=n-2;i>=0;i--){
        if(a[i]>lead){
        cout<<a[i]<<" ";
        lead=a[i];
        }
    }
    
// 5 maximum diff in array elements a[j]-a[i] j>i in o(n) time

int maxDiff(int arr[], int n)
{
	int res = arr[1] - arr[0], minVal = arr[0];

	for(int i = 1; i < n; i++)
	{
		
			res = max(res, arr[i] - minVal);
			
			minVal = min(minVal, arr[i]);
	}

	return res;
}


//6  frequency of array element

void printFreq(int arr[], int n)
{
	int freq = 1, i = 1;

	while(i < n)
	{
		while(i < n && arr[i] == arr[i - 1])
		{
			freq++;
			i++;
		}

		cout<<arr[i - 1] << " " << freq << endl;

		i++;
		freq = 1;
	}
}

//7 reversing array elements in group(k)

 void reverseInGroups(vector<long long>& arr, int n, int k){
        // code here
        
         for (int i = 0; i < n; i += k)
    {
        int left = i;
 
        // to handle case when k is not multiple of n
        int right = min(i + k - 1, n - 1);
 
        // reverse the sub-array [left, right]
        while (left < right)
            swap(arr[left++], arr[right--]);
    }
}


//8 counting maximum ones in array:

	int res = 0, curr = 0;

	for(int i = 0; i < n; i++)
	{
		if(arr[i] == 0)
			curr = 0;
		else
		{
			curr++;

			res = max(res, curr);
		}
	}
	
	return res;

//9 *continuous- sub array*
    maximum sum subarray- kadane's algo
    
    int maxSum(int arr[], int n)
{
	int res = arr[0];

	int maxEnding = arr[0];

	for(int i = 1; i < n; i++)
	{
		maxEnding = max(maxEnding + arr[i], arr[i]);

		res = max(maxEnding, res);
	}
	
	return res;
}


// 10* stock buy sell prblm

int maxProfit(int price[], int n)
{
	int profit = 0;

	for(int i = 1; i < n; i++)
	{
		if(price[i] > price[i - 1])
			profit += price[i] - price[i -1];
	}

	return profit;

}

//11*  trapping rainwater

int getWater(int arr[], int n)
{
	int res = 0;

	for(int i = 1; i < n - 1; i++)
	{
		int res = 0;

    	int lMax[n];
    	int rMax[n];

    	lMax[0] = arr[0];
    	for(int i = 1; i < n; i++)
    		lMax[i] = max(arr[i], lMax[i - 1]);


    	rMax[n - 1] = arr[n - 1];
    	for(int i = n - 2; i >= 0; i--)
    		rMax[i] = max(arr[i], rMax[i + 1]);

    	for(int i = 1; i < n - 1; i++)
    		res = res + (min(lMax[i], rMax[i]) - arr[i]);
    	
    	return res;
	}


// *12- longest even odd sub array

int maxEvenOdd(int arr[], int n)
{
	int res = 1;
	int curr = 1;

	for(int i = 1; i < n; i++)
	{
			if((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0)
			   ||(arr[i] % 2 != 0 && arr[i - 1] % 2 == 0))
				{
					curr++;

					res = max(res, curr);
				}
				else
					curr = 1;
	}
	
	return res;
}


// 13 - Maximum product subarray:
 int maxProduct(vector<int>& nums) {
       //optimised dp solution  
        int mx=nums[0];
        int mn=nums[0];
        int ans=nums[0];
        
        int n=nums.size();
        
        for(int i=1;i<n;i++){
            int temp=mx;
            
            mx=max({nums[i]*temp, nums[i]*mn, nums[i]}); //either of three can be maximum due to negative number multiplications.
            mn=min({nums[i]*temp, nums[i]*mn, nums[i]});
            
            ans=max(ans,mx);
        }
        
        return ans;
}
	
