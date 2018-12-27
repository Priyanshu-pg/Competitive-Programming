#include<bits/stdc++.h>
using namespace std;

bool isCycle(int v, vector<vector<int>> &graph, int (&visited)[10000], int parent){
    visited[v]=true;
  //  cout<<"v "<<v<<" parent "<<parent<<endl;
    for(int i=0;i<graph[v].size();i++){
      //  cout<<"child "<<graph[v][i]<<endl;
        if(!visited[graph[v][i]]){
            if(isCycle(graph[v][i], graph, visited, v)){
            //    cout<<"not vis "<<v<<endl;
                return true;
            };
        }
        else if(graph[v][i] != parent)
        {
         //   cout<<"not par "<<parent<<endl;
            return true;
        }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n);
    int visited[10000];
    for(int i=0;i<n;i++)
        visited[i]=false;

    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    /*for(int j=0;j<n;j++){
            for(int i=0;i<graph[j].size();i++)
                cout<<graph[i][j]<<" ";
        cout<<endl;
    }*/
    bool isTree=true;
    if(isCycle(0, graph, visited, -1)){
      //  cout<<"NO"<<endl;
        isTree=false;
    }
    for(int i=0;i<n;i++){
        if(visited[i]==false)
        {
            isTree=false;
            //cout<<"NO"<<endl;
            break;
        }
    }
    if(isTree)
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
return 0;
}
