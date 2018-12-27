#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    set<long long int> s;
    bool flag = true;
    while(n>1)
    {
        if(n%2==0)
            n/=2;
        else
        {
            n=3*(n+1);
        }
        if(s.find(n)== s.end())
        {
            s.insert(n);
        }
        else
        {
            flag=false;
            break;
        }
    }

    if(flag){
        cout<<"TAK"<<endl;
    }
    else
        cout<<"NIE"<<endl;
    return 0;
}
