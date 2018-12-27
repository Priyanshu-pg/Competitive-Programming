#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    while(true)
    {
        ll n;
        cin>>n;
        if(n==-1)
        {
            break;
        }
        ll a[n], sum=0;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%n!=0)
        {
            cout<<-1<<endl;
            continue;
        }
        else
        {
            ll req=sum/n;
            ll move=0;
            for(int i=0;i<n;i++)
            {
                if(a[i]<req)
                {
                    move+=req-a[i];
                }
            }
            cout<<move<<endl;
        }
    }
    return 0;
}

