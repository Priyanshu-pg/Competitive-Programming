#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        int dp[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>dp[i][j];
            }
        }
        int maxint=INT_MIN;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j==0)
                    dp[i][j]+=max(dp[i-1][j], dp[i-1][j+1]);
                else if(j==m-1)
                    dp[i][j]+=max(dp[i-1][j], dp[i-1][j-1]);
                else
                    dp[i][j]+=max(dp[i-1][j], max(dp[i-1][j-1],dp[i-1][j+1]));
                if(i==n-1 && dp[i][j]>maxint)
                    maxint=dp[i][j];
            }
        }
        cout<<maxint<<endl;
    }
    return 0;
}
