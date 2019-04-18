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
    #define MAX_LIM 1000001
    typedef pair<int, int> p;

    void solve()
    {
        ll t;
        cin>>t;
        while(t--)
        {
            ll n, p;
            cin>>n>>p;

            ll m = (n-1)/2, x = 1;
            if(n == 1)
                m = 0;
            if(n == 2)
            {
                m = 0;
                x = 2;
            }
            
            ll y = p-n;
            ll z = p-m;
            if( y < 0)
                y = 0;
            if( z < 0)
                z =0 ;
            ll res = x*z*z + y*x*z + y*y*x;
            if(m == 0)
                res = x*p*p + y*x*p + y*y*x + y*y*y;
            cout<<res<<endl;
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
