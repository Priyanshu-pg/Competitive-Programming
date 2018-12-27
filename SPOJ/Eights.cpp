#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        long long int k, i;
        cin>>k;
        if(k%2==1)
        {
            i = 192 + (k-1)/2*500;
        }
        else
        {
            i = 442 + (k/2 -1)*500;
        }
        cout<<i<<endl;
    }
    return 0;
}
