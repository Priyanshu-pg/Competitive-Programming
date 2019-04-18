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
    #define I_LIM 202918036
    #define N_LIM 99683841
    typedef pair<int, int> p;

    ll phi[I_LIM];

    void precalc_phi()
    {
        for(ll i = 0, j = 0; i < I_LIM, j < N_LIM; i++, j++)
        {
            phi[i] = i;
        }

        for(ll i = 2; i < I_LIM; i++)
        {
            if( phi[i] == i )
            {
                for(ll j = i; j < I_LIM; j += i)
                {
                    phi[j] -= phi[j]/i;
                }
            }
        }
    }

    ll b_search(ll low, ll high, ll target)
    {
        while( low <= high)
        {
            ll mid = low + (high - low)/2;
            if( phi[mid] >= target )
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        if( phi[low] < target)
            return -1;
        return low;
    }

    void solve()
    {
        precalc_phi();
        ll t;
        cin>>t;
        while(t--)
        {
            ll n;
            cin>>n;
            cout<<phi[I_LIM-1]<<endl;
            if( n == 1 )
            {
                cout<<1<<endl;
            }
            else
            {
                ll res = inverse_phi[n];
                if(res == 0)
                    cout<<-1<<endl;
                else
                    cout<<res<<endl;
            }
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
