#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, dev;
        cin>>n>>dev;
        double a[n]={0};
        if(n==1 && dev!=0)
        {
            cout<<"-1"<<endl;
            continue;
        }
        if(n%2 == 0)
        {
            for(int i=0;i<n/2;i++)
            {
                cout<<-dev<<" ";
            }
            for(int i=0;i<n/2;i++)
            {
                cout<<dev<<" ";
            }
        }
        else
        {
            double a = dev*sqrt(double(n)/(n-1));
            for(int i=0;i<n/2;i++)
            {
                cout<<-a<<" ";
            }
            for(int i=0;i<n/2;i++)
            {
                cout<<a<<" ";
            }
            cout<<0;
        }
        cout<<endl;
    }
    return 0;
}
