#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, result =0;
    cin>>n;
    int limit = (1 + floor(sqrt(1+4*n)))/2;
    for(int i=1;i<=limit;i++)
    {
        result+=(n/i)-(i-1);
    }
    cout<<result<<endl;
    return 0;
}
