#include <bits/stdc++.h>
    using namespace std;
     
    #define ll long long
    #define ull unsigned long long
    #define PI 3.14159265358979323846
    #define r2 1.41421356237309504880
    #define rep(i,n) for(ll i=0;i<n;i++)
    #define REP(i,k,n) for(ll i=k;i<n;i++)
    #define REPR(i,k,n) for(ll i=k;i>n;i--)
    #define fastIO std::ios::sync_with_stdio(0)
    #define fileI freopen("input.txt","r",stdin)
    #define fileO freopen("output.txt","w",stdout)
    #define mod 1000000007
    #define max3(a,b,c) max(a,max(b,c))
    #define _USE_MATH_DEFINES
    #define ms(a) memset(a,0,sizeof(a))

    void solve()
    {
        while(true)
        {
            int a, d;
            cin>>a>>d;
            if(a==0 && d==0)
                break;
            ll attack[a], defend[d];
            ll attacker=INT_MAX, lastDef=INT_MAX, secondLastDEf=INT_MAX;
            for(int i=0;i<a;i++)
            {
                cin>>attack[i];
                if(attacker > attack[i])
                {
                    attacker=attack[i];
                }
            }
           // cout<<attacker<<endl;
            for(int i=0;i<d;i++)
            {
                cin>>defend[i];
                if(defend[i] < lastDef)
                {
                    secondLastDEf=lastDef;
                    lastDef=defend[i];
                }
                else if(defend[i] < secondLastDEf)
                {
                    secondLastDEf=defend[i];
                }
            }
            //cout<<lastDef<<" "<<secondLastDEf<<endl;
            if(attacker < secondLastDEf)
            {
                cout<<"Y"<<endl;
            }
            else
            {
                cout<<"N"<<endl;
            }
        }
    }

    int main()
    {
        fileI;
        fileO;
        fastIO;
        solve();
        return 0;
    }
