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

    bool isRealFancy(string s)
    {
        stringstream s_stream(s);
        string word;

        while( getline(s_stream, word, ' ') )
        {
            if( word == "not" )
                return true;
        }
        
        return false;
    }

    void solve()
    {
        int t;
        cin>>t;
        cin.ignore();
        while(t--)
        {
            string s;
            getline(cin, s);
            if( isRealFancy(s) )
                cout<<"Real Fancy"<<endl;
            else 
                cout<<"regularly fancy"<<endl;
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
