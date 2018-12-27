#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    bool flag=true;
    while(flag)
    {
        ll n;
        cin>>n;
        if(n==0)
        {
            flag=false;
            break;
        }
        else
        {
            ll result = (n*(n+1)*(2*n+1))/6;
            cout<<result<<endl;
        }
    }
}
