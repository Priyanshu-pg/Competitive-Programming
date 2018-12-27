#include<bits/stdc++.h>
using namespace std;

int dfs(vector<int> adj[], int visited[], int v, int s, int & maxLen)
{
    visited[s]=1;
    int maxChild=0, secmaxChild=0;
    for(int i=0;i<adj[s].size();i++)
    {
        if(visited[adj[s][i]]==0)
        {
            int curr=dfs(adj, visited, v, adj[s][i], maxLen)+1;
            if(curr>maxChild)
            {
                secmaxChild=maxChild;
                maxChild=curr;
            }
            else if(curr>secmaxChild)
            {
                secmaxChild=curr;
            }
        }
    }
    //cout<<s<<" "<<len<<" "<<maxChild<<" "<<secmaxChild<<endl;
    maxLen = max(maxLen, maxChild + secmaxChild);
    return maxChild;
}

int main()
{
    int n;
    cin>>n;
    vector<int> adj[n];
    int visited[n];
    visited[0]=0;
    for(int i=0;i<n-1;i++)
    {
        visited[i+1]=0;
        int x, y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
    }
    int maxLen = 0;
    dfs(adj, visited, n, 0, maxLen);
    cout<<maxLen<<endl;
    return 0;
}
