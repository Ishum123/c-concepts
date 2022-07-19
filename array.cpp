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
    maximum sum subarray- kadane algo
    
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
	
// 14 - Longest subarray that is divisible by k
	# We make use of modulus concept and map
	# mod array contains sum till i and its modulus
	# if you encounter zero there, update the answer
Code:
		int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    //int sum=0;
	    map<int,int> mp;
	    
	    int sum=0;
	    int ans=0;
	    int maxLength=0;
	    
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	        
	        int mod=((sum%k)+k)%k; //to handle negative we do like this
	        
	        if(mod==0){
	            ans=max(ans,i+1);
	        }
	        
	        else if(mp.find(mod)==mp.end()){
	            mp[mod]=i;
	        }
	        
	        else{
	            ans=max(ans,i-mp[mod]);
	        }
	    }
	    
	    return ans;
	}
	
//15 - Printing all possible combinations of r elements in the array
int n=5;
int r=3;
vector<vector<int>> ans;
vector<int> arr={1,2,3,4,5};

//Similar to nCr=(n-1)C(r-1)+ (n-1)C(r)
//len bdhega if element liya, else len remains same(element is excluded)
void memo(vector<int> data, int i, int len){
     
     //Made one combination
     if(len==r){
          ans.push_back(data);
          return;
     }
     
     //Base Case
     if(i>=n){
          return;
     }
     
     //iterating through indexes
     data.pb(arr[i]);
     memo(data,i+1,len+1); 
     data.pop_back(); //bakctrack for next solution
     memo(data,i+1,len);
     
}

void hihi(){
   
    vector<int> data;
    memo(data,0,0);
    
    for(auto it:ans){
         vector<int> temp=it;
         
        for(int i=0;i<r;i++){
             cout<<temp[i]<<" ";
        }
        cout<<endl;
    }
    return;
}

//Length of largest subarray having contiguos elements:
Code:
	int arr[]={1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
     int n=10;
     
     int ans=1;
     //if diff btw maximum and minimum element of subarray
     //is equal to the diff of first and last index of subarray
     //the ans=len(i-j)
     
     for(int i=0;i<n-1;i++){
          int mx=arr[i];
          int mn=arr[i];
          
          for(int j=i+1;j<n;j++){
               mx=max(mx,arr[j]);
               mn=min(mn,arr[j]);
               
               if(abs(mx-mn)==abs(j-i)){
                    ans=max(ans,(mx-mn+1));
               }
          }
     }
     
     cout<<ans<<endl;
     return;
}
