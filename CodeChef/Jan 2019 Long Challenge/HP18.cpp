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

    ll gcd(ll a, ll b)
    {
        if( b == 0 )
            return a;
        return gcd(b, a%b);
    }
    void solve()
    {
        int t;
        cin>>t;
        while(t--)
        {
            ll n, a, b;
            cin>>n>>a>>b;
            ll arr[n];
            for(ll i = 0; i < n ; i++)
            {
                cin>>arr[i];
            }

            ll a_count = 0, b_count = 0, lcm = (a*b)/gcd(a, b), lcm_count=0;

            for(ll i = 0; i < n; i++)
            {
                if( arr[i]%a == 0 )
                    a_count++;
                if( arr[i]%b == 0 )
                    b_count++;
                if( arr[i]%lcm == 0 )
                    lcm_count++;
            }

            if(a_count == 0)
            {
                cout<<"ALICE"<<endl;
                continue;
            }

            if( (a_count - lcm_count) >= (b_count - lcm_count) )
                cout<<"BOB"<<endl;
            else
                cout<<"ALICE"<<endl;
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
