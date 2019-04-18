#include <bits/stdc++.h>
    using namespace std;
     
    #define pb push_back
    #define mp make_pair
    #define fr first
    #define sc second
    #define ll long long
    #define ull unsigned long long
    #define PI 3.14159265358979323846
    #define r2 1.41421356237309504880
    #define rep(i,n) for(ll i=0;i<n;i++)
    #define REP(i,k,n) for(ll i=k;i<n;i++)
    #define REPR(i,k,n) for(ll i=k;i>n;i--)
    #define fastIO std::ios::sync_with_stdio(0)
    #define fileI freopen("input.txt","r",stdin)
    #define fileO freopen("output.txt","w",stdout)
    #define mod 1000000007
    #define max3(a,b,c) max(a,max(b,c))
    #define _USE_MATH_DEFINES
    #define ms(a) memset(a,0,sizeof(a))
    typedef pair<int, int> p;
    void solve()
    {
        int t;
        cin>>t;
        for(int k = 1; k <= t; k++)
        {
            ll n, p;
            cin>>n>>p;
            ll s[n], cummSum[n+1];
            for(ll i = 0; i < n; i++)
            {
                cin>>s[i];
            }    
            sort(s, s+n);
            for(ll i = 0; i < n; i++)
            {
                if(i == 0)
                    cummSum[i] = s[i];
                else
                    cummSum[i] = s[i] + cummSum[i-1];
            }  
            ll least = INT_MAX;
            for(int i = p-1; i < n; i++)
            {
                ll maxNo = s[i];
                ll sum = (p-1)*maxNo - cummSum[i-1];
                if(i != p-1)
                    sum += cummSum[i-p]; 
                // cout<<maxNo<<" "<<sum<<endl;
                least = min(least, sum);
            }
            cout<<"Case #"<<k<<": "<<least<<endl;
        }
    }

    int main()
    {
        #ifdef ONLINE_JUDGE
        #else
            fileI;
            fileO;
        #endif
        fastIO;
        solve();
        return 0;
    }
