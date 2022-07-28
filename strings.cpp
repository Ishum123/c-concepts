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


Q2) KMP algo
vector<int> kmp(string s){
     int n=s.length();
     vector<int> pre(n,0);
     
     for(int i=1;i<n;i++){
          int j=pre[i-1];
          
          while(j>0 and s[i]!=s[j]){
               //match nahi hore, to go to index jaha last match ho paa rhe ho!
               j=pre[j-1];
          }
          
          if(s[i]==s[j]){
               j++; //match hogya to abhi tk jitna hua plus one
          }
          pre[i]=j;
     }
     return pre;
}

void hihi(){
     string t="lolojaslol";
     string s="as";
     
     vector<int> prefix=kmp(s);
     
     //for finding lps(longest proper prefix suffix) by kmp
     /*for(int i=0;i<s.length();i++){
          cout<<prefix[i]<<" ";
     }
     cout<<endl;*/
     
     //for searching s in t and returning index
     //kmp s ka bnta he jise search krna hota uski table
     int pos=-1;
     int i(0),j(0);

     while(i<t.size()){
          if(t[i]==s[j]){
               i++;
               j++;
          }
          
          else{
               if(j!=0) j=prefix[j-1];//puraane index pr jaao
               else i++;
          }
          
          if(j==s.size()){//found a substring
               pos=i-s.size();
               break;
          }
     }
     
     cout<<pos<<endl;
     return;
}

Q3) Base 2 to base 6
    void hihi(){
     string s="100111";
     int n=s.length();
     
     //getting decimal value from base 2 numbers(binary)
     __int128 num=0;
     for(int i=0;i<n;i++){
          num=num*2+(s[i]-'0');
     }
     
     vector<int> ans;
 
    // Decimal to base 6
    while (num> 0) {
        ans.push_back(num % 6);
        num = num / 6;
    }
     
     reverse(all(ans));
     fors(i,0,ans.size()) cout<<ans[i];
     return;
}
