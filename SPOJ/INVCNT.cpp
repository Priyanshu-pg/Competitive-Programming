#include<bits/stdc++.h>
using namespace std;

long long int mergeArr(int arr[], int l, int m , int r){
    int i, j, k;
    long long int count = 0;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            //cout<<L[i]<<" "<<R[j]<<" ";
            count+=n1-i;
           // cout<<count<<endl;
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    return count;
}

void mergesort(int a[], int low, int high, long long int & count){
    if(low<high)
    {
        int mid = (low+high)/2;
        mergesort(a, low, mid, count);
        mergesort(a, mid+1, high, count);

        count+=mergeArr(a, low, mid, high);
        //cout<<"low "<<low<<" high "<<high<<" count "<<count<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        long long int count = 0;
        mergesort(a,0,n-1, count);
        cout<<count<<endl;
    }
    return 0;
}
