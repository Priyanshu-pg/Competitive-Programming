#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll m=1000000007;
ll fac[100001];

ll calc(ll n)
{
    ll res=1;
    if(n%2==1)
    {
        res*=n;
        n--;
    }
    for(ll i=n-1;i>=1;i-=2)
    {
        res = (res%m * i%m)%m;
    }
    return res;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        map<ll,ll> freq;
        map<ll,ll>::reverse_iterator it;
        ll result=1;
        bool flag = false;
        ll si;

        cin>>n;
        for(ll i=0;i<n;i++)
        {
            cin>>si;
            freq[si]+=1;
        }

        for(it = freq.rbegin(); it!=freq.rend();it++)
        {
            ll currFreq=it->second;
          // calculate pairs when previous no is unpaired
            if(flag)
            {
                result= (result%m * currFreq%m)%m;
                currFreq--;
            }
            //calculate pairs when teams among same si is not formed
            if(currFreq > 1)
                result = (result%m * calc(currFreq)%m)%m;

            //flag indicates if there is one single si or not
            flag = false;
            if(currFreq%2==1)
            {
                flag = true;
            }
        }
        cout<<result<<endl;
    }
    return 0;
}
