Q1) kth smallest element after removing some elements from the array.
Link: https://www.geeksforgeeks.org/k-th-smallest-element-removing-integers-natural-numbers/

Most efficient and easy solution is:
int ksmallest(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) //if array element is smaller than or equal to k, then k++ as k will shift now
            k++;
        else
            break; //elsewe found the answer
    }
    return k;
}

//Note: array given is sorted.
