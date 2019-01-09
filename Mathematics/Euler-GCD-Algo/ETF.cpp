#include <bits/stdc++.h>
    using namespace std;
     
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

    void solve()
    {
        int t;
        cin>>t;
        while(t--)
        {
            ll n;
            cin>>n;
            double ans = n;

            if(n%2 == 0)
            {
                ans *= 0.5;
                n /= 2;
            }
            while(n%2 == 0)
            {
                n /= 2;
            }

            for(ll i=3; i <= sqrt(n); i+=2)
            {
                if(n%i == 0)
                {
                    ans *= 1 - 1/(double)i;;
                    n /= i;
                    while(n%i == 0)
                    {
                        n /= i;
                    }
                }
            }

            if(n > 2)
            {
                ans *= 1 - 1/(double)n;
            }

            cout<<ans<<endl;
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
