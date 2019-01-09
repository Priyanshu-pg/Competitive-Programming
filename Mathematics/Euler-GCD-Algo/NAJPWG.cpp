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
    #define MAX_LIM 100005
    typedef pair<int, int> p;

    ll phi[MAX_LIM];
 
    void precalc_cumm_phi()
    {
        for(ll i = 0; i < MAX_LIM; i++)
        {
            phi[i] = i;
        }

        for(ll i = 2; i < MAX_LIM; i++)
        {
            if( phi[i] == i )
            {
                for(ll j = i; j < MAX_LIM; j += i)
                {
                    phi[j] -= phi[j]/i;
                }
            }
        }

        for(ll i = 2; i < MAX_LIM; i++)
            phi[i] += phi[i-1];
    }

    void solve()
    {
        precalc_cumm_phi();
        ll t;
        cin>>t;
        ll kase = 1;
        while(t--)
        {
            ll n;
            cin>>n;
            ll res = 0;
            if( n%2 == 0 )
            {
                res += (n/2)*(n+1);
            }
            else 
            {
                res += ((n+1)/2)*n;
            }
            res -= phi[n];
            cout<<"Case "<<kase<<": ";
            kase++;
            cout<<res<<endl;
        }

    }

    int main()
    {
        fileI;
        fileO;
        fastIO;
        solve();
        return 0;
    }
