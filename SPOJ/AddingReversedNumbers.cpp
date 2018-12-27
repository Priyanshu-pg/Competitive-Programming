#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll reverseNo(ll n)
{
    ll reverse=0;
    while(n!=0)
    {
        reverse*=10;
        reverse+=n%10;
        n/=10;
    }
    return reverse;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n, m;
        cin>>n>>m;
        cout<<reverseNo( reverseNo(n)+ reverseNo(m))<<endl;
    }
    return 0;
}
