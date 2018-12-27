
    /***************************
    Sahil Khosla  |  18-02-2018
    ***************************/

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
    // ll countBits(ll n){
    //     ll num = n;
    //     ll ct = 0;
    //     while(num!=0){
    //         if(num%2==1){
    //             ct++;
    //         }
    //         num = num/2;
    //     }
    //     return ct;
    // }
    void solve( ){
    	ll t;cin>>t;
        while(t--){
            ll a,b,c;
            cin>>a>>b>>c;
            ll x = __builtin_popcount(a);
            ll y = __builtin_popcount(b);
            ll i;
            ll count = 0;
            for(i=1;i<c;i++){
                if(__builtin_popcount(i)==x&&__builtin_popcount(c-i)==y){
                    count++;
                }
            }
            cout<<count<<"\n";
        }
    }
    int main()
    {

        fastIO;
        map<ll,vector<ll>> m;
        ll max = 0;
        for(ll i=1;i<=1000000000;i++)
        {
            int x = __builtin_popcount(i);
            m[x].push_back(i);

            if(max < m[x].size())
            {
                max=m[x].size();
            }

            cout<<i<<endl;
            //cout<<i<<" "<<x<<" "<<max<<" "<<m[x].size()<<endl;
        }
        cout<<max<<endl;
    	//solve();
    	return 0;
    }
