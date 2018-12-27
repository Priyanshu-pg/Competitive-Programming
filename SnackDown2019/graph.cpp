#include<bits/stdc++.h>
using namespace std;

bool isConnectedGraph(int a[], int n)
{
    bool visited[n];
    queue<int> curr;
    bool flag = true;

    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }

    curr.push(a[0]);
    visited[0]=true;

    while(!curr.empty() && flag)
    {
        int x=curr.front();
        //cout<<x<<endl;
        curr.pop();
        //flag=false;
        for(int i=0;i<n;i++)
        {
           // cout<<a[i]<<" "<<__gcd(x,a[i])<<endl;
            if(!visited[i])
            {
                //flag=true;
                if(__gcd(x,a[i])==1)
                {
                    visited[i]=true;
                    curr.push(a[i]);
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        bool isConnected = isConnectedGraph(a,n);
        if(isConnected)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<1<<endl;
            bool flag=true;
            for(int i=0;i<n;i++)
            {
                if(a[i]!=47)
                {
                    flag=false;
                }
            }
            if(flag)
                a[0]=41;
            else
                a[0]=47;
        }
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
