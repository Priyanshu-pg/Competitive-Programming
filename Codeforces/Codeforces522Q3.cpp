#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int a[200001]={0};
int main()
{
    int n;
    ll k;
    cin>>n>>k;
    int x;
    int len =0;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x>len)
            len=x;
        a[1]++;
        a[x+1]--;
    }
    int pivot=0;
    for(int i=1;i<=len;i++)
    {
        a[i]+=a[i-1];
        if(a[i]==n)
        {
            pivot=i;
        }
    }
    ll sum =0,count=0;
    for(int i=len;i>pivot;i--)
    {
        sum+=a[i];
        if(sum>k)
        {
            count++;
            i++;
            sum=0;
        }
    }
    if(sum>0)
        count++;
    cout<<count<<endl;
    return 0;
}
