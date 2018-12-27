#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool comp(pair<ll,ll> a, pair<ll, ll> b)
{
    return a.second<b.second;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        pair<ll, ll>xy[n];
        for(int i=0;i<n;i++)
        {
            cin>>xy[i].first;
            cin>>xy[i].second;
        }
        sort(xy, xy+n, comp);
        ll res=0, count=0;
        set<ll> in;
        for(int i=n-1;i>=0;i--)
        {
            if(in.find(xy[i].first)==in.end())
            {
           // cout<<xy[i].second<<" ";
                res+=xy[i].second;
                count++;
                in.insert(xy[i].first);
            }
            if(count==3)
            break;
        }
        if(count>=3)
        cout<<res<<endl;
        else
        cout<<0<<endl;
    }

    return 0;
}
