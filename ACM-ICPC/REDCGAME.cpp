#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long

int calcDelta(vector<int> a)
{
    int n = a.size();
    bool flag = true;
    int i=n-1;
    int last = 0;
    while(flag)
    {
        flag=false;
        for(i=n-1;i>last;i-=2)
        {
            if(a[i]!=0)
            {
                a[i]=a[i]-a[i-1];
                a[i-1]=0;
               // flag = true;
            }
        }
        sort(a.begin()+last,a.end());
        /*
        .for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;*/
        for(int i=0;i<n;i++)
        {
            if(a[i]>0)
            {
                flag=true;
                last =i;
                break;
            }
        }
        if(last == n-1)
        {
            return a[n-1];
        }
    }
    return 0;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;cin>>n>>k;
            ll i,arr[n];

            for(i=0;i<n;i++){
                cin>>arr[i];
            }

            sort(arr,arr+n);

            ll idx = -1;
            for(i=0;i<n;i++){
                if(arr[i]<=k){
                    idx = i;
                }
                else{
                    break;
                }
            }
            idx++;
            ll sum= 0;

            for(i=0;i<idx;i++)
                sum += arr[i];
         //  cout<<sum<<"\n";
            if(idx!=-1){
                vector<int> b ;
                for(int i=idx;i<n-1;i++)
                {
                    b.push_back(arr[i]-k);
                }
                int delta = calcDelta(b);
               // cout<<delta<<endl;
                sum+=(n-idx-1)*k + arr[n-1] - delta;
            }

        cout<<sum<<"\n";
    }

    return 0;
    }
