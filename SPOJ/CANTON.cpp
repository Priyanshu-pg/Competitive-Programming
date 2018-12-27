#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int diagnol = (int)ceil((-1 + sqrt(1+8*n))/2);
        int no = (int)(diagnol*(diagnol+1))/2;
        int diff = no - n;
        //cout<<diagnol<<" "<<no<<" "<<diff<<endl;
        int row, col, dir;
        if(diagnol%2==0){
            row=diagnol-1-diff+1;
            col=diff+1;
        }
        else{
            row=diff+1;
            col=diagnol-1-diff+1;
        }
        cout<<"TERM "<<n<<" IS "<<row<<"/"<<col<<endl;
    }
return 0;
}

