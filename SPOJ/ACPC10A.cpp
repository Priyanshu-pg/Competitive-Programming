#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    while(true)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        if(x==0 && y==0 && z==0)
        {
            break;
        }
        if(y-x == z-y)
        {
            cout<<"AP "<<z + (z-y)<<endl;
        }
        else if((double)y/x == (double)z/y)
        {
            cout<<"GP "<<z*((double)z/y)<<endl;
        }
    }
    return 0;
}
