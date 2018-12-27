#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        double n, k;
        cin>>n>>k;
        double exp=0.0;
        exp = n*1.0 - (double)(n-1)/k;
        exp*=2.0;
        cout<<fixed<<exp<<endl;
    }
    return 0;
}
