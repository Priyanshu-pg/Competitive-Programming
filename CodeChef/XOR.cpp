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
        ll n, q;
        cin>>n>>q;
        ll a[n];
        for(ll i = 0; i < n; i++)
            cin>>a[i];
        ll pre_xor[n+1];
        pre_xor[0]=0;
        for(ll i = 0; i < n; i++)
        {
            pre_xor[i+1] = pre_xor[i]^a[i];
        }
        while(q--)
        {
            ll k;
            cin>>k;
            ll index = k%(n+1);
            cout<<pre_xor[index]<<endl;
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
