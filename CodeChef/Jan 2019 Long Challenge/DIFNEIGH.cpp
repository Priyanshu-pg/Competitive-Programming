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
        int seq1[4] = {1,1,2,2};
        int seq2[2][6] = {{1,1,3,2,2,3}, {2,2,3,1,1,3}};
        int seq3[4][4] = {{1,1,4,4}, {2,2,3,3}, {4,4,1,1}, {3,3,2,2}};
        int t;
        cin>>t;
        while(t--)
        {
            int n, m;
            cin>>n>>m;
            int a[n][m];
            int k = 1;
            if( n == 1 || m == 1)
            {
                if( n == 1)
                {
                    for(int i = 0; i < m; i++)
                    {
                        k = max(k, seq1[i%4]);
                        a[0][i] = seq1[i%4];
                    }
                }
                else
                {
                    for(int i = 0; i < n; i++)
                    {
                        k = max(k, seq1[i%4]);
                        a[i][0] = seq1[i%4];
                    }
                }
            }
            else if( n == 2 || m == 2)
            {
                if( n == 2)
                {
                    for(int i = 0; i < 2; i++)
                    {
                        for(int j = 0; j < m; j++)
                        {
                            a[i][j] = seq2[i%2][j%6];
                            k = max(k, a[i][j]);
                        }
                    }
                }
                else
                {
                    for(int i = 0; i < n; i++)
                    {
                        for(int j = 0; j < 2; j++)
                        {
                            a[i][j] = seq2[j%2][i%6];
                            k = max(k, a[i][j]);
                        }
                    }
                }
            }
            else
            {
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < m; j++)
                    {
                        a[i][j] = seq3[i%4][j%4];
                        k = max(k, a[i][j]);
                    }
                }
            }

            cout<<k<<endl;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    cout<<a[i][j]<<" ";
                }
                cout<<endl;
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
