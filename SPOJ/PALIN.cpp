#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string n;
        cin>>n;
        vector<int> a;
        bool isAll9=true;
        for(int i=0;i<n.size();i++)
        {
            a.push_back(n[i]-'0');
            if(a[i]!=9)
                isAll9=false;
        }
        ll len = a.size();
        if(isAll9)
        {
            cout<<1;
            for(int i=0;i<len-1;i++)
                cout<<0;
            cout<<1<<endl;
            continue;
        }

        int i=(len-1)/2;
        int j=(len%2)?i:i+1;
        while(i>=0 && a[i]==a[j])
        {
            i--;
            j++;
        }
        bool leftSmaller=false;
        if(i<0 || a[i]<a[j])
            leftSmaller=true;

        while(i>=0)
        {
            a[j]=a[i];
            i--;
            j++;
        }

        if(leftSmaller)
        {
            int carry=1;
            int mid=(len)/2;
            i=mid-1;
            if(len%2==1)
            {
                a[mid]+=carry;
                carry=a[mid]/10;
                a[mid]%=10;
                j=mid+1;
            }
            else
            {
                j=mid;
            }

            while(i>=0)
            {
                a[i]+=carry;
                carry=a[i]/10;
                a[i]%=10;
                a[j]=a[i];
                i--;
                j++;
            }
        }
        for(ll i=0;i<a.size();i++)
        {
            cout<<a[i];
        }
        cout<<endl;
    }
}
