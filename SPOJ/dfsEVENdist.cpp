#include<bits/stdc++.h>
using namespace std;

pair<int, int> dfs(int src, vector<int>adj[], int visited[]){
    pair<int, int> odd_even= make_pair(0,0);
    pair<int, int> curr;
    visited[src]=1;
    for(int i=0;i<adj[src].size();i++){
        if(visited[adj[src][i]]==0){
            curr=dfs(adj[src][i], adj, visited);
            odd_even.first+=curr.second+1;
            odd_even.second+=curr.first;
        }
    }
   // cout<<src<<" "<<odd_even.first<<" "<<odd_even.second<<endl;
    return odd_even;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int v;
	    cin>>v;
	    vector<int> adj[v];
	    int visited[v];
	    visited[0]=0;
	    for(int i=0;i<v-1;i++){
            visited[i+1]=0;
            int x, y;
	        cin>>x>>y;
	        adj[x-1].push_back(y-1);
	        adj[y-1].push_back(x-1);
	    }
	    pair<int, int> dist = dfs(0, adj, visited);
	    cout<<dist.second<<endl;
	}
	return 0;
}
