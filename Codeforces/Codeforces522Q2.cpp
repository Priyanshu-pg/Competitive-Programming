#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n, m;
    cin>>n>>m;
    ll min, max;
    min = n-2*m;
    if(min<0)
        min =0;
    double d = ceil(( 1+sqrt(1 + 8*m) )/2) ;
    if(m == 0)
        max = n;
    else
        max = n - (ll)d;
    cout<<min<<" "<<max<<endl;
}
