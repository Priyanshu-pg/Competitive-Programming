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
    
    string pattern[8];

    void generateComb()
    {
        for(int i=0;i<8;i++)
        {
            pattern[i] = "TTT";
            for(int bit = 1<<2, j=0; bit>0; bit/=2, j++)
            {
                if(i&bit)
                {
                    pattern[i][j] = 'H';
                }
            }
            //cout<<pattern[i]<<endl;
        }
    }


    bool string_match(string a, string b)
    {
        if(a.length() != b.length())
            return false;

        for(int i=0;i<a.size();i++)
        {
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
    void solve()
    {
        generateComb();

        int t;
        cin>>t;
        while(t--)
        {
            int set_no;
            cin>>set_no;
            string seq;
            cin>>seq;

            int count[8]={0};

            for(int i=0;i<seq.length()-2;i++)
            {
                string sub = seq.substr(i, 3);
                for(int i=0;i<8;i++)
                {
                    if(string_match(sub, pattern[i]))
                        count[i]++;
                }
            }
            cout<<set_no<<" ";
            for(int i=0;i<8;i++)
            {
                cout<<count[i]<<" ";
            }
            cout<<endl;

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
