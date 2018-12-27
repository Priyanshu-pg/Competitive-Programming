#include<bits/stdc++.h>
using namespace std;

int main()
{
    while(true)
    {
        int n,m;
        cin>>n>>m;
        if(n == -1 && m==-1)
            break;
        int g = min(n,m);
        int b = max(n,m);

        double result = ceil((double)b/(g+1));
        cout<<result<<endl;

    }

    return 0;
}
