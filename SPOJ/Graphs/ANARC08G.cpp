#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(true)
    {
        int n;
        cin>>n;
        if(n==0)
        break;

        int a[n][n];
        long int sum1=0,sum2=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
                sum1+=a[i][j];
            }
        }
        int tempSum=0;
        for(int i=0;i<n;i++)
        {
            tempSum=0;
            for(int j=0;j<n;j++)
            {
                tempSum+=a[i][j];
            }
            for(int j=0;j<n;j++)
            {
                tempSum-=a[j][i];
            }
            if(tempSum>0)
            sum2+=tempSum;
        }
        cout<<t<<". "<<sum1<<" "<<sum2<<endl;
        t++;
    }
    return 0;
}
