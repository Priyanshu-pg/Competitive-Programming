#include<bits/stdc++.h>
using namespace std;

int main()
{
    while(true)
    {
        double len;
        cin>>len;
        if(len == 0.00)
            break;
        double sum = 0.0;
        double i=1;
        for(i=1;;i++)
        {
            sum += (double)1/(i+1);
            if(sum>=len)
                break;
        }
        cout<<i<<" card(s)"<<endl;
    }
    return 0;
}
