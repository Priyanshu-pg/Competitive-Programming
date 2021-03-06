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
        int kase = 1;
        while(true)
        {
            string s;
            cin>>s;
            if(s[0]=='-')
                break;
            stack<char> st;
            for(int i = 0; i < s.size(); i++)
            {
                if(st.empty() || s[i] == '{')
                    st.push(s[i]);
                else
                {
                    if(st.top() == '{')
                        st.pop();
                    else
                        st.push(s[i]);
                }
            }
            //cout<<st.size()<<endl;
            int count = 0, open = 0, closed = 0;
            while(!st.empty())
            {
                if(st.top() == '{')
                    open++;
                else
                    closed++;
                st.pop();
            }
            count = (open+1)/2 + (closed+1)/2;
            cout<<kase<<". "<<count<<endl;
            kase++;
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
