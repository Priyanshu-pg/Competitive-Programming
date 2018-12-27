#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long

void solve( ){
    	ll t;cin>>t;
        while(t--){
            ll n,k;cin>>n>>k;
            ll i;
            ll arr[n];
            ll S=0;
            for(i=0;i<n;i++){
                cin>>arr[i];
            }

            sort(arr,arr+n);

            ll idx = -1;
            ll sum = 0;
            ll brr[n];
            ll p=0;
            bool flag = true;
            for(i=0;i<n;i++){

                if(arr[i]<=k){
                    sum += arr[i];
                }
                else{
                    flag = false;
                    brr[p++] = arr[i]-k;
                }
            }
            if(flag){
                cout<<sum<<"\n";
            }
            else{
                if(p==1){
                    cout<<sum+brr[p-1]+k<<"\n";
                }
                else if (p==2){
                    if(brr[p-1]>=brr[p-2]){

                        brr[p-1]-=brr[p-2];
                        brr[i-2] = 0;
                    }
                    cout<<sum+2*k+brr[p-1]<<"\n";
                }
                else{
                    bool is_one = false;
                    while(!is_one){
                        for(i=p-2;i>0;i--){
                            if(brr[i]>=brr[i-1]){

                                brr[i]-=brr[i-1];
                                brr[i-1] = 0;
                                i--;
                            }
                        }
                        ll ct= 0;
                        for(i=0;i<p-1;i++){
                            if(brr[i]>0){
                                ct++;
                            }
                        }
                        if(ct<=1){
                            is_one = true;
                        }
                        sort(brr,brr+p-1);
                    }
                    if(brr[p-1]>=brr[p-2]){

                        brr[p-1]-=brr[p-2];
                        brr[i-2] = 0;
                    }
                    cout<<sum + brr[p-1] + (p)*k<<"\n";

                }




            }

        }
    }
int main(){

solve();
    return 0;
}
