Q1) Minimising cash flow between given sets of friends.
Link: https://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/

//A graph is given here.
//First find maximum debtor and maximum creditor and settles these two.(Greedy)
//Then recur in the same way until all the amount gets settled. (becomes 0)

Trying...
  const int N=3;
const int n=3;

int maxi(int amount[]){
     int index=0;
    
     
     for(int i=1;i<n;i++){
          if(amount[i]>amount[index]){
               index=i;
          }
     }
     
     return index;
}

int mini(int amount[]){
     int index=0;
    
     
     for(int i=1;i<n;i++){
          if(amount[i]<amount[index]){
               index=i;
          }
     }
     
     return index;
}

void minimise(int amount[]){
     int maxCredit=maxi(amount);
     int maxDebit=mini(amount);
     
     if(maxCredit==0 && maxDebit==0){
          return;
     }
     int mn=min(-amount[maxDebit], amount[maxCredit]);
     
     amount[maxCredit]-=mn;
     amount[maxDebit]+=mn;
     //maxDebit wala index pays mn amount to maxCredit
     
     minimise(amount);
}

void minCashFlow(int graph[][N]){
   
     int amount[n]={0};
     //amount btw friends to be minimised amount represents net amount to be paid to person i.
     
     for(int p=0;p<n;p++){
          for(int i=0;i<n;i++){
               amount[p]+=(graph[i][p]-graph[p][i]);
          }
     }
     
     minimise(amount); //recursive function to minimise the amount array;
     
     for(int i=0;i<n;i++){
          cout<<amount[i]<<" "; //Atlast amount array would be zero.
     }
     cout<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
        int graph[N][N] = { {0, 1000, 2000},
                        {0, 0, 5000},
                        {0, 0, 0},};
 
   
        minCashFlow(graph);
        
        // hihi();
}
/
