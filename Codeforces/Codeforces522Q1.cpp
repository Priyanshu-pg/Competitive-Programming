#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll s,a,b,c;
        cin>>s>>a>>b>>c;
        ll totalChoc, boughtChoc, freeChoc;
        boughtChoc = s/c;
        freeChoc = (boughtChoc /a)*b;
        //freeChoc = boughtChoc *b/a;
        totalChoc = freeChoc + boughtChoc;
        cout<<totalChoc<<endl;
    }

    return 0;
}
