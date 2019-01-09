#include <bits/stdc++.h>
    using namespace std;
     
    #define pb push_back
    #define mp make_pair
    #define fr first
    #define sc second
    #define ll long lon
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
    #define MAX_LIM 1000002

    ll phi[MAX_LIM];

    ll calc_phi(ll n, map<ll, ll> & phi_map)
    {
        if(phi_map.find(n) != phi_map.end())
            return phi_map[n];

        ll res = n;

        if(n%2 == 0)
        {
            res -= res/2;
        }
        while(n%2 == 0)
        {
            n /= 2;
        }

        for(ll i = 3; i*i <= n; i += 2)
        {
            if(n%i == 0)
            {
                res -= res/i;
                while(n%i == 0)
                    n /= i;
            }
        }
        if(n > 1)
            res -= res/n;
        phi_map[n] = res;
        return res;
    }

    bool isPrime(ll n, map<ll, bool> prime_map)
    {
        if(prime_map.find(n) != prime_map.end())
            return prime_map[n];
        if(n == 2)
        {
            prime_map[n] = true;
            return true;
        }
        if(n == 1)
        {
            prime_map[n] = false;
            return false;
        }
        if(n == 0)
        {
            prime_map[n] = false;
            return false;
        }
        
        if(n%2 == 0)
        {
            prime_map[n] = false;
            return false;
        }

        for(ll i = 3; i <= sqrt(n); i+=2)
        {
            if(n%i == 0)
            {
                prime_map[n] = false;
                return false;
            }
        }
        prime_map[n] = true;
        return true;
    }

    void solve()
    {
        ll n, q;
        cin>>n>>q;

        ll a[n+1];
        a[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            cin>>a[i];
            map<ll, ll> phi_map;
            map<ll, bool> prime_map;
            ll phi = calc_phi(a[i], phi_map);
          //  cout<<a[i]<<" phi "<<phi<<endl;
            if(isPrime(phi, prime_map))
            {
                a[i] = 1;
            }
            else
            {
                a[i] = 0;
            }
            //cout<<a[i]<<endl;
        }

        for(int i = 2; i <= n ; i++)
        {
            a[i] += a[i-1];
        }

        ll l, r;
        while(q--)
        {
            cin>>l>>r;
            cout<<a[r]-a[l-1]<<endl;
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
