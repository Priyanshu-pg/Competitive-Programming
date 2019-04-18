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

ll gcd(ll a, ll b)
{
	if (b == 0) 
        return a; 
    return gcd(b, a % b); 
}

void solve()
{
	int t;
	cin>>t;
	for(int k = 1; k <= t; k++)
	{
		ll n, l; 
		cin>>n>>l;
		map<ll,ll> cipher;
		set<ll> s;
		map<ll, string> m;
		vector<ll> cipherArray, msgArray;
		ll x;
		for(ll i = 0; i < l; i++)
		{
			cin>>x;
			if(cipher.find(x) == cipher.end())
			{
				cipher[x] = 0;
				cipherArray.pb(x);
			}
			else
				cipher[x] = cipher[x]+1;
		}
		
		ll secondChar = gcd(cipherArray[0], cipherArray[1]);
		msgArray.pb(cipherArray[0]/ secondChar);
		msgArray.pb(secondChar);
		s.insert(msgArray[0]);
		s.insert(msgArray[1]);
		ll currentLen = 2, reqLen = cipher[cipherArray[0]]+1;
		if(currentLen < reqLen)
		{
			ll temp[2] = { msgArray[msgArray.size()-2],  msgArray[msgArray.size()-1] };
			for(ll i = 0; i < reqLen-currentLen; i++)
				msgArray.pb(temp[i%2]);
		}

		for(ll i = 2; i < cipherArray.size(); i++)
		{
			msgArray.pb(cipherArray[i-1]/ msgArray[msgArray.size()-1]);
			s.insert(msgArray[msgArray.size()-1]);

			ll currentLen = 2, reqLen = cipher[cipherArray[i-1]]+1;
			if(currentLen < reqLen)
			{
				ll temp[2] = { msgArray[msgArray.size()-2],  msgArray[msgArray.size()-1] };
				for(ll i = 0; i < reqLen-currentLen; i++)
					msgArray.pb(temp[i%2]);
			}
		}

		msgArray.pb(cipherArray[cipherArray.size()-1]/ msgArray[msgArray.size()-1]);
		s.insert(msgArray[msgArray.size()-1]);
		
		currentLen = 2, reqLen = cipher[cipherArray[cipherArray.size()-1]]+1;
		if(currentLen < reqLen)
		{
			ll temp[2] = { msgArray[msgArray.size()-2],  msgArray[msgArray.size()-1] };
			for(ll i = 0; i < reqLen-currentLen; i++)
				msgArray.pb(temp[i%2]);
		}

		int i = 0;
		string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		for(auto x : s)
		{
			m[x] = alphabet[i];
			i++;
		}
		string text = "";
		for(ll i = 0; i < msgArray.size(); i++)
		{
			text += m[msgArray[i]];
		}
		cout<<"Case #"<<k<<": "<<text<<endl;
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
