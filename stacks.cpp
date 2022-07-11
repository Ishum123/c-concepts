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
