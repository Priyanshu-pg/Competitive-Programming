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

    ll find_gcd(ll a, ll b)
    {
        if( b == 0)
            return a;
        return find_gcd(b, a%b);
    }

    void solve()
    {
        ll t;
        cin>>t;
        while(t--)
        {
            ll n, t, x, y, z;
            cin>>n>>t>>x>>y>>z;
            ll a, b, gcd;
            switch(t)
            {
                case 1:
                    if( x == z && (y == x+1 || y == x-1) )
                    {
                        a = z;
                        b = 2*n + 1;
                    } 
                    else if( (z == y + 1 && y == x+1) || (x == y+1 && y == z+1) )
                    {
                        a = 2*n + 1 - z;
                        b = 2*n +1;
                    }
                break;
                case 2:
                    if((z == y + 1 && y == x+1) || (x == y+1 && y == z+1))
                    {
                        a = 2*n + 1 - 2*y;
                        b = 2*n + 1;
                    }
                break;
                case 3:
                    if( x == z && (y == x+1 || y == x-1) )
                    {
                        a = z;
                        b = 2*n + 1;
                    }
                    else if( (z == y + 1 && y == x+1) || (x == y+1 && y == z+1) )
                    {
                        a = 2*n + 1 - z;
                        b = 2*n + 1;
                    }
                break;
                case 4:
                if((z == y + 1 && y == x+1) || (x == y+1 && y == z+1))
                    {
                        a = 2*n + 1 - 2*y;
                        b = 2*n + 1;
                    }
                break;
            }
            gcd = find_gcd(a,b);
           // cout<<find_gcd(a,b)<<endl;
            a /= gcd;
            b /= gcd;
            cout<<a<<" "<<b<<endl;
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

