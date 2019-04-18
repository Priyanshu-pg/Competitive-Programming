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
    bool valid[MAX_LIM][MAX_LIM];
    vector< vector<p> > paths;
    int n, m;
    vector<p> marked;

    int row[4] = { 1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    bool isValid(int x, int y, p s, p d)
    {
        if(x < 0 || x >= n || x < s.sc || x > d.sc)
            return false;
        if(y < 0 || y >= n )
            return false;
        return valid[x][y];
    }

    bool myComp(p a, p b)
    {
        return graph[a.fr][a.sc] < graph[b.fr][b.sc];
    }

    bool compMarks(p a, p b)
    {
        return a.fr < b.fr;
    }

    bool dfs(p s, p d, int x, int y, vector<p> &path)
    {
        valid[x][y] = false;
        path.push_back(mp(x, y));
        if(x == d.fr && y == d.sc)
        {
            paths.push_back(path);
           // cout<<"path "<<endl;
            for(int i = 0; i < path.size(); i++)
            {
                cout<<path[i].fr<<" "<<path[i].sc<<" ";
            }
            cout<<endl;
            return 1;
        }

        vector<p> neighbors;
        for(int i = 0; i < 4; i++)
        {
            if( isValid(x + row[i], y + col[i], s, d) )
            {
                neighbors.push_back(mp(x + row[i], y + col[i]));
            }
        }

        sort(neighbors.begin(), neighbors.end(), myComp);

        // cout<<"curr "<<x<<" "<<y<<endl;
        // cout<<"neighbors "<<endl;
        for(int i = 0; i < neighbors.size(); i++)
        {
            //cout<<neighbors[i].fr<<" "<<neighbors[i].sc<<endl;
            if(dfs(s, d, neighbors[i].fr, neighbors[i].sc, path) == 1)
                return 1;
        }

        valid[x][y] = false;
        path.pop_back();
        return 0;
    }

    void solve()
    {
        int x, y;
        cin>>n>>m;

        for( int i = 0; i < 2*m; i++)
        {
            cin>>x>>y;
            marked.push_back(make_pair(x, y));
        }

        sort(marked.begin(), marked.end(), compMarks);

        // for(int i = 0; i < marked.size(); i++)
        // {
        //     cout<<marked[i].fr<<" "<<marked[i].sc<<endl;
        // }
        for( int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin>>graph[i][j];
                graph[i][j] = -graph[i][j];
                valid[i][j] = true;
            }
        }

        vector<int> path;
        for(int i = 0; i < marked.size(); i += 2)
        {
            p start =  marked[i];
            p end = marked[i+1];

            for( int i = start.fr; i <= end.fr; i++)
            {
                path.push_back(i);
                path.push_back(start.sc);
                //cout<<i<<" "<<start.sc<<" ";
            }
            if(end.sc > start.sc)
            {
                for( int i = start.sc + 1; i <= end.sc; i++)
                {
                    path.push_back(end.fr);
                    path.push_back(i);
                    //cout<<end.fr<<" "<<i<<" ";
                }
            }
            else
            {
                for( int i = start.sc - 1; i >= end.sc; i--)
                {
                    path.push_back(end.fr);
                    path.push_back(i);
                    //cout<<end.fr<<" "<<i<<" ";
                }
            }
            cout<<path.size()/2<<" ";
            for(int i = 0; i< path.size(); i++)
                cout<<path[i]<<" ";
            cout<<endl;
            path.clear();
            //vector<p> curr_path ;
           // cout<<start.fr<<" "<<start.sc<<endl;
            //dfs(start, end, start.fr, start.sc, curr_path);
           // cout<<marked.size()<<endl;  
        }

        // for(int i = 0; i < paths.size(); i++)
        // {
        //     for(int j = 0; j < paths[i].size(); j++)
        //     {
        //         cout<<paths[i][j].fr<<" "<<paths[i][j].sc<<"  ";
        //     }
        //     cout<<endl;
        // }
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
