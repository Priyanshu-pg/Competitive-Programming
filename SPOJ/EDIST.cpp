#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string a, b;
        cin>>a>>b;
        int n = a.size(), m = b.size();
        int dp[n+1][m+1];

        for(int i=0;i<=m;i++)
        {
            dp[0][i]=i;
        }
        for(int j=0;j<=n;j++)
        {
            dp[j][0]=j;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
            }
        }
        cout<<dp[n][m]<<endl;
    }
}

