#include<bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n, int m){
    if(i>=0 && i<n && j>=0 && j<m)
    return true;
    return false;
}


int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n, m;
	    cin>>n>>m;
	    char graph[n][m];
	    int visited[n][m];
	    for(int i=0;i<n;i++){
	        string s;
	        cin>>s;
	        for(int j=0;j<m;j++){
	            graph[i][j]=s[j];
	            visited[i][j]=0;
	        }
	    }

	    int count = 1;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(graph[i][j]=='X' && visited[i][j]==0)
	            {
	                visited[i][j]=count;
	                queue<pair<int, int>> q;
	                q.push(make_pair(i,j));

	                while(!q.empty())
	                {
	                    if(isValid(i+1, j, n,m) && graph[i+1][j]=='X' && visited[i+1][j]==0)
	                    {
	                        visited[i+1][j]=count;
	                        q.push(make_pair(i+1, j));
	                    }
	                    if(isValid(i-1, j, n,m) && graph[i-1][j]=='X' && visited[i-1][j]==0)
	                    {
	                        visited[i-1][j]=count;
	                        q.push(make_pair(i-1, j));
	                    }
	                    if(isValid(i, j+1, n,m) && graph[i][j+1]=='X' && visited[i][j+1]==0)
	                    {
	                        visited[i][j+1]=count;
	                        q.push(make_pair(i, j+1));
	                    }
	                    if(isValid(i, j-1, n,m) && graph[i][j-1]=='X' && visited[i][j-1]==0)
	                    {
	                        visited[i][j-1]=count;
	                        q.push(make_pair(i, j-1));
	                    }
	                }
	            }
	        }
	    }

	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            cout<<visited[i][j]<<" ";
	        }
	        cout<<endl;
	    }
	    cout<<count<<endl;
	}
	return 0;
}
