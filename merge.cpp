1) Merge Sort Algo
void merge(int arr[], int low, int mid, int high){
     int n1=mid-low+1;
     int n2=high-mid;
     
     int a1[n1],a2[n2];
     
     for(int i=0;i<n1;i++){
          a1[i]=arr[low+i];
     }
     
     for(int i=0;i<n2;i++){
          a2[i]=arr[mid+1+i];
     }
     
     int i=0,j=0,k=low;
     
     while(i<n1 and j<n2){
          if(a1[i]<=a2[j]){
               arr[k++]=a1[i++];
          }
          else{
               arr[k++]=a2[j++];
          }
     }
     
     while(i<n1){
          arr[k++]=a1[i++];
     }
     
     while(j<n2){
          arr[k++]=a2[j++];
     }
}

void mergeSort(int arr[], int low, int high){
     if(low<high){
          int mid=low+(high-low)/2;
          
          mergeSort(arr,low,mid);
          mergeSort(arr,mid+1,high);
          
          merge(arr,low,mid,high);
     }
}                      

void hihi(){
     int arr[] = {10, 12, 12, 10, 10, 11, 10};
     int n=7;
     //implementing and practicing merge sort
     
     mergeSort(arr,0,n-1);
     
     for(int i=0;i<n;i++){
          cout<<arr[i]<<" ";
     }
     
     cout<<endl;
     return;
}
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
2) Counting inversions
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
3) Finding surpasser of the elements of the array
Link: https://practice.geeksforgeeks.org/problems/surpasser-count0615/1
