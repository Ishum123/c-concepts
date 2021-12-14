I’d say, that if \frac{n(n+1)}{2} 
2
n(n+1)
​
  is som of n numbers, then \frac{(n-1)n}{2} 
2
(n−1)n
​
  is the sum of n-1 numbers, do you agree?

You know, it’s not easy to answer the question without the proper context…

Second formula can also be used to find out number of combinations how to choose two elements out of n, or how many elements Ai,j are in square matrix where i < j and probably one can find another dozen of descriptions…


3) int n,x1,y1,x2,y2;
cin>>n>>x1>>y1>>x2>>y2;
char c;
for(int i=1;i<=n;i++){
    cin>>c;
    if(c=='N' && y2>y1) y1++;
    else if(c=='S' && y2<y1) y1--;
    else if(c=='E' && x2>x1) x1++;
    else if(c=='W' && x2<x1) x1--;
    
    if(x1==x2 && y1==y2){
        cout<<i;
        return 0;
    }
}
cout<<-1;
   }  //it's not always necessary to have strings and solve them..
