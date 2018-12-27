#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isPrime(ll n)
{
    if(n<=1)
        return false;
    if(n==2)
        return true;
    if(n%2 == 0)
        return false;
    for(ll i=3;i<=sqrt(n); i+=2)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n, m;
        cin>>n>>m;
        for(ll i=n;i<=m;i++)
        {
            if(isPrime(i))
                cout<<i<<endl;
        }
        cout<<endl;
    }
    return 0;
}
