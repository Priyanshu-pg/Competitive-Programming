#include<bits/stdc++.h>
using namespace std;

int main()
{
    bool flag = true;
    int x;
    while(flag)
    {
        cin>>x;
        if(x==42)
        {
            flag = false;
            break;
        }
        cout<<x<<endl;
    }
    return 0;
}
