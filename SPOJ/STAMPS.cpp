#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int k=1;k<=t;k++){
        int sum, n;
        cin>>sum>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a, a+n);

        int count=0, coll=0;
        for(int i=n-1;i>=0;i--){
            coll+=a[i];
            count++;
            if(coll>=sum){
                break;
            }
        }
        cout<<"Scenario #"<<k<<":"<<endl;
        if(coll<sum)
            cout<<"impossible"<<endl;
        else
            cout<<count<<endl;
    }
return 0;
}
