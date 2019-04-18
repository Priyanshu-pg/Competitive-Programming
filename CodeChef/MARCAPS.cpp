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
        int t;
        cin>>t;
        while(t--)
        {
            bool flag = true;
            ll n;
            cin>>n;
            ll a[n];
            map<ll,ll> m;
           // cout<<n<<endl;
            for(ll i = 0; i < n ;i++)
            {
                cin>>a[i];
                if(m.find(a[i]) != m.end())
                    m[a[i]]++;
                else
                    m[a[i]] = 1;
            }    
            for(auto const& x : m)
            {
                if((n - 2*x.sc) < 0)
                {
                    flag = false;
                    break;
                }
            }
            
            std::map<ll, ll>::iterator it, it1;
            if(flag)
            {
                cout<<"Yes"<<endl;
                for(int i = 0; i < n; i++)
                {
                    it = m.find(a[i]);
                    it1 = ++it;
                    if(it1 == m.end())
                    {
                        it1 = m.begin();
                    }
                    
                    cout<<it1->first<<" ";
                    (it1->second)--;
                    if(it1->second == 0)
                        m.erase(it1);
                }
                cout<<endl;
            }
            else
            {
                cout<<"No"<<endl;
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
