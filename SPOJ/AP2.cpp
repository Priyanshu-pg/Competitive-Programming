#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll x,y,s,a,n,d;
        cin>>x>>y>>s;

        n = (2*s)/(x+y);
        d = (y-x)/(n-5);
        a = (x-2*d);

        cout<<n<<endl;
        for(int i=1;i<=n;i++){
            cout<<a+(i-1)*d<<" ";
        }
        cout<<endl;
    }
    return 0;
}
