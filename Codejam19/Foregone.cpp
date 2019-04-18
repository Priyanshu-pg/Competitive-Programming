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
    for(int k = 1; k <= t; k++)
    {
        string n;
        cin>>n;
        string a, b;
        a = n;
        b = "";
        bool encountered = false;
        for(int i = 0; i < n.size(); i++)
        {
            if(n[i] == '4')
            {
                if(!encountered)
                {
                    encountered = true; 
                }

                a[i] = '2';
                b += '2';
            }
            else
            {
                if(encountered)
                    b = b + '0';
            }
        }
        cout<<"Case #"<<k<<": "<<a<<" "<<b<<endl;
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
