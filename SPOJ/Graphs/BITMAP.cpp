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

ll dist[183][183];
int n, m;

void updateNeighbour(int i, int j, queue<p> & q)
{
    int row[] = { 1, -1, 0, 0};
    int col[] = { 0, 0, -1, 1};
   // cout<<"neighbours"<<endl;
    for(int k=0;k<4;k++)
    {
        int new_row = i+row[k], new_col = j+col[k];
        if(new_row>=0 && new_row<n && new_col>=0 && new_col<m)
        {
           // cout<<new_row<<" "<<new_col<<endl;
            if(dist[new_row][new_col]  > dist[i][j]+1)
            {
                dist[new_row][new_col] = dist[i][j] + 1;
            //    cout<<"new dist "<<dist[new_row][new_col]<<endl;
                q.push(mp(new_row, new_col));
            }            
        }
    }
}

void solve()
{
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        string x;
        queue<p> q;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            for(int j=0;j<m;j++)
            {

                if(x[j]== '0')
                {
                    dist[i][j] = INT_MAX;
                }
                else
                {
                    dist[i][j] = 0;
                    q.push(mp(i, j));
                }
            }
        }
        
      
        while(!q.empty())
        {
            p curr = q.front();
            q.pop();
           // cout<<curr.fr<<" "<<curr.sc<<" "<<dist[curr.fr][curr.sc]<<endl;
            updateNeighbour(curr.fr, curr.sc, q);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
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
