#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ll result;
    ll curr;
    for(int i=0;i<n;i++)
    {
        cin>>curr;
        if(i==0)
        result=curr;
        else
        result^=curr;
       // cout<<curr<<" "<<result<<endl;
    }
    cout<<result<<endl;
    return 0;
}
