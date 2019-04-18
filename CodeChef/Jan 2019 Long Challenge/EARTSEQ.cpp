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
#define LIM 1000000

bool prime[LIM];
vector<ll> prime_list;

void seive()
{
    for(ll i = 2; i < LIM; i++)
        prime[i] = true;

    for(ll i = 2; i < LIM; i++)
    {
        if(prime[i])
        {
            for(ll j = 2*i; j < LIM; j += i)
            {
                prime[j] = false;
            }
            if(i != 2 && i != 3)
            prime_list.push_back(i);
        }
    }
}

typedef pair<int, int> p;
void solve()
{
    seive();
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        ll j = 0;
        for(ll i = 0; i < n; i += 2)
        {
            a[i] = prime_list[j];
            if(i+1<n)
                a[i+1] = prime_list[j];
            j++;
        }
        a[0] *= 2;

        for(ll i = 1; i < n; i++)
        {
            a[i] *= 3;
            i++;
            if(i < n)
                a[i] *= 3;
            i++;
            if(i < n)
                a[i] *= 2;
            i++;
            if(i < n)
                a[i] *= 2;
        }

        if(a[n-1]%2 == 1)
        {
            if(a[n-2]%2 == 0)
            {
                a[0] *= 7;
                a[n-1] *= 7;
            }
            else
                a[n-1] *= 2;
        }
        else
        {
            if(a[n-2]%2 == 0)
            {
                a[0] /= 2;
                a[0] *= prime_list[j-1];
            }
        }

        for(ll i = 0; i < n; i++)
        {
            // if(a[i] >= 1000000000 || a[i] <= 0)
            //     cout<<"trash"<<" "<<i<<" "<<prime_list[i]<<endl;
            cout<<a[i]<<" ";
        }
        cout<<endl;
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
