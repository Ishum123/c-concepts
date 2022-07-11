Q1) Finding number that is smaller than every of its permutation.
Link: https://www.geeksforgeeks.org/count-natural-numbers-whose-permutation-greater-number/

//approach, the question is very unique and the concept won't click if you see it for the first time. It requires going through stacks.
# Two observations:
//1) Number should be in increasing order.
//2) Number btw 1 to 9 are all such numbers.

Code:
int countNumber(int n)
{
    int result = 0;
 
    // Pushing 1 to 9 because all number from 1
    // to 9 have this property.
    stack<int> s;
    for (int i = 1; i <= 9; i++)
    {
         
        if (i <= n)
        {
            s.push(i);
            result++;
        }
 
        // take a number from stack and add
        // a digit smaller than or equal to last digit
        // of it.
        while (!s.empty())
        {
            int tp = s.top();
            s.pop();
            for (int j = tp % 10; j <= 9; j++)
            {
                int x = tp * 10 + j;
                if (x <= n)
                {
                    s.push(x);
                    result++;
                }
            }
        }
    }
 
    return result;
}

2) Largest area in histogram and largest area of rectagnles in matrix.

3) Maximum of minimum for every window of size in a given array.
Link: https://www.geeksforgeeks.org/find-the-maximum-of-minimums-for-every-window-size-in-a-given-array/


Question uses, next smaller and previous smaller element array(Store indexes), when made keep len=right[i]-left[i]-1; ans for this length=ans[len]=max(ans[len],arr[i]);

Code:


int left[n+1],right[n+1]; //fill be previous smaller and next smaller code!(You know that!):)
int ans[n+1]; //for length 1 to n

for(int i=0;i<=n;i++){
    ans[i]=0;
}

for(int i=0;i<n;i++){
     int len=right[i]-left[i]-1;
    ans[len]=max(ans[len],arr[i]);
}

//to fill entries which are still zero by taking values from right side of one.
for(int i=n-1;i>=1;i--){
  ans[i]=max(ans[i],ans[i+1]);
}

//ans from index 1 to n contains your answer!
