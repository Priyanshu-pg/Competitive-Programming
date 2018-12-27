#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n+1];
        a[0]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int count=0;
        for(int i=n;i>0;i--)
        {
            a[i]-=a[i-1];
            count+=a[i]/k;
        }
        cout<<count<<endl;
    }
    return 0;
}
