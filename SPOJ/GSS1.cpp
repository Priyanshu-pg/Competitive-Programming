#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int m;
    cin>>m;
    while(m--)
    {
        int l, r;
        cin>>l>>r;
        l--;r--;
        int sum=0, maxsum=INT_MIN;
        for(int i=l;i<=r;i++)
        {
            if(a[i]+sum>=a[i])
                sum+=a[i];
            else
                sum=a[i];
            if(sum>maxsum)
                maxsum=sum;
        }
        cout<<maxsum<<endl;
    }
    return 0;
}
