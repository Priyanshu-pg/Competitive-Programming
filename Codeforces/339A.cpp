#include <iostream>
using namespace std;

int main() {
    string s;
    cin>>s;
    int count1=0, count2=0, count3=0, count =0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
            count1++;
        else if(s[i]=='2')
            count2++;
        else if(s[i] == '3')
            count3++;
        else
            count++;
    }
    for(int i=0;i<count1;i++)
    {
        cout<<1;
        if(count>0)
        cout<<'+';
        count--;
    }
    for(int i=0;i<count2;i++)
    {
        cout<<2;
        if(count>0)
        cout<<'+';
        count--;
    }
    for(int i=0;i<count3;i++)
    {
        cout<<3;
        if(count>0)
        cout<<'+';
        count--;
    }
    cout<<endl;
	return 0;
}