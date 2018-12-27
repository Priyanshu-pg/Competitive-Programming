#include<bits/stdc++.h>
using namespace std;

bool isComponentBipartite(vector<int> adj[], bool visited[], bool color[], int s, bool currColor)
{
    visited[s]=true;
    color[s]=currColor;
    bool nextColor = !currColor;
    for(int i=0;i<adj[s].size();i++)
    {
        if(!visited[adj[s][i]])
        {
            if(!isComponentBipartite(adj,visited, color,adj[s][i],nextColor))
            return false;
        }
        else
        {
            if(!(color[adj[s][i]]^color[s]))
                return false;
        }
    }
    return true;
}

bool isBipartite(vector<int>adj[], int v)
{
    bool color[v], visited[v];
    for(int i=0;i<v;i++)
    {
        color[i]=false;
        visited[i]=false;
    }
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            if(!isComponentBipartite(adj,visited,color,i,true))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    int k=1;
    while(t--)
    {
        int v,e;
        cin>>v>>e;
        vector<int> adj[v];

        for(int i=0;i<e;i++)
        {
            int x,y;
            cin>>x>>y;
            x--;y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        cout<<"Scenario #"<<k<<":"<<endl;
        if(isBipartite(adj, v))
        {
            cout<<"No suspicious bugs found!"<<endl;
        }
        else
            cout<<"Suspicious bugs found!"<<endl;
        k++;
    }
}

