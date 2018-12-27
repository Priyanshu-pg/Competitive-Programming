#include <bits/stdc++.h>
using namespace std;
int min(int a, int b)
{
    if(a<b)
    return a;
    return b;
}
int main() {
    int n;
    cin>>n;
    int count1=0, count2=0, count3=0, count4=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x == 1)
        {
            count1++;
        }
        else if(x == 2)
        {
            count2++;
        }
        else if(x == 3)
        {
            count3++;
        }
        else 
        {
            count4++;
        }
    }
    int ans=0;
    // put 4 people in a cab
    ans+=count4;
    
    // make four people of group one in a car
    ans += count1/4;
    count1%=4;

    // make two groups of group2 in a cab
    ans += count2/2;
    count2%=2;
    
    // pair group3 with group1
    int pool = min(count1, count3);
    ans+=pool;
    count1-=pool;
    count3-=pool;
    ans+=count3;
    
    ans += (count1 + count2*2)/4 + (count1 + count2*2)%4;
    cout<<ans<<endl;
	return 0;
}
