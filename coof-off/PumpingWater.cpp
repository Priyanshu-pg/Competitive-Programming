#include<bits/stdc++.h>
using namespace std;

int count(int a[], int l, int r)
{
   // if(l>r) return 0;
    int max = max_element(a+l, a+r+1)-a;
    if(max == l || max == r)
        return 1;
    return 1+min(count(a,l,max-1), count(a,max+1,r));
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>n;
        int result;
        result = count(a,0,n-1);
        cout<<result<<endl;
    }
    return 0;
}
