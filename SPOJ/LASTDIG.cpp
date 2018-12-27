#include<iostream>
using namespace std;

int main()
{
    int t;
    int a;
    long int b;
    int n,mod,res,i;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        a%=10;
        if(b==0)
        {
            cout<<1<<endl;
            continue;
        }
        if(a==0 || a==1 ||a==6|| a==5)
        {
            cout<<a<<endl;
            continue;
        }
        if(a==2 || a==3 || a==7 || a==8)
            n=4;
        if(a==4 || a==9)
            n=2;
        mod=b%n;
        res=1;
        if(mod==0)
        {
            mod=n;
        }
        for(i=0;i<mod;i++)
        {
            res*=a;
            res%=10;
        }
        cout<<res<<endl;
    }
    return 0;
}
