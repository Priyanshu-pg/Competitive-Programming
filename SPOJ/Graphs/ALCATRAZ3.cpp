#include<bits/stdc++.h>
using namespace std;

int n,m,x,y,k;
char maze[100][100];
int visited[100][100];

int row[]={1,0,-1,0};
int col[]={0,1,0,-1};

bool isValid(int x, int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
    return true;
    return false;
}

bool dfs(int u, int v, int steps)
{
    if(visited[u][v]==1)
    {
        if(u==x && v==y && steps>=k)
        {
            return 1;
        }
        return 0;
    }

    visited[u][v]=1;

    for(int i=0;i<4;i++)
    {
        int a=u+row[i];
        int b=v+col[i];
        if(isValid(a,b) && maze[a][b]=='.')
        {
            if(dfs(a, b, steps+1))
                return 1;
        }
    }

    visited[u][v]=0;
    return 0;
}

int main()
{
    cin>>n>>m;
    cin>>k;
    cin>>x>>y;
    x--;y--;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>maze[i][j];
            visited[i][j]=0;
        }
    }

    if(dfs(x,y,0))
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    return 0;
}
