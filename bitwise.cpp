Rule 1) 1<<i is left shift operator
Example: a<<1 and b<<2, it shifts 1 to left.
  //a = 5(00000101) -> 1010
  //b = 9(00001001) -> 100100
 
Rule 2) (x & -x) gives us rightmost set bit!
  //101 & -(101) -> 001
  
Q1--Finding two elements appearing once in array:
1) take xor
2) find rsb
3) one would have set bit at that point
4) other would have unset
5) take xor again depending on above two conditions
6) SEE code
https://practice.geeksforgeeks.org/viewSol.php?subId=f9539c25398b49ff0c3dc6bf65973b7c&pid=703807&user=yashasweni123
 

Q2--Finding count of all set bits from 1 to n
After many observations of some great ppl, we come to know that:
  #1 First find nearest power of x, the no of set bits till it are: x *(2 power (x-1))
  #2 Now for msb of remaining digits, we add n-(2 power x)+1 to answer, that is no of remaining elements, all having msb set
  #3 The number left noe reduces again to 1----lower of power of 2
  #4 Finally, we need to find that lower power of 2 recursively, we are done!! :)

Code:
int power2 (int n){
        int x=0;
        
        while((1<<x) <=n){ //2 power x is less than equal to n
            x++;
        }
        
        return x-1;
    }
    int countSetBits(int n)
    {
       if(n==0){
           return 0;
       }
       
       int x=power2(n);
       int stx = x * (1<<(x-1)); // x into 2 power (x-1)
       int msb = n - (1<<x) + 1;
       int rest = n - (1<<x);
       
       int ans= stx + msb + countSetBits(rest);
       
       return ans;
       
    }
