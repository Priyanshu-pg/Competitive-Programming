#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        ll n;
        cin>>n;
        ll a[n+1];
        a[0]=0;
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(ll i=2;i<=n;i++)
        {
            a[i]=max(a[i-1], a[i-2]+a[i]);
        }
        cout<<"Case "<<k<<": "<<a[n]<<endl;
    }
    return 0;
}
