#include<bits/stdc++.h>

using namespace std;

int main()
{
    long int mod = 1000007;
    long int t;
    cin>>t;
    while(t--)
    {
        long int n;
        cin>>n;
        long long int result = (n*(3*n +1))/2;
        result%=mod;
        cout<<result<<endl;
    }
}
