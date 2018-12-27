#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        int max_g=INT_MIN, max_mg=INT_MIN, count_g=0, count_mg=0;
        cin>>n>>m;
        int g[n], mg[m];
        for(int i=0;i<n;i++){
            cin>>g[i];
            if(g[i] > max_g){
                max_g = g[i];
                count_g = 1;
            }
            else if(g[i] == max_g)
                count_g++;
        }

        for(int i=0;i<m;i++){
            cin>>mg[i];
            if(mg[i] > max_mg){
                max_mg = mg[i];
                count_mg = 1;
            }
            else if(mg[i] == max_mg)
                count_mg++;
        }

        if(max_g < max_mg){
            cout<<"MechaGodzilla"<<endl;
        }
        else if( max_g >= max_mg )
        {
            cout<<"Godzilla"<<endl;
        }
    }
    return 0;
}
