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
    #define MAX_LIM 1001
    typedef pair<int, int> p;

    ll graph[MAX_LIM][MAX_LIM];
    bool marked[MAX_LIM][MAX_LIM];
    int n, m;

    void solve()
    {
        int x, y;
        cin>>n>>m;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                marked[i][j] = false;
        }

        for( int i = 0; i < 2*m; i++)
        {
            cin>>x>>y;
            marked[x-1][y-1] = true;
        }

        for( int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin>>graph[i][j];
            }
        }

        int true_count = 0;
        std::vector<int> path;
        for(int i = 0; i < n; i++)
        {
            if(i%2 == 0)
            {
                for(int j = 0; j < n; j++)
                {
                    if(marked[i][j])
                        true_count++;

                    if(true_count%2 == 1)
                    {
                        path.push_back(i);
                        path.push_back(j);   
                    }
                    else
                    {
                        if(path.size() > 0)
                        {
                            //cout<<path.size()/2<<" ";
                            path.push_back(i);
                            path.push_back(j);
                            cout<<path.size()/2<<" ";
                            for(int i = 0; i < path.size(); i++)
                                cout<<path[i]+1<<" ";
                            cout<<endl;
                            path.clear();
                        }
                    }
                } 
            }
            else
            {
                for(int j = n-1; j >= 0; j--)
                {
                    if(marked[i][j])
                        true_count++;

                    if(true_count%2 == 1)
                    {
                        path.push_back(i);
                        path.push_back(j);   
                    }
                    else
                    {
                        if(path.size() > 0)
                        {
                            path.push_back(i);
                            path.push_back(j);
                            cout<<path.size()/2<<" ";
                            for(int i = 0; i < path.size(); i++)
                                cout<<path[i]+1<<" ";
                            cout<<endl;
                            path.clear();
                        }
                    }
                }
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
