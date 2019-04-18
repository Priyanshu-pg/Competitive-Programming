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
        ll n, m;
        cin>>n>>m;
        ll low_index = 0, high_index = 0;
        ll a[n], b[m];
        for( ll i = 0; i < n ; i++)
        {
            cin>>a[i];
            if( a[low_index] > a[i] )
                low_index = i;
        }

        for( ll i = 0; i < m; i++)
        {
            cin>>b[i];
            if( a[high_index] < a[i] )
                high_index = i;
        }

        for( ll i = 0; i < m; i++)
            cout<<low_index<<" "<<i<<endl;

        for( ll i = 0; i < n; i++ ){
            if( i != low_index)
            cout<<i<<" "<<high_index<<endl;
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
