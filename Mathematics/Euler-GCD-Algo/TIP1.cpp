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
    #define MAX_LIM 10000005
    typedef pair<int, int> p;

    ll phi[MAX_LIM], greatest_ratio[MAX_LIM];

    bool isPerm(ll a, ll b)
    {
        int count_a[10]={0};
        int count_b[10]= {0};

        while(a)
        {
            count_a[ a%10 ]++;
            a /= 10;
        }

        while(b)
        {
            count_b[ b%10 ]++;
            b /= 10;
        }

        for(int i = 0; i <= 9; i++)
        {
            if(count_a[i] != count_b[i])
                return false;
        }
        return true;
    }

    void precal_phi()
    {
        for(ll i = 0; i < MAX_LIM; i++)
        {
            phi[i] = i;
            greatest_ratio[i] = -1;
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

            greatest_ratio[i] = greatest_ratio[i-1];

            if(isPerm(phi[i], i))
            {
                if(greatest_ratio[i-1] == -1)
                    greatest_ratio[i] = i;
                else if( i * phi[greatest_ratio[i-1]] <= greatest_ratio[i-1] * phi[i] )
                    greatest_ratio[i] = i;
            }                
        }

    }

    void solve()
    {
        precal_phi();
        ll t;
        cin>>t;
      //  cout<<phi[63]<<" "<<isPerm(63, phi[63])<<endl;
        while(t--)
        {
            ll n;
            cin>>n;
            if(greatest_ratio[n-1] == -1)
                cout<<"No solution."<<endl;
            else
                cout<<greatest_ratio[n-1]<<endl;
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
