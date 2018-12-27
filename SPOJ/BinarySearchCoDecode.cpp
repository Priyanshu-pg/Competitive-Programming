#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        long int n,c;
        cin>>n>>c;

        long int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];

        sort(a,a+n);
        long int diff[n-1], low=INT_MAX, high=0;
        for(int i=0;i<n-1;i++){
            diff[i]=a[i+1]-a[i];
            if(low>diff[i])
                low=diff[i];
            high+=diff[i];
        }

        while(low<high){
            long long int mid = low+(high-low+1)/2;
            int cows=1;
            long long int curr=0;
            for(int i=0;i<n-1;i++){
                if(curr+diff[i] >= mid){
                    cows++;
                    curr = 0;
                }
                else{
                    curr+=diff[i];
                }
            }

            /*int i = 0 , j = 1 , cows = 1;
            while(j<n) {
                if(a[j] - a[i] >=mid) i = j++ ,cows++ ;
                else j++ ;
            }*/
          //  cout<<low<<" "<<high<<" "<<cow<<endl;
            if(cows >= c){
                low=mid;
            }
            else if(cows < c)
            {
                high = mid-1;
            }
        }
        cout<<low<<endl;
    }
    return 0;
}
