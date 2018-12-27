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

    ll break_no(ll n)
    {
        ll ans=0;
        while(n)
        {
            ans+=pow(n%10,2);
            n/=10;
        }
        return ans;
    }
    void solve()
    {
        ll n;
        cin>>n;
        unordered_set<ll> happy_nos;
        happy_nos.insert(n);
        bool flag=false;
        ll count=0;
        while(true)
        {
            count++;
            n = break_no(n);
            //cout<<n<<endl;
            if(n == 1)
            {
                flag=true;
                break;
            }
            if(happy_nos.find(n)==happy_nos.end())
            {
                happy_nos.insert(n);
            }
            else
            {
                break;
            }
        }
        if(flag)
            cout<<count<<endl;
        else
            cout<<-1<<endl;
    }

    int main()
    {
        fileI;
        fileO;
        fastIO;
        solve();
        return 0;
    }
