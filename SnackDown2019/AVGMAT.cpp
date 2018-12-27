#include<bits/stdc++.h>
#include<cstdio>
#define pb push_back
#define mp make_pair
#define inf 1000000007
#define fr first
#define sc second
#define eps 1e-9
#define clr(a) memset(a, 0, sizeof(a))1
#define sz(x) x.size()
#define sni(x) scanf("%d",&x)
#define snl(x) scanf("%lld", &x)
#define snc(x) scanf("%c", &c);
#define rep(n) for(int i = 0 ; i < n ;i ++)
#define repc(i, n) for(int i = 0 ; i < n ; i ++)
#define FOR(i, x, y) for(int i = x ; i < y ; i ++)
#define DEC(i, x, y) for(int i = x ; i >= y ; i --)
#define all(v) v.begin(), v.end()
#define min3(a, b, c) min(a, min(b,c))
#define max3(a, b, c) max(a, max(b, c))
#define alla(a, n) a, a+n
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

// UTILITY FUNCTIONS
bool isUpper(char c) {return (c >= 'A' && c <= 'Z');}
bool isLower(char c) {return (c >= 'a' && c <= 'z');}
bool iplpha(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z');}
bool isnum(char c){return (c >= '0' and c <= '9');}
bool isalnum(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z')||(c >= '0' && c <= '9');}
char toUpper(char c){return isUpper(c)?c:c-'a'+'A';}
char toLower(char c){return isLower(c)?c:c+'a'-'A';}
bool isvowel(char c){c = toLower(c); return (c == 'a' or c == 'e' or c == 'i' or c == 'i' or c == 'o' or c == 'u' || c == 'y');}
template<typename t> t gcd(t a, t b){a = abs(a), b = abs(b);return ((b == 0) ? a : gcd(b, a%b));}
template<typename t> t lcm(t a, t b){return (a * (b / gcd(a, b)));}
template <typename T> T modpow(T base, T exp, T modulus) {base %= modulus;T result = 1;while (exp > 0) {if (exp & 1) result = (result * base) % modulus;base = (base * base) % modulus;exp >>= 1;}return result;}
string toLowerCase(string s){rep(s.size()){if(!isLower(s[i])){s[i] = toLower(s[i]);}}return s;}
string toUpperCase(string s){rep(s.size()){s[i] = toUpper(s[i]);}return s;}
template<typename T> void cumulative(T *a, T *b, T n){rep(n){i ? b[i] = b[i-1] + a[i] : b[i] = a[i];}}
bool ispal(string s){ll lo, hi;lo = 0;hi = s.length()-1;while(lo <= hi){if(s[lo] != s[hi]){return 0;}lo++;--hi;}return 1;}
template<class T >string toString(T n){string v = "";while(n){v.pb(n % 10 + '0');n /= 10;}reverse(all(v));return v;}

int manhDist(pair<int,int> x, pair<int,int> y)
{
    return abs(x.first - y.first) + abs(x.second - y.second);
}

//------------------------------------------------------------------------
void solve(){
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> houses;
        int a;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a;
                if(a==1)
                {
                    houses.push_back(mp(i,j));
                }
            }
        }
        for(int i=0;i<houses.size();i++)
        {
            cout<<houses[i].fr<<" "<<houses[i].sc<<endl;
        }
        int len = n+m-2;
        int dist[len]={0};
        int curr_dist;
        for(int i=0;i<houses.size()-1;i++)
        {
            for(int j=i+1; j<houses.size();j++)
            {
                curr_dist=manhDist(houses[i], houses[j]);
                dist[curr_dist-1]++;
            }
        }

        for(int i=0;i<len;i++)
        {
            cout<<dist[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
   int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> houses;
        string s;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            for(int j=0;j<m;j++)
            {
                if(s[j]=='1')
                {
                    houses.push_back(mp(i,j));
                }
            }
        }
        int len = n+m-2;
        int dist[len]={0};
        int curr_dist;
        for(int i=0;i<houses.size()-1;i++)
        {
            for(int j=i+1; j<houses.size();j++)
            {
                curr_dist=manhDist(houses[i], houses[j]);
                dist[curr_dist-1]++;
            }
        }

        for(int i=0;i<len;i++)
        {
            cout<<dist[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
