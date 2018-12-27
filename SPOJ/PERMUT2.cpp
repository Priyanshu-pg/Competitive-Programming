#include<bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        int n;
        cin>>n;
        if(n==0)
            break;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];

        bool isAmbiguous = true;
        for(int i=0;i<n;i++){
            if(a[a[i]-1] != i+1)
                isAmbiguous = false;
        }
        if(isAmbiguous)
            cout<<"ambiguous"<<endl;
        else
            cout<<"not ambiguous"<<endl;
    }
return 0;
}
