#include<bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        int n;
        cin>>n;
        if(n==0)
            break;
        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            b[i]=0;
        }

        stack<int> s;

        int exp=1, i=0,j=0;
        while(j<n && i<n){
            if(a[i]==exp){
                b[j]=a[i];
                i++;j++;exp++;
            }
            else if(!s.empty() && s.top()==exp){
                b[j]=s.top();
                s.pop();
                j++;exp++;
            }
            else{
                s.push(a[i]);
                i++;
            }
        }
        while(!s.empty()){
            //cout<<s.top()<<endl;
            b[j++]=s.top();
            s.pop();
        }
        bool correct=true;
        for(int i=0;i<n;i++)
        {
            if(b[i]!=i+1)
                correct=false;
        }
        if(correct){
            cout<<"yes";
        }
        else
        {
            cout<<"no";
        }
        cout<<endl;
    }
return 0;
}
