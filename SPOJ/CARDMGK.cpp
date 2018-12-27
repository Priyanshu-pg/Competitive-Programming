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
        ll a[n];
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }

        bool flag = true;
        ll i=0;
        for(i=1;i<n;i++)
        {
            if(a[i]<a[i-1])
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            cout<<"YES"<<endl;
        }
        else{
            flag = true;
            for(ll j=i+1;j<n;j++)
            {
                if(a[j]>=a[j-1])
                {
                    continue;
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(!flag)
            {
                cout<<"NO"<<endl;
                continue;
            }
            else{
                if(a[n-1]<=a[0])
                {
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
        }
    }
    return 0;
}
