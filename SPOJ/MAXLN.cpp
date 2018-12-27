#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        long long r;
        cin>>r;
        long long ans = 4*r*r;
        cout<<"Case "<<k<<": "<<ans<<".25"<<endl;
    }
    return 0;
}
