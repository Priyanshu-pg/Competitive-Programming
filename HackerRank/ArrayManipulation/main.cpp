#include <bits/stdc++.h>
#include<unistd.h>
using namespace std;
long a[10000001]={0};
int main()
{
    long n,m,l,r,k;
    cin>>n>>m;
    for(long  i=0;i<m;i++)
    {
        cin>>l>>r>>k;
        a[l]+=k;
        if(r+1<=n)
            a[r+1]-=k;
    }
    long max = INT_MIN, x=0;
    for(long i=1;i<=n;i++)
    {
        x+=a[i];
        if(max<x)
            max=x;
    }
    cout<<max<<endl;
    usleep(3000);
    return 0;
}
