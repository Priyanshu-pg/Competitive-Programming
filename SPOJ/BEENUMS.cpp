#include<bits/stdc++.h>
using namespace std;

int main()
{
    while(true)
    {
        long long int n;
        cin>>n;
        if(n==-1)
        break;

        double x = (3+ sqrt(12*n-3))/6;
        if(ceil(x)!=x)
        {
            cout<<"N"<<endl;
        }
        else if(3*x*(x-1)+1 == n)
        cout<<"Y"<<endl;
    }
    return 0;
}
