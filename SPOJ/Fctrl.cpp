#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll result=0;
        for(ll i=5;n/i>0;i*=5)
        {
            result+=n/i;
        }
        cout<<result<<endl;
    }
    return 0;
}
