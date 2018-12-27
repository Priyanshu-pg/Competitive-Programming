#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[], int visited[], int color[], int v, int s, int currColor)
{
    cout<<"source "<<s<<endl;
    visited[s]=1;
    color[s]=currColor;
    int nextColor;
    if(currColor==1)
    {
        nextColor=0;
    }
    else
    {
        nextColor=1;
    }

    for(int i=0;i<adj[s].size();i++)
    {
        cout<<adj[s][i]<<endl;
        if(visited[adj[s][i]]==0)
        {
            cout<<"not visited"<<" "<<nextColor<<endl;
            if(!dfs(adj,visited, color,v,adj[s][i],nextColor))
            return false;
        }
        else
        {
            cout<<"visited"<<" "<<color[s]<<" "<<color[adj[s][i]]<<endl;
            if(color[adj[s][i]]==color[s])
                return false;
        }
    }
    return true;
}

long int howMany(string compete[], int v)
{
    int visited[v], color[v];
    vector<int> adj[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=0;
        stringstream check1(compete[i]);
        string intermediate;
        while(getline(check1, intermediate, ' '))
        {
            adj[i].push_back(stoi(intermediate));
            adj[stoi(intermediate)].push_back(i);
        }
    }

    long int result = 1, count;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==0)
        {
            if(!dfs(adj, visited, color, v, i, 1))
            {
                return -1;
            }
            else
                result*=2;
        }
    }
    return result;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cin.ignore();
        string compete[n];
        for(int i=0;i<n;i++)
        {
            getline(cin, compete[i]);
          //  cout<<i<<" "<<compete[i]<<endl;
        }
        long int count = howMany(compete, n);
        cout<<count<<endl;
    }
}
