1) Rabin-Karp Algo:
# Useful in finding the occurences of a string in other string
# It generates a rolling hash functions that decreases our comparisons much more!
# It can be any function we want, just try to decrease collisions as much as possible!
# Helps to solve the palindrome finding of a stream, the worst case TC of the string finding remains O(n square) but it works quite good for simple cases
Code for finding palindromic strings:
// d is the number of characters in input alphabet
#define d 256
// q is a prime number used for evaluating Rabin Karp's Rolling hash
#define q 103
vector<bool> ans;

void getAns(string &s){
     int n=s.length();
     
     ans.push_back(1);
     
     if(n==1){
          return;
     }
     
     int fstr=s[0]%q;
     int second=s[1]%q;
     
     int h=1,i,j;
     for(i=1;i<n;i++){
          if(fstr==second){
               //comparing only when hash matches
               for(j=0;j<i/2;j++){
                    if(s[j]!=s[i-j]) break;
               }
               if(j==i/2){
                    ans.pb(1);
               }
               else ans.pb(0);
          }
          else ans.pb(0);
          
        // Calculate hash values for next iteration.
        // Don't calculate hash for next characters if
        // this is the last character of string
        if(i!=n-1){
             if(i%2==0){
                 // Add next character after first half at beginning 
                // of 'fstr'
                h = (h*d) % q;
                fstr  = (fstr + h*s[i/2])%q;
                   
                // Add next character after second half at the end
                // of second half.
                second = (second*d + s[i+1])%q;
             }
        
        else{
             // If next i is odd (next i is even) then we
             // need not to change firstr, we need to remove
             // first character of second and append a
             // character to it.
                second = (d*(second + q - s[(i+1)/2]*h)%q
                          + s[i+1])%q;
        }
       }
     }
     return;
}

void hihi(){
   
    string s="aabaacaabaa";
    
    getAns(s);
    
    for(int i=0;i<s.length();i++){
         cout<<ans[i]<<" ";
    }
    
    return;
}
