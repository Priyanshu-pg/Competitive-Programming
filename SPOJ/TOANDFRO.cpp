#include<bits/stdc++.h>
using namespace std;

int main()
{
    while(true)
    {
        int m;
        cin>>m;
        if(m==0)
        {
            break;
        }
        string s;
        cin>>s;
        int n=s.size()/m;
        char a[n][m];
        int p=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                for(int j=0;j<m;j++)
                {
                    a[i][j]=s[p++];
                }
            }
            else
            {
                for(int j=m-1;j>=0;j--)
                {
                    a[i][j]=s[p++];
                }
            }
        }

        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                cout<<a[i][j];
            }
        }
        cout<<endl;
    }
}
