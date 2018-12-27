#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if(y == x)
        {
            if(x%2==0)
            {
                cout<<x*2<<endl;
            }
            else
            {
                cout<<1+(x-1)*2<<endl;
            }
        }
        else if(y == x-2)
        {
            if(x%2==0)
            {
                cout<<2+(x-2)*2<<endl;
            }
            else
            {
                cout<<3+(x-3)*2<<endl;
            }
        }
        else
        {
            cout<<"No Number"<<endl;
        }
    }
    return 0;
}
